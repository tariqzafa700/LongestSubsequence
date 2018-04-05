#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMax(int a, int b) {
  return a > b?a:b;
}
int findLCS(const string& first, const string& second) {
  vector<vector<int> > memoize(100, vector<int>(100));
  memoize[0][0] = 0;
  for(int i=0;i<=first.size(); ++i) {
    for(int j=0;j<=second.size(); ++j) {
      if(j == 0 || i == 0) {
        memoize[i][j] = 0;
        continue;
      }
      if(first[i] == second[j]) {
        memoize[i][j] = memoize[i-1][j-1] + 1;
      } else {
        memoize[i][j] = getMax(memoize[i-1][j], memoize[i][j-1]);
      }
    }
  }
    for(int i=0;i<=first.size(); ++i) {
        for(int j=0;j<=second.size(); ++j) {
            cout << memoize[i][j] << " ";
        }
        cout << endl;
    }
    return memoize[first.size()][second.size()];
}
int main() {
  string first = "AGGTAB";
  string second = "GXTXAYB";

  cout << findLCS(first, second);
}

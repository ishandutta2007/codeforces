#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;
char ans[N][N];

string str;
int n, l, k;

int main() {
  cin >> n >> l >> k;
  cin >> str;

  sort(str.begin(), str.end());

  int t = 0;
  int idx = 1;
  for (int j = 0; j < l; ++j) {
    for (int i = idx; i <= k; ++i) {
      ans[i][j] = str[t++];
    }
    while (ans[idx][j] != ans[k][j]) ++idx;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < l; ++j) {
      if (!ans[i][j]) ans[i][j] = str[t++];
    }
    cout << ans[i] << "\n";
  }

  return 0;
}
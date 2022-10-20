#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, k;
vector <int> a[N];
int res = 0, pos;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int u;
      cin >> u;
      a[i].push_back(u);
      if (u == 1) {
        pos = i;
      }
    }
  }
  a[pos].push_back(n + 2);
  int pos2 = 1;
  for (int i = 1; i <= k; i++) {
    if (i != pos) {
      res += (a[i].size() - 1);
    } else {
      for (int j = 1; j < a[i].size(); j++) {
        if (a[i][j] != a[i][j - 1] + 1) {
          pos2 = a[i][j - 1];
          res += a[i].size() - j - 1;
          break;
        }
      }
    }
  }
  res += (n - pos2);
  cout << res;
  return 0;
}
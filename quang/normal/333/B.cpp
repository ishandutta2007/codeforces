#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int delcol[N], delrow[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    delrow[x] = 1;
    delcol[y] = 1;
  }
  int res = 0;
  for (int i = 2; i <= n / 2; i++) {
    int cnt = 4 - delrow[i] - delrow[n - i + 1] - delcol[i] - delcol[n - i + 1];
    res += cnt;
  }
  if (n % 2 == 1) {
    int x = n / 2 + 1;
    int cnt = 2 - delrow[x] - delcol[x];
    if (cnt) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
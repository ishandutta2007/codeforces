#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 900;

int m, t, r;
int dd[N], sl[N], a[N];

void Fill(int vt) {
  for (int i = vt; i <= vt + t - 1; i++) sl[i]++;
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> m >> t >> r;
  if (t < r) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= m; i++) cin >> a[i];
  int res = 0;
  for (int i = 1; i <= m; i++) {
    if (sl[a[i] + 300] >= r) continue;
    int cl = r - sl[a[i] + 300];
    for (int j = a[i] + 300; j && cl; j--)
    if (!dd[j]) {
      dd[j] = 1;
      Fill(j);
      cl--;
      res++;
    }
  }
  cout << res;
  return 0;
}
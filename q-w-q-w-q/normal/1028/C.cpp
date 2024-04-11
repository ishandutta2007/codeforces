#include <cstdio>
#include <iostream>

using namespace std;

const int N = 150005, inf = 1 << 30;
int n;
int a[N], b[N], c[N], d[N];
int pl[N], pr[N], pu[N], pd[N];
int sl[N], sr[N], su[N], sd[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];

  pl[0] = -inf, pr[0] = inf, pu[0] = inf, pd[0] = -inf;
  sl[n + 1] = -inf, sr[n + 1] = inf, su[n + 1] = inf, sd[n + 1] = -inf;

  for (int i = 1; i <= n; i++) {
    pl[i] = max(pl[i - 1], a[i]);
    pr[i] = min(pr[i - 1], c[i]);
    pd[i] = max(pd[i - 1], b[i]);
    pu[i] = min(pu[i - 1], d[i]);
  }

  for (int i = n; i; i--) {
    sl[i] = max(sl[i + 1], a[i]);
    sr[i] = min(sr[i + 1], c[i]);
    sd[i] = max(sd[i + 1], b[i]);
    su[i] = min(su[i + 1], d[i]);
  }

  for (int i = 1; i <= n; i++) {
    int l = max(pl[i - 1], sl[i + 1]);
    int r = min(pr[i - 1], sr[i + 1]);
    int d = max(pd[i - 1], sd[i + 1]);
    int u = min(pu[i - 1], su[i + 1]);
    if (l <= r && d <= u) {
      cout << l << ' ' << d;
      return 0;
    }
  }
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

int n, q;
bool vis[maxn];

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    vector<int> a(n);
    for (auto &x : a) scanf("%d", &x);
    sort(all(a));
    uni(a);
    for (auto x : a) vis[x] = true;
    int mmax = a.back(), ans = mmax, ans2 = 0;
    if (mmax % 2 == 0 && vis[mmax / 2] && mmax % 3 == 0 && vis[mmax / 3] && mmax % 5 == 0 && vis[mmax / 5]) {
      int u = mmax / 2, v = mmax / 3, w = mmax / 5;
      if (u % w) ans2 = u + v + w;
    }
    int se = mmax, cnt = 1;
    ROF(i, int(a.size()) - 2, 0) {
      if (mmax % a[i] == 0 || se % a[i] == 0) continue;
      if (se == mmax) se = a[i];
      ans += a[i];
      if (++cnt == 3) break;
    }
    printf("%d\n", max(ans, ans2));
    for (auto x : a) vis[x] = false;
  }
}
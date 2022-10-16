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

const int maxn = 312345;

int n, q, k;
int a[maxn], b[maxn], f[maxn][20];
ll ans[maxn][20];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q >> k;
  FOR(i, 1, n) cin >> a[i];
  deque<int> Q;
  ROF(i, n, 1) {
    while (!Q.empty() && a[i] <= a[Q.back()]) Q.pop_back();
    Q.eb(i);
    while (i + k < Q.front()) Q.pop_front();
    b[i] = a[Q.front()];
  }
  f[n + 1][0] = n + 1;
  ROF(i, n, 1) {
    f[i][0] = min(i + k, n + 1);
    while (b[i] < b[f[i][0]]) f[i][0] = f[f[i][0]][0];
    ans[i][0] = ll(f[i][0] - i + k - 1) / k * b[i];
  }
  FOR(j, 1, 19) FOR(i, 1, n + 1) {
    f[i][j] = f[f[i][j - 1]][j - 1];
    ans[i][j] = ans[i][j - 1] + ans[f[i][j - 1]][j - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    ll cost = a[l];
    ROF(j, 19, 0) if (f[l][j] <= r) {
      cost += ans[l][j];
      l = f[l][j];
    }
    cout << cost + ll(r - l) / k * b[l] << '\n';
  }
}
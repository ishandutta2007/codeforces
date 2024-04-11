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

const int maxn = 1123;

int pw[15], a[maxn][15];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  pw[0] = 1;
  int ans = 0;
  while (pw[ans] < n) {
    pw[ans + 1] = pw[ans] * k;
    ans++;
  }
  cout << ans << '\n';
  REP(i, n) REP(j, ans) a[i][j] = (i / pw[j]) % k;
  REP(i, n) FOR(j, i + 1, n - 1) ROF(c, ans - 1, 0) if (a[i][c] != a[j][c]) {
    cout << c + 1 << ' ';
    break;
  }
}
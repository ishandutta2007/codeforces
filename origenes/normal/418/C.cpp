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

const int maxn = 112;

int n, m;
int a[maxn], b[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  a[1] = b[1] = 1;
  FOR(i, 2, n - 1) a[i] = 2;
  FOR(j, 2, m - 1) b[j] = 2;
  if (n > 1) a[n] = 2 * (n - 1) - 2;
  if (m > 1) b[m] = 2 * (m - 1) - 2;
  if (n == 2) a[1] = 3, a[2] = 4;
  if (m == 2) b[1] = 3, b[2] = 4;
  FOR(i, 1, n) {
    FOR(j, 1, m) cout << a[i] * b[j] << ' ';
    cout << '\n';
  }
}
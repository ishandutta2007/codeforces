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

int n, k;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  if (n == 1) {
    if (!k) cout << 1;
    else cout << -1;
    return 0;
  }
  if (n / 2 > k) {
    cout << -1;
    return 0;
  }
  int f = k - n / 2 + 1;
  cout << f << ' ' << f * 2 << ' ';
  int need = n / 2 - 1;
  for (int i = 1; ; i += 2) {
    if (need == 0) break;
    if (i == f || i == f * 2 || i + 1 == f || i + 1 == f * 2) continue;
    need--;
    cout << i << ' ' << i + 1 << ' ';
  }
  if (n & 1) cout << int(1e9);
}
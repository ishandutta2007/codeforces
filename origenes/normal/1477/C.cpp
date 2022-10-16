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

const int maxn = 5123;

int n;
ll x[maxn], y[maxn];
int id[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> x[i] >> y[i];
  iota(id + 1, id + n + 1, 1);
  FOR(i, 3, n) ROF(j, i, 3) {
    if ((x[id[j - 1]] - x[id[j]]) * (x[id[j - 1]] - x[id[j - 2]]) + (y[id[j - 1]] - y[id[j]]) * (y[id[j - 1]] - y[id[j - 2]]) > 0) break;
    swap(id[j], id[j - 1]);
  }
  FOR(i, 1, n) cout << id[i] << ' ';
}
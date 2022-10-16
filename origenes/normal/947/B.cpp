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

const int maxn = 112345;

int n;
int V[maxn], T[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> V[i];
  FOR(i, 1, n) cin >> T[i];
  multiset<ll> q;
  ll s = 0;
  FOR(i, 1, n) {
    q.emplace(s + V[i]);
    ll ans = 0;
    while (!q.empty() && *q.begin() <= s + T[i]) {
      ans += *q.begin() - s;
      q.erase(q.begin());
    }
    ans += ll(T[i]) * q.size();
    cout << ans << ' ';
    s += T[i];
  }
}
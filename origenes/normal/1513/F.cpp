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

int n;
int a[maxn], b[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  ll s = 0;
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  vector<pii> u, v;
  FOR(i, 1, n) {
    s += abs(a[i] - b[i]);
    if (a[i] > b[i]) u.eb(b[i], a[i]);
    else if (a[i] < b[i]) v.eb(a[i], b[i]);
  }
  sort(all(u)); sort(all(v));
  ll ans = 0;
  priority_queue<int> tails;
  int i = 0;
  for (auto [l, r] : v) {
    while (i < u.size() && u[i]._1 <= l) {
      tails.emplace(u[i]._2);
      i++;
    }
    if (!tails.empty()) {
      auto x = tails.top();
      chkmax(ans, ll(min(x, r)) - l);
    }
  }
  while (!tails.empty()) tails.pop();
  i = 0;
  for (auto [l, r] : u) {
    while (i < v.size() && v[i]._1 <= l) {
      tails.emplace(v[i]._2);
      i++;
    }
    if (!tails.empty()) {
      auto x = tails.top();
      chkmax(ans, ll(min(x, r)) - l);
    }
  }
  cout << s - 2 * ans;
}
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

mt19937 rng;
bool composite[maxn];
map<pii, ll> tab;

ll ask(int i, int j) {
  if (i > j) swap(i, j);
  if (tab.count(mp(i, j))) return tab[mp(i, j)];
  cout << "? " << i << ' ' << j << endl;
  ll res;
  cin >> res;
  return tab[mp(i, j)] = res;
}

void solve() {
  int n; cin >> n;
  tab.clear();
  if (n <= 86) {
    vector<int> ans(n + 1);
    int mn = 2e5;
    FOR(i, 1, n) {
      ll d = 0;
      FOR(j, 1, n) if (j != i) d = gcd(d, ask(i, j));
      ans[i] = d;
      chkmin(mn, ans[i]);
    }
    // n=3 case
    FOR(i, 1, n) if (ans[i] > mn + n - 1) ans[i] /= 2;
    cout << '!';
    FOR(i, 1, n) cout << ' ' << ans[i];
    cout << endl;
    return;
  }
  uniform_int_distribution<> pick(1, n);
  set<int> checked;
  vector<int> ans(n + 1);
  int x;
  while (true) {
    do {
      x = pick(rng);
    } while (checked.count(x));
    checked.emplace(x);
    set<int> s;
    ll d = 0;
    REP(_, 8) {
      int y;
      do {
        y = pick(rng);
      } while (y == x || s.count(y));
      s.emplace(y);
      d = gcd(d, ask(x, y));
    }
    if (!composite[d] && (d == 1 || d >= 83)) {
      ans[x] = d;
      break;
    }
  }
  FOR(i, 1, n) if (i != x) ans[i] = ask(i, x) / ans[x];
  if (ans[x] != 1) {
    int y;
    FOR(i, 1, n) if (i != x && ll(ans[i]) * ans[x] > ans[x] + n - 1) {
      y = i;
      break;
    }
    FOR(i, 1, n) if (i != x && ll(ans[i]) * ans[x] <= ans[x] + n - 1) {
      ll c = ask(i, y);
      if (c % ans[x] == 0) ans[i] *= ans[x];
    }
  }
  cout << '!';
  FOR(i, 1, n) cout << ' ' << ans[i];
  cout << endl;
}

int main() {
  int T; cin >> T;
  rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  FOR(i, 2, 2e5) if (!composite[i]) {
    for (int j = i + i; j <= 2e5; j += i) composite[j] = true;
  }
  while (T--) solve();
}
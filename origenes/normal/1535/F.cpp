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

int sz;
string x[maxn];
vector<int> y[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  map<string, vector<string>> anagrams;
  REP(i, n) {
    string s; cin >> s;
    sz = size(s);
    auto t = s;
    sort(all(t));
    anagrams[t].eb(s);
  }
  ll ans = n * ll(n - 1) / 2 * 1337;
  for (auto [_, cur] : anagrams) {
    ll tot = size(cur);
    ans -= tot * (tot - 1) / 2 * 1335;
    REP(i, tot) x[i] = cur[i];
    REP(i, tot) {
      y[i].resize(sz);
      y[i][sz - 1] = sz;
      ROF(j, sz - 2, 0) {
        if (x[i][j] <= x[i][j + 1]) y[i][j] = y[i][j + 1];
        else y[i][j] = j + 1;
      }
    }
    REP(i, tot) REP(j, i) {
      int h = 0, t = sz - 1;
      while (x[i][h] == x[j][h]) h++;
      while (x[i][t] == x[j][t]) t--;
      ans -= (y[i][h] > t || y[j][h] > t);
    }
  }
  cout << ans;
}
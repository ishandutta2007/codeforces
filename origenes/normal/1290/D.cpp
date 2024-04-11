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

int LIMIT;

bool ask(int x) {
  if (LIMIT == 0) assert(0);
  cout << "? " << x << endl;
  string ret;
  cin >> ret;
  return ret[0] == 'N';
}

const int maxn = 51234;

int n, k;
bool good[maxn];
vector<int> a[maxn], b[maxn], c[maxn];

int main() {
  cin >> n >> k;
  LIMIT = 3 * sqr(n) / (2 * k);
  if (k == 1) {
    int ans = 0;
    FOR(i, 1, n) {
      bool fi = true;
      FOR(j, 1, i - 1) {
        ask(j); fi &= ask(i);
        cout << 'R' << endl;
      }
      ans += fi;
    }
    cout << "! " << ans << endl;
    return 0;
  }
  fill(good + 1, good + n + 1, true);
  int blks = n / (k / 2);
  FOR(i, 1, blks) {
    int st = (i - 1) * (k / 2);
    FOR(j, 1, k / 2) a[i].eb(st + j);
  }
  int clk = 0;
  FOR(i, 1, blks) FOR(j, 1, i - 1) {
    if (b[j].empty()) {
      clk++;
      c[clk].eb(j); c[clk].eb(i);
      b[i].eb(clk);
    } else {
      int pre = b[j].back(); b[j].pop_back();
      c[pre].eb(i);
      b[i].eb(pre);
    }
  }
  FOR(i, 1, clk) {
    for (auto v : c[i]) for (auto u : a[v]) good[u] &= ask(u);
    cout << 'R' << endl;
  }
  int ans = 0;
  FOR(i, 1, n) ans += good[i];
  cout << "! " << ans << endl;
}
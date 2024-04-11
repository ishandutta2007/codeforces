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
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int n;
string s[maxn];
vector<int> f[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  FOR(i, 1, n) cin >> s[i];
  f[1] = vector<int>(s[1].length() + 1, 1);
  FOR(i, 2, n) {
    f[i].resize(s[i].length() + 1);
    auto calc = [&](string now) {
      int ans = 0;
      vector<char> vis(s[i - 1].length() + 1);
      vis.back() = 1;
      ROF(j, int(s[i - 1].length()) - 1, 1)
        vis[j] = j - 1 >= now.length() ? 0 : (s[i - 1][j] == now[j - 1] ? vis[j + 1] : s[i - 1][j] < now[j - 1]);
      bool large = false;
      REP(j, int(s[i - 1].length())) {
        if (large) ans = add(ans, f[i - 1][j]);
        else {
          if (vis[j + 1]) ans = add(ans, f[i - 1][j]);
          if (s[i - 1][j] > now[j]) break;
          if (s[i - 1][j] < now[j]) large = true;
        }
      }
      if (s[i - 1] <= now) ans = add(ans, f[i - 1].back());
      return ans;
    };
    REP(j, int(s[i].length())) f[i][j] = calc(s[i].substr(0, j) + s[i].substr(j + 1));
    f[i][s[i].length()] = calc(s[i]);
  }
  int ans = 0;
  for (auto x : f[n]) ans = add(ans, x);
  cout << ans;
}
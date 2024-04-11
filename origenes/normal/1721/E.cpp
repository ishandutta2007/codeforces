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

const int maxn = 1123456;

string s, t;
int f[maxn][26], sz[maxn];

int calc(int i) {
  reset(f[i], 0);
  int ch = s[i] - 'a';
  REP(j, 26) f[i][j] = i && j != ch ? f[sz[i - 1]][j] : i + (j == ch);
  return sz[i] = i ? f[sz[i - 1]][ch] : 0;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> s;
  int ns = size(s);
  REP(i, ns) calc(i);
  int q; cin >> q;
  while (q--) {
    cin >> t;
    int nt = size(t);
    s += t;
    FOR(i, ns, ns + nt - 1) cout << calc(i) << ' ';
    cout << '\n';
    while (nt--) s.pop_back();
  }
}
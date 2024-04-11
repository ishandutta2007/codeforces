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

const int maxn = 512345;

int n;
int f[maxn], a[maxn], fi[maxn], la[maxn], cnt[maxn], pos[maxn];
vector<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  reset(f, 0x3f);
  FOR(i, 1, n) fi[i] = n + 1, la[i] = 0;
  FOR(i, 1, n) {
    chkmin(fi[a[i]], i);
    chkmax(la[a[i]], i);
    cnt[a[i]]++;
    G[a[i]].eb(i);
  }
  f[0] = 0;
  FOR(i, 1, n) {
    chkmin(f[i], f[i - 1] + 1);
    if (fi[a[i]] == i) chkmin(f[la[a[i]]], f[i - 1] + la[a[i]] - fi[a[i]] + 1 - cnt[a[i]]);
    else chkmin(f[n], f[i - 1] + n - i + 1 - int(G[a[i]].size()) + pos[a[i]]);
    pos[a[i]]++;
  }
  cout << f[n];
}
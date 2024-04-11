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
const int BLK = 1000;
const int NBLK = maxn / BLK;

int n, m;
int a[maxn], op[maxn], q[maxn][2], c0[NBLK][maxn * 2], c1[NBLK][maxn];

void add(int i, int x) {
  c0[i][x]++;
  c1[i][c0[i][x]]++;
}

void del(int i, int x) {
  c1[i][c0[i][x]]--;
  c0[i][x]--;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) cin >> a[i];
  vector<int> candidates(a, a + n);
  cin >> m;
  REP(i, m) {
    cin >> op[i] >> q[i][0] >> q[i][1];
    if (op[i] == 1) candidates.eb(q[i][0]);
  }
  sort(all(candidates));
  uni(candidates);
  REP(i, n) a[i] = lower_bound(all(candidates), a[i]) - candidates.begin();
  REP(i, m) if (op[i] == 1) q[i][0] = lower_bound(all(candidates), q[i][0]) - candidates.begin();
  for (int i = 0; i * BLK < n; i++) REP(j, i * BLK) add(i, a[j]);
  REP(i, m) {
    if (op[i] == 1) {
      int x = q[i][0], y = q[i][1] - 1;
      for (int j = y / BLK + 1; j * BLK < n; j++) {
        del(j, a[y]);
        add(j, x);
      }
      a[y] = x;
      continue;
    }
    int x = q[i][0], y = q[i][1] - 1;
    if (x == 1) {
      cout << candidates[a[y]] << '\n';
      continue;
    }
    int b = y / BLK;
    FOR(j, b * BLK, y) add(b, a[j]);
    int c = c0[b][a[y]];
    if (x % 2 == 0) cout << c << '\n';
    else cout << c1[b][c] << '\n';
    FOR(j, b * BLK, y) del(b, a[j]);
  }
}
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

const int maxn = 312345;

int tot, n;
int nxt[30 * maxn][2], cnt[30 * maxn], A[maxn], P[maxn];

void insert(int x) {
  int u = 0;
  ROF(i, 29, 0) {
    int ch = (x >> i) & 1;
    if (nxt[u][ch] == -1) nxt[u][ch] = ++tot;
    u = nxt[u][ch];
    cnt[u]++;
  }
}

int query(int x) {
  int u = 0, ret = 0;
  ROF(i, 29, 0) {
    int ch = (x >> i) & 1;
    if (nxt[u][ch] != -1 && cnt[nxt[u][ch]]) u = nxt[u][ch];
    else {
      u = nxt[u][1 - ch];
      ret |= 1 << i;
    }
    cnt[u]--;
  }
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> A[i];
  reset(nxt, -1);
  FOR(i, 1, n) {
    cin >> P[i];
    insert(P[i]);
  }
  FOR(i, 1, n) cout << query(A[i]) << ' ';
}
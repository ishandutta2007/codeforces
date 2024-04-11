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

int n, tot;
int a[maxn], pre[maxn], s[maxn], head[maxn][2], tail[maxn][2];

struct Node {
  int v, nxt;
} nodes[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  int ans = 0;
  REP(j, 20) {
    int ALL = (1 << 20) - 1;
    REP(i, j + 1) ALL -= 1 << i;
    REP(mask, 1 << 20) {
      head[mask][0] = head[mask][1] = -1;
      tail[mask][0] = tail[mask][1] = -1;
    }
    tot = 0;
    FOR(i, 1, n) {
      pre[i] = a[i] & ALL;
      pre[i] = pre[i - 1] ^ pre[i];
      s[i] = (a[i] >> j) & 1;
      s[i] = s[i] + s[i - 1];
    }
    REP(i, n) {
      nodes[++tot].v = i;
      nodes[tot].nxt = -1;
      if (head[pre[i]][i % 2] == -1) head[pre[i]][i % 2] = tail[pre[i]][i % 2] = tot;
      else {
        nodes[tail[pre[i]][i % 2]].nxt = tot;
        tail[pre[i]][i % 2] = tot;
      }
    }
    int l = 1;
    FOR(r, 2, n) {
      while (l <= r && s[r] - s[l - 1] < r - l + 1) l++;
      if (l > r) continue;
      while (head[pre[r]][r % 2] != -1 && nodes[head[pre[r]][r % 2]].v < l - 1) head[pre[r]][r % 2] = nodes[head[pre[r]][r % 2]].nxt;
      if (head[pre[r]][r % 2] != -1 && nodes[head[pre[r]][r % 2]].v < r) chkmax(ans, r - nodes[head[pre[r]][r % 2]].v);
    }
  }
  cout << ans;
}
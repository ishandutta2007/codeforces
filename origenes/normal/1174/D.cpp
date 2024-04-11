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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

int n, x;
bool vis[1 << 18];

int main() {
  scanf("%d%d", &n, &x);
  vector<int> ans{0};
  vis[x] = true;
  FOR(i, 1, (1 << n) - 1) if (!vis[i]) {
    ans.eb(i);
    vis[i ^ x] = true;
  }
  printf("%d\n", int(ans.size()) - 1);
  FOR(i, 1, int(ans.size()) - 1) printf("%d ", ans[i] ^ ans[i - 1]);
}
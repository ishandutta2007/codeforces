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

int n;
int a[maxn], nex[maxn];
bool vis[maxn];
vector<int> G[4];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ROF(i, n, 1) if (a[i]) {
    if (a[i] == 1) G[1].eb(i);
    else if (a[i] == 2) {
      if (G[1].empty()) {
        puts("-1");
        return 0;
      }
      nex[i] = G[1].back();
      G[1].pop_back();
      G[2].eb(i);
    } else {
      if (!G[3].empty()) nex[i] = G[3].back();
      else if (!G[2].empty()) nex[i] = G[2].back();
      else if (!G[1].empty()) {
        nex[i] = G[1].back();
        G[1].pop_back();
      } else {
        puts("-1");
        return 0;
      }
      G[3].eb(i);
    }
  }
  int r = 1;
  vector<pii> ans;
  FOR(i, 1, n) if (!vis[i] && a[i]) {
    int c = i;
    while (c) {
      vis[c] = true;
      if (a[c] == 1) {
        ans.eb(r, c);
        r++;
        c = nex[c];
      } else if (a[c] == 2) {
        ans.eb(r, c);
        c = nex[c];
      } else {
        ans.eb(r, c);
        c = nex[c];
        ans.eb(r, c);
        r++;
      }
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto [r, c] : ans) printf("%d %d\n", r, c);
}
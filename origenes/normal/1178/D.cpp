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

const int maxn = 2123;

int n;
bool vis[maxn];

int main() {
  vis[1] = true;
  FOR(i, 2, 2000) if (!vis[i]) for (int j = i + i; j <= 2000; j += i) vis[j] = true;
  scanf("%d", &n);
  vector<pii> ans;
  REP(i, n) ans.eb(i + 1, (i + 1) % n + 1);
  FOR(i, n, n + n / 2) {
    if (!vis[i]) break;
    int j = i - n;
    ans.eb(j + 1, j + n / 2 + 1);
  }
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d %d\n", x._1, x._2);
}
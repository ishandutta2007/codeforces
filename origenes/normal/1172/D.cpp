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

const int maxn = 1123;

vector<pair<pii, pii>> ans;
int n;
int r[maxn], c[maxn], pr[maxn], pc[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", r + i);
    pr[r[i]] = i;
  }
  FOR(i, 1, n) {
    scanf("%d", c + i);
    pc[c[i]] = i;
  }
  FOR(i, 1, n) if (pr[i] != pc[i] || pr[i] != i) {
    ans.eb(mp(pr[i], i), mp(i, pc[i]));
    int x = c[i], y = r[i];
    swap(r[i], r[pr[i]]);
    swap(c[i], c[pc[i]]);
    swap(pc[i], pc[x]);
    swap(pr[i], pr[y]);
  }
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d %d %d %d\n", it._1._1, it._1._2, it._2._1, it._2._2);
}
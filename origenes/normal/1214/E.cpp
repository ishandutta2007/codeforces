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
int d[maxn], id[maxn], pos[2 * maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", d + i);
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [](int a, int b) { return d[a] > d[b]; });
  vector<pii> ans;
  pos[1] = id[1] * 2 - 1;
  FOR(i, 1, d[id[1]] - 1) {
    ans.eb(id[i] * 2 - 1, id[i + 1] * 2 - 1);
    pos[i + 1] = id[i + 1] * 2 - 1;
  }
  ans.eb(pos[d[id[1]]], id[1] * 2);
  pos[d[id[1]] + 1] = id[1] * 2;
  int en = d[id[1]] + 1;
  FOR(i, 2, d[id[1]]) {
    int need = d[id[i]];
    if (i + need > en) {
      assert(en + 1 == i + need);
      pos[++en] = id[i] * 2;
    }
    ans.eb(pos[i + need - 1], id[i] * 2);
  }
  FOR(i, d[id[1]] + 1, n) {
    ans.eb(id[i] * 2 - 1, pos[1]);
    if (d[id[i]] == 1) ans.eb(id[i] * 2 - 1, id[i] * 2);
    else {
      int need = d[id[i]] - 1;
      ans.eb(pos[need], id[i] * 2);
    }
  }
  for (auto x : ans) printf("%d %d\n", x._1, x._2);
}
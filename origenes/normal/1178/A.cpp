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

const int maxn = 112;

int a[maxn], id[maxn];
int n, need;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    need += a[i];
  }
  need = (need + 2) / 2;
  iota(id + 1, id + n + 1, 1);
  need -= a[1];
  sort(id + 2, id + n + 1, [&](const int i, const int j) { return a[i] < a[j]; });
  vector<int> ans{1};
  FOR(i, 2, n) {
    if (need <= 0) break;
    if (a[id[i]] <= a[1] / 2) {
      ans.eb(id[i]);
      need -= a[id[i]];
    }
  }
  if (need > 0) puts("0");
  else {
    printf("%d\n", int(ans.size()));
    for (auto x : ans) printf("%d ", x);
  }
}
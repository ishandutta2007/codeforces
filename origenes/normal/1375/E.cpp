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

const int maxn = 1123;

int n, a[maxn], id[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [&](int i, int j) {return a[i] < a[j]; });
  vector<pii> ans;
  FOR(i, 1, n) FOR(j, 1, n - 1) if (id[j] > id[j + 1]) {
    ans.eb(id[j + 1], id[j]);
    swap(id[j + 1], id[j]);
  }
  printf("%d\n", int(ans.size()));
  for (auto [u, v] : ans) printf("%d %d\n", u, v);
}
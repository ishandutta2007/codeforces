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

vector<pii> ans;

void solve(int l, int r) {
  if (l == r) return;
  int mi = l + r >> 1;
  solve(l, mi);
  solve(mi + 1, r);
  REP(i, mi - l + 1) ans.eb(l + i, mi + 1 + i);
}

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 2) {
    puts("0");
    return 0;
  }
  int k = 0;
  while ((1 << k + 1) < n) k++;
  solve(1, 1 << k);
  solve(n - (1 << k) + 1, n);
  printf("%d\n", int(ans.size()));
  for (auto [x, y] : ans) printf("%d %d\n", x, y);
}
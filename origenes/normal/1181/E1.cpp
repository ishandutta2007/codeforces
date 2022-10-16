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

struct Rec {
  int l, r, u, d;
} tab[maxn];

inline bool cmpv(const Rec &r1, const Rec &r2) {
  return r1.l < r2.l;
}

inline bool cmph(const Rec &r1, const Rec &r2) {
  return r1.d < r2.d;
}

int n;

bool solve(int l, int r) {
  if (l == r) return true;
  sort(tab + l, tab + r + 1, cmpv);
  int pre = tab[l].r;
  FOR(i, l + 1, r) {
    if (tab[i].l >= pre) return solve(l, i - 1) && solve(i, r);
    chkmax(pre, tab[i].r);
  }
  sort(tab + l, tab + r + 1, cmph);
  pre = tab[l].u;
  FOR(i, l + 1, r) {
    if (tab[i].d >= pre) return solve(l, i - 1) && solve(i, r);
    chkmax(pre, tab[i].u);
  }
  return false;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d%d%d", &tab[i].l, &tab[i].d, &tab[i].r, &tab[i].u);
  puts(solve(1, n) ? "YES" : "NO");
}
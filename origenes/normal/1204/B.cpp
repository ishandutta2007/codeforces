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

int n, l, r;
int mn[maxn], mx[maxn];

int main() {
  scanf("%d%d%d", &n, &l, &r);
  REP(i, l) mn[n - i] = 1 << l - i - 1;
  ROF(i, n - l, 1) mn[i] = 1;
  FOR(i, 1, r) mx[i] = 1 << i - 1;
  FOR(i, r + 1, n) mx[i] = 1 << r - 1;
  printf("%d %d", accumulate(mn + 1, mn + n + 1, 0), accumulate(mx + 1, mx + n + 1, 0));
}
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

const int maxn = 5123;

int a[maxn], n;

int solve(int l, int r) {
  if (l > r) return 0;
  if (l == r) return a[l] > 0;
  int best = l;
  FOR(i, l + 1, r) if (a[i] < a[best]) best = i;
  int dec = a[best];
  FOR(i, l, r) a[i] -= dec;
  return min(dec + solve(l, best - 1) + solve(best + 1, r), r - l + 1);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  printf("%d", solve(1, n));
}
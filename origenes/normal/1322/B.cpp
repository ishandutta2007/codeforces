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

const int maxn = 412345;

int n, a[maxn], b[maxn];

ll f(int lim) {
  ll ret = 0;
  int j = n;
  FOR(i, 1, n) {
    while (j > 0 && b[i] + b[j] >= lim) j--;
    ret += (n - j) - (j < i);
  }
  return ret / 2;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int ALL = 0, ans = 0;
  REP(j, 25) {
    ALL |= 1 << j;
    FOR(i, 1, n) b[i] = a[i] & ALL;
    sort(b + 1, b + n + 1);
    int cnt = (f(1 << j) - f(2 << j) + f(3 << j)) & 1;
    ans += cnt << j;
  }
  printf("%d", ans);
}
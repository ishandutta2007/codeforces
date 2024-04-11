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

const int maxn = 212345;

int a[maxn], l[maxn], r[maxn], tab[maxn], ans[maxn];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  // bad_l = 0, bad_r = n + 1
  FOR(i, 1, n) {
    scanf("%d", a + i);
    tab[a[i]] = i;
    l[i] = i - 1, r[i] = i + 1;
  }
  int rd = 1;
  ROF(i, n, 1) if (!ans[tab[i]]) {
    ans[tab[i]] = rd;
    int st = tab[i], j, cnt, L, R;
    for (j = l[st], cnt = 0; j && cnt < k; j = l[j], cnt++) ans[j] = rd;
    L = j;
    for (j = r[st], cnt = 0; j < n + 1 && cnt < k; j = r[j], cnt++) ans[j] = rd;
    R = j;
    if (L != 0) r[L] = R;
    if (R != n + 1) l[R] = L;
    rd = rd == 1 ? 2 : 1;
  }
  FOR(i, 1, n) printf("%d", ans[i]);
}
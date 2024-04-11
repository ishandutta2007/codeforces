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

int n, ans;
int a[maxn], cnt[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  FOR(i, 1, 200000) {
    int tot = 0, j = i - 1;
    while (cnt[i] >= 2) tot += cnt[i], i++;
    chkmax(ans, cnt[i] + cnt[j] + tot);
  }
  FOR(i, 1, 200000) {
    int tot = 0, j = i - 1;
    while (cnt[i] >= 2) tot += cnt[i], i++;
    if (cnt[i] + cnt[j] + tot == ans) {
      printf("%d\n", ans);
      FOR(k, j, i) while (cnt[k] > 1) {
        printf("%d ", k);
        cnt[k]--;
      }
      ROF(k, i, j) if (cnt[k] > 0) printf("%d ", k);
      return 0;
    }
  }
}
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

int n, l[maxn], r[maxn], cnt[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    cnt[l[i]]++, cnt[r[i]]--;
  }
  int now = cnt[0], ans = 0;
  FOR(i, 1, 100) {
    if (now == 1 && l[1] <= i - 1 && i <= r[1]) ans++;
    now += cnt[i];
  }
  printf("%d", ans);
}
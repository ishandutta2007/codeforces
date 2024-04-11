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

const int maxn = 112345;

int n;
char a[maxn], b[maxn];

int main() {
  scanf("%d", &n);
  scanf("%s%s", a + 1, b + 1);
  int ans = 0;
  if (n % 2 == 1 && a[n / 2 + 1] != b[n / 2 + 1]) ans++;
  FOR(i, 1, n / 2) {
    int cnt[26] = {};
    cnt[a[i] - 'a']++, cnt[a[n - i + 1] - 'a']++;
    cnt[b[i] - 'a']++, cnt[b[n - i + 1] - 'a']++;
    int type = 0;
    bool f = false;
    REP(j, 26) if (cnt[j]) {
      type++;
      if (cnt[j] % 2 == 1) f = true;
    }
    if (type == 2 && f) ans++;
    else if (type == 3) {
      ans++;
      if (a[i] == a[n - i + 1]) ans++;
    } else if (type == 4) ans += 2;
  }
  printf("%d", ans);
}
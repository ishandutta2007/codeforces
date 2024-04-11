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

int n, k, a, ans;
int cnt[maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    scanf("%d", &a);
    cnt[a]++;
  }
  FOR(i, 1, k) while (cnt[i] >= 2) cnt[i] -= 2, ans += 2;
  bool fi = true;
  FOR(i, 1, k) if (cnt[i]) {
    if (fi) {
      ans++;
      fi = false;
    } else fi = true;
  }
  printf("%d", ans);
}
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

int n, m;
int t[maxn], l[maxn], r[maxn], a[maxn];
bool vis[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d%d", t + i, l + i, r + i);
    if (t[i]) FOR(j, l[i], r[i] - 1) vis[j] = true;
  }
  a[1] = 1e7;
  FOR(i, 1, n - 1) a[i + 1] = a[i] - !vis[i];
  FOR(i, 1, m) if (!t[i]) {
    bool good = false;
    FOR(j, l[i], r[i] - 1) if (a[j] > a[j + 1]) good = true;
    if (!good) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  FOR(i, 1, n) printf("%d ", a[i]);
}
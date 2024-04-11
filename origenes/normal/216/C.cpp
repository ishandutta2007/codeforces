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

const int maxn = 3123;

int n, m, k;
int have[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  vector<int> ans;
  FOR(i, 1, m + n) {
    int need = 0;
    if (have[i] < k) need = k - have[i];
    if (!have[i + 1] && !need) need = 1;
    if (need) {
      FOR(j, i, i + n - 1) have[j] += need;
      while (need--) ans.eb(i);
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d ", x);
}
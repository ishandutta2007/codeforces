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

const int maxn = 512;
const int sigma_size = 26;

char mat[maxn][maxn];
int n, m, ans;
vector<int> odd;
vector<vector<int>> cnt;

inline bool check(int i, int j) {
  if (odd[i] > 1 || odd[j] > 1) return false;
  return cnt[i] == cnt[j];
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  FOR(lo, 1, m) {
    odd = vector<int>(maxn);
    cnt = vector<vector<int>>(maxn, vector<int>(sigma_size));
    FOR(hi, lo, m) {
      FOR(i, 1, n) {
        int &cur = cnt[2 * i - 1][mat[i][hi] - 'a'];
        if (++cur & 1) odd[2 * i - 1]++;
        else odd[2 * i - 1]--;
      }
      vector<int> p(maxn);
      p[0] = 1;
      int o = 0, mx = 0;
      FOR(i, 1, 2 * n) {
        if (i <= mx) {
          p[i] = mx - i;
          if (2 * o - i >= 0) chkmin(p[i], p[2 * o - i]);
        }
        else p[i] = 1;
        while (p[i] <= i && i + p[i] <= 2 * n + 1 && check(i - p[i], i + p[i])) p[i]++;
        if (odd[i] > 1) p[i] = 1;
        if (mx < i + p[i]) {
          o = i;
          mx = i + p[i];
        }
        ans += p[i] >> 1;
      }
    }
  }
  printf("%d", ans);
}
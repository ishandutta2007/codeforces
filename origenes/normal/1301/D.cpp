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

int re[maxn];
string op[maxn];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (k > 4 * n * m - 2 * n - 2 * m) {
    puts("NO");
    return 0;
  }
  int f = 0;
  if (m == 1) {
    REP(i, n - 1) {
      if (!k) break;
      re[++f] = 1, op[f] = "D";
      k--;
    }
    REP(i, n - 1) {
      if (!k) break;
      re[++f] = 1, op[f] = "U";
      k--;
    }
  } else {
    FOR(i, 1, n - 1) {
      if (k > m - 1) {
        re[++f] = m - 1;
        op[f] = "R";
      } else {
        re[++f] = k;
        op[f] = "R";
      }
      k -= m - 1;
      if (k <= 0) break;
      if (k > 3 * (m - 1)) {
        re[++f] = m - 1;
        op[f] = "DUL";
      } else {
        int complete = k / 3;
        if (complete) {
          re[++f] = complete;
          op[f] = "DUL";
          k -= 3 * complete;
        }
        if (k == 1) {
          re[++f] = 1;
          op[f] = "D";
        } else if (k == 2) {
          re[++f] = 1;
          op[f] = "DU";
        }
      }
      k -= 3 * (m - 1);
      if (k <= 0) break;
      re[++f] = 1;
      op[f] = "D";
      if (!--k) break;
    }
    if (k > 0) {
      if (k > m - 1) {
        re[++f] = m - 1;
        op[f] = "R";
      } else {
        re[++f] = k;
        op[f] = "R";
      }
      k -= m - 1;
    }
    if (k > 0) {
      if (k > m - 1) {
        re[++f] = m - 1;
        op[f] = "L";
      } else {
        re[++f] = k;
        op[f] = "L";
      }
      k -= m - 1;
    }
    if (k > 0) {
      assert(k <= n - 1);
      re[++f] = k;
      op[f] = "U";
    }
  }
  puts("YES");
  printf("%d\n", f);
  FOR(i, 1, f) printf("%d %s\n", re[i], op[i].c_str());
}
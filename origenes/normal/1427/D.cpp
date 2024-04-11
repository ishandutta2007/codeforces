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

const int maxn = 55;

int n;
int c[maxn];
vector<vector<int>> ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", c + i);
  while (true) {
    int tail = n;
    if (c[n] == n) {
      ROF(i, n - 1, 1) if (c[i] != c[i + 1] - 1) {
        tail = i;
        break;
      }
      if (tail == n) break;
    }
    vector<int> now;
    vector<vector<int>> tmp;
    if (tail != n) {
      now.eb(n - tail);
      tmp.eb(c + tail + 1, c + n + 1);
    }
    ROF(i, tail, 1) if (c[i] == c[tail] + 1) {
      int j;
      for (j = tail - 1; j >= i; j--) if (c[j] != c[j + 1] - 1) break;
      now.eb(tail - j);
      tmp.eb(c + j + 1, c + tail + 1);
      now.eb(j - i + 1);
      tmp.eb(c + i,  c + j + 1);
      if (i != 1) {
        now.eb(i - 1);
        tmp.eb(c + 1, c + i);
      }
      break;
    }
    reverse(all(now));
    ans.eb(now);
    int i = 1;
    for (const auto &x : tmp) for (auto y : x) c[i++] = y;
  }
  printf("%d\n", int(ans.size()));
  for (const auto &x : ans) {
    printf("%d", int(x.size()));
    for (auto y : x) printf(" %d", y);
    putchar('\n');
  }
}
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

const int maxn = 312345;

int p[maxn], loc[maxn];
int n;
vector<pii> ans;

inline void go(int i, int j) {
  if (i > j) swap(i, j);
  ans.eb(i, n);
  ans.eb(n, 1);
  ans.eb(1, j);
  ans.eb(1, n);
  ans.eb(i, n);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", p + i);
    loc[p[i]] = i;
  }
  FOR(i, 1, n) if (p[i] != i) {
    int j = loc[i];
    if (2 * abs(i - j) >= n) {
      ans.eb(i, j);
      p[j] = p[i];
      loc[p[i]] = j;
      p[i] = i;
      loc[i] = i;
    } else {
      if (i <= n / 2 && j <= n / 2) {
        int t = n;
        ans.eb(i, t);
        ans.eb(j, t);
        ans.eb(i, t);
      } else if (i > n / 2 && j > n / 2) {
        int t = 1;
        ans.eb(i, t);
        ans.eb(j, t);
        ans.eb(i, t);
      } else go(i, j);
      p[j] = p[i];
      loc[p[i]] = j;
      p[i] = i;
      loc[i] = i;
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d %d\n", it._1, it._2);
}
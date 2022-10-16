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

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  FOR(i, 1, n / 2) FOR(j, 1, m) {
    printf("%d %d\n", i, j);
    printf("%d %d\n", n - i + 1, m - j + 1);
  }
  if (n & 1) {
    int x = n / 2 + 1;
    printf("%d 1\n", x);
    int st = 2, en = m;
    while (st <= en) {
      printf("%d %d\n", x, en);
      en--;
      if (st <= en) printf("%d %d\n", x, st);
      st++;
    }
  }
}
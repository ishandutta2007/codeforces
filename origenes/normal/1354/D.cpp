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

const int maxn = 1123456;

int a[maxn], k[maxn];
int n, q;

bool check(int tar) {
  int cnt = 0;
  FOR(i, 1, n) if (a[i] <= tar) cnt++;
  FOR(i, 1, q) {
    if (k[i] > 0) {
      if (k[i] <= tar) cnt++;
    } else if (k[i] >= -cnt) cnt--;
  }
  return cnt > 0;
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  int cnt = 0;
  FOR(i, 1, q) {
    scanf("%d", k + i);
    k[i] > 0 ? cnt++ : cnt--;
  }
  if (n + cnt == 0) {
    puts("0");
    return 0;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lo);
}
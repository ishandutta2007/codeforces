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

int a1, a2, k1, k2, n;

int main() {
  scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }
  int nn = n - a1 * (k1 - 1) - a2 * (k2 - 1);
  int mn = nn <= 0 ? 0 : nn;
  int mx = a1 * k1 >= n ? n / k1 : a1 + (n - a1 * k1) / k2;
  printf("%d %d", mn, mx);
}
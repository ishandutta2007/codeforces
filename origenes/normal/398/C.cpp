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

int n;

int main() {
  scanf("%d", &n);
  if (n == 5) {
    puts("1 3 3\n1 2 3\n2 4 2\n4 5 1");
    puts("3 4");
    puts("3 5");
    return 0;
  }
  FOR(i, 1, n / 2) printf("%d %d 1\n", i, i + n / 2);
  FOR(i, n / 2 + 1, n - 1) printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
  puts("1 3");
  FOR(i, 1, n / 2 - 1) printf("%d %d\n", i, i + 1);
}
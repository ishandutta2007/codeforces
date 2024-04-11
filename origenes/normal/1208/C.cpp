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

const int ans4[4][4] = {
    {8, 9, 1, 13},
    {3, 12, 7, 5},
    {0, 2, 4, 11},
    {6, 10, 15, 14}
};

int n;

int main() {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, n) printf("%d ", ans4[i & 3][j & 3] | ((i / 4 * (n / 4) + j / 4) << 4));
    putchar('\n');
  }
}
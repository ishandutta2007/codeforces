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

const int maxn = 2123;
const char vowels[] = {'a', 'e', 'i', 'o', 'u'};

int k;
char mat[maxn][maxn];

int main() {
  cin >> k;
  int upp = sqrt(k) + 0.5;
  FOR(i, 5, upp) if (k % i == 0) {
    int n = i, m = k / i;
    FOR(j, 1, n) REP(kk, 5) mat[j][kk] = vowels[(j + kk) % 5];
    FOR(kk, 5, m - 1) FOR(j, 1, n) mat[j][kk] = vowels[j % 5];
    FOR(j, 1, n) REP(kk, m) cout << mat[j][kk];
    return 0;
  }
  cout << -1;
}
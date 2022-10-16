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

const int maxn = 212345;

int n, diff[maxn], diff2[maxn];
pii b[maxn];

int main() {
  scanf("%d", &n);
  if (n <= 3) {
    puts("1");
    return 0;
  }
  FOR(i, 1, n) {
    scanf("%d", &b[i]._1);
    b[i]._2 = i;
  }
  sort(b + 1, b + n + 1);
  FOR(i, 1, n - 1) diff[i] = b[i + 1]._1 - b[i]._1;
  FOR(i, 1, n - 2) diff2[i] = b[i + 2]._1 - b[i]._1;
  bool good = true;
  FOR(i, 2, n - 1) if (diff[i] != diff[2]) {
    good = false;
    break;
  }
  if (good) {
    printf("%d", b[1]._2);
    return 0;
  }
  good = true;
  FOR(i, 1, n - 2) if (diff[i] != diff[1]) {
    good = false;
    break;
  }
  if (good) {
    printf("%d", b[n]._2);
    return 0;
  }
  good = true;
  FOR(i, 3, n - 1) if (diff[i] != diff2[1]) {
    good = false;
    break;
  }
  if (good) {
    printf("%d", b[2]._2);
    return 0;
  }
  good = true;
  int changed = 0;
  FOR(i, 2, n - 2) {
    if (diff[i] == diff[1] || i == changed) continue;
    if (!changed && diff2[i] == diff[1]) {
      changed = i + 1;
      continue;
    }
    good = false;
    break;
  }
  if (changed != n - 1 && diff[n - 1] != diff[1]) good = false;
  if (good) printf("%d", b[changed]._2);
  else puts("-1");
}
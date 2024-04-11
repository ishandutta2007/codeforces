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

const int maxn = 212345;

int a[maxn], n;
bool vis[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int inc = -1, dec = maxn;
  FOR(i, 1, n) {
    int flag = 0;
    if (a[i] > inc) flag++;
    if (a[i] < dec) flag += 2;
    if (!flag) {
      puts("NO");
      return 0;
    }
    if (flag == 1) inc = a[i];
    else if (flag == 2) dec = a[i], vis[i] = true;
    else {
      if (a[i] < a[i + 1]) inc = a[i];
      else dec = a[i], vis[i] = true;
    }
  }
  puts("YES");
  FOR(i, 1, n) printf("%d ", vis[i]);
}
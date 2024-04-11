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

const int maxn = 112345;

int n, tail;
char a[maxn], b[maxn], ans[maxn][2];
map<int, int> par;

char Find(char x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

bool Union(int x, int y) {
  x = Find(x), y = Find(y);
  if (x != y) {
    par[x] = y;
    return true;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  scanf("%s%s", a + 1, b + 1);
  FOR(i, 'a', 'z') par[i] = i;
  FOR(i, 1, n) if (Union(a[i], b[i])) {
    ans[++tail][0] = b[i];
    ans[tail][1] = a[i];
  }
  printf("%d\n", tail);
  FOR(i, 1, tail) printf("%c %c\n", ans[i][1], ans[i][0]);
}
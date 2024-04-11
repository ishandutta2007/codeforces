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

int n, m, p;

int main() {
  scanf("%d%d%d", &n, &m, &p);
  vector<int> f(n), g(m);
  for (auto &x : f) scanf("%d", &x);
  for (auto &x : g) scanf("%d", &x);
  if (n > m) {
    swap(n, m);
    swap(f, g);
  }
  for (auto &x : f) x %= p;
  for (auto &x : g) x %= p;
  int i = 0, j = 0;
  while (f[i] == 0) i++;
  while (g[j] == 0) j++;
  printf("%d", i + j);
}
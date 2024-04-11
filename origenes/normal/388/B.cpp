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

const int maxn = 92;

int G[maxn][maxn], k;

void add(int u, int v) {
  G[u][v] = G[v][u] = 1;
}

int main() {
  scanf("%d", &k);
  FOR(i, 2, 30) {
    add(i, i + 1);
    add(i + 30, i + 31);
    add(i + 30, i + 61);
    add(i + 60, i + 31);
    add(i + 60, i + 61);
  }
  add(0, 31); add(1, 32); add(1, 62);
  if (k & 1) k ^= 1, add(1, 2);
  FOR(i, 1, 30) if (k & (1 << i)) add((i + 1) % 31 + 1, i + 31), add((i + 1) % 32 + 1, i + 61);
  puts("92");
  REP(i, 92) {
    REP(j, 92) putchar(G[i][j] ? 'Y' : 'N');
    putchar('\n');
  }
}
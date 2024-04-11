#include <cstdio>
#include <set>

using namespace std;

const int N = 1 << 17;
const int md = 777777777;

int tree[2 * N], a[N];
int cm[5][5], tmp[5][5], ways[N][5][5];
int good[5][5];


void tset(int x, int y) {
  x += N;
  tree[x] = y;
  while (x > 1) {
    x >>= 1;
    tree[x] = (long long) tree[x * 2] * tree[x * 2 + 1] % md;
  }
}

int tget(int l, int r) {
  --r;
  l += N;
  r += N;
  int ret = 1;
  while (l <= r) {
    if (l & 1) {
      ret = (long long) ret * tree[l] % md;
      l++;
    }
    if ((r & 1) == 0) {
      ret = (long long) ret * tree[r] % md;
      --r;
    }
    l >>= 1;
    r >>= 1;
  }
  return ret;
}


int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) 
      scanf("%d", good[i] + j);
  for (int i = 1; i <= 3; i++) good[0][i] = 1;
  for (int i = 1; i <= 3; i++) good[i][4] = 1;
  set<int> nz;
  nz.insert(0);
  nz.insert(n + 1);
  for (int i = 0; i < 5; i++) 
    cm[i][i] = 1;
  for (int pw = 1; pw <= n + 1; pw++) {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) {
        long long z = 0;
        for (int k = 0; k < 5; k++) {
          z = (z + (long long) cm[i][k] * good[k][j]) % md;
        }
        tmp[i][j] = z;
      }
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) cm[i][j] = tmp[i][j];
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        ways[pw][i][j] = cm[i][j];
  }
  for (int i = 1; i <= n; i++) tset(i, 1);
  tset(0, ways[n + 1][0][4]);
  for (int i = 1; i <= n; i++) a[i] = -1;
  a[n + 1] = 4;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (y == 0) --y;
    if (y >= 0) {
      a[x] = y;
      nz.insert(x);
      set<int>::iterator it1 = nz.find(x);
      --it1;
      int prev = *it1;
      ++it1;
      ++it1;
      int next = *it1;
      tset(prev, ways[x - prev][a[prev]][a[x]]);
      tset(x, ways[next - x][a[x]][a[next]]);
    } else if (a[x] >= 0) {
      a[x] = y;
      set<int>::iterator it1 = nz.find(x);
      --it1;
      int prev = *it1;
      ++it1;
      ++it1;
      int next = *it1;
      nz.erase(x);
      tset(prev, ways[next - prev][a[prev]][a[next]]);
      tset(x, 1);
    }
    printf("%d\n", tget(0, n + 1));
  }
}
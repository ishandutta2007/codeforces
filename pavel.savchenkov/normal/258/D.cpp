#include <cstdio>
#include <algorithm>
#include <memory.h>

const int MAXN = 1010;

using namespace std;

double p[MAXN][MAXN];
int arr[MAXN];
int n, m;

int main() {
  memset(p, 0.0, sizeof p);

  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    arr[i]--;
  }

  memset(p, 0.0, sizeof p);
  for (int i = 0; i < n; i++) 
    for (int j = i + 1; j < n; j++)
      if  (arr[i] > arr[j])
        p[i][j] = 1.0;

  for (int it = 0; it < m; it++) {
    int a, b; scanf("%d%d", &a, &b); a--; b--;
    if  (a > b) swap(a, b);
    
    p[a][b] = 0.5;
    
    for (int c = 0; c < a; c++) {
      double pa = p[c][a];
      double pb = p[c][b];
      p[c][a] = p[c][b] = 0.5 * pa + 0.5 * pb;
    }
    
    for (int c = a + 1; c < b; c++) {
     double pa = p[a][c];
     double pb = p[c][b];
     p[a][c] = 0.5 * pa + 0.5 * (1.0 - pb);
     p[c][b] = 0.5 * (1.0 - pa) + 0.5 * pb; 
    }
    
    for (int c = b + 1; c < n; c++) {
      double pa = p[a][c];
      double pb = p[b][c];
      p[a][c] = p[b][c] = 0.5 * pa + 0.5 * pb; 
    }
  }

  double res = 0.0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      res += p[i][j];

  printf("%.10lf\n", res);
  return 0;
}
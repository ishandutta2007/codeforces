#include <cstdio>
#include <algorithm>

int b[111][111];
int x[111], y[111], a[111];

int main() {
  int n,d,i,j,k;
  scanf("%d%d",&n,&d);  
  for (i=1;i<n-1;i++) scanf("%d", a+i);
  for (i=0;i<n;i++) scanf("%d%d", x+i, y+i);
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      if (i == j) b[i][j] = 0; else
      b[i][j] = d*(std::abs(x[i]-x[j])+std::abs(y[i]-y[j]))-a[i];
  for (k=0;k<n;k++) 
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        b[i][j] = std::min(b[i][j], b[i][k]+b[k][j]);
  printf("%d\n", b[0][n-1]);
}
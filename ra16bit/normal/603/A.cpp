#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,r,f[100100][3][2];
char s[100100];
int main() {
  scanf("%d",&n);
  scanf("%s",s+1);
  f[0][0][0]=f[0][0][1]=1;
  for (i=1; i<=n; i++) {
    for (j=0; j<3; j++) {
      for (k=0; k<2; k++) f[i][j][k]=f[i-1][j][k];
      k=s[i]-'0';
      if (j==1) k=1-k;
      if (f[i-1][j][1-k]) f[i][j][k]=max(f[i][j][k],f[i-1][j][1-k]+1);
      if (j>0 && f[i-1][j-1][1-k]) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][1-k]+1);
    }
  }
  for (j=1; j<3; j++) for (k=0; k<2; k++) r=max(r,f[n][j][k]);
  printf("%d\n",r-1);
  return 0;
}
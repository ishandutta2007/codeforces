#include <stdio.h>
int n,m,i,j,a[256][256],b[256],f[256],g[256],md=1000000007;
char s[5][2222];
long long c;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s[0]);
    for (j=0; j<3; j++) scanf("%s",s[j]);
    for (j=0; j<m; j++) {
      a[i][j]=0;
      if (s[0][j*4+1]=='O' && s[0][j*4+2]=='O' && s[0][j*4+3]=='O') a[i][j]=1;
      if (s[0][j*4+1]=='O' && s[1][j*4+1]=='O' && s[2][j*4+1]=='O') a[i][j]=2;
      if (s[0][j*4+1]=='.' && s[1][j*4+2]=='O' && s[2][j*4+3]=='.' && s[0][j*4+3]=='O' && s[2][j*4+1]=='O') a[i][j]=2;
      if (s[0][j*4+1]=='O' && s[1][j*4+2]=='O' && s[2][j*4+3]=='O' && s[0][j*4+3]=='.' && s[2][j*4+1]=='.') a[i][j]=1;
      if (s[0][j*4+1]=='.' && s[1][j*4+2]=='.' && s[2][j*4+3]=='.' && s[0][j*4+3]=='O' && s[2][j*4+1]=='O') a[i][j]=2;
      if (s[0][j*4+1]=='O' && s[1][j*4+2]=='.' && s[2][j*4+3]=='O' && s[0][j*4+3]=='.' && s[2][j*4+1]=='.') a[i][j]=1;
    }
  }
  f[0]=1;
  for (j=0; j<m; j++) {
  //printf("j=%d\n",j);
    if ((n&1)==0) {
      for (i=0; i<n; i++) if (a[i][j]==1) break;
      if (i>=n) {
        f[j+1]+=f[j];
        if (f[j+1]>=md) f[j+1]-=md;
      }
    }
    if (j<m-1) {
      for (i=0; i<n; i++) {
        if (a[i][j]==1 && a[i][j+1]==2) break;
        if (a[i][j]==2 && a[i][j+1]==1) break;
        if (a[i][j]==1 || a[i][j+1]==1) b[i]=1; else if (a[i][j]==2 || a[i][j+1]==2) b[i]=2; else b[i]=0;
      }
      if (i<n) continue;
      for (i=0; i<=n; i++) g[i]=int(i==0);
      for (i=0; i<n; i++) {
        if (b[i]!=2) {
          g[i+1]+=g[i];
          if (g[i+1]>=md) g[i+1]-=md;
        }
        if (i<n-1 && b[i]!=1 && b[i+1]!=1) {
          g[i+2]+=g[i];
          if (g[i+2]>=md) g[i+2]-=md;
        }
//        printf("%d = %d\n",i+1,g[i+1]);
      }
      c=g[n]; 
      if ((n&1)==0) {
        for (i=0; i<n; i++) if (b[i]==1) break;
        if (i>=n) c=(c-1+md)%md;
      }
      f[j+2]=(f[j+2]+c*f[j])%md;
    }
//    for (int p=0; p<=m; p++) printf("%d ",f[p]);puts("");
  }
  printf("%d\n",f[m]);
  return 0;
}
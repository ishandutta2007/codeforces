#include <cstdio>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;
const int md=1000000007;
//v[5005],q[5005],
int n,i,j,k,p,r,inf,f[5005][5005],sum[5005][5005],sb[5005][5005],best[5005];
char s[5005];
int main() {
  scanf("%s",s); n=strlen(s);
  for (i=0; i<n; i++) f[n][i]=1;
  for (i=n-1; i>=0; i--) for (j=i-1; j>=0; j--) if (s[i]==s[j]) {
       if (f[i+1][j+1]) f[i][j]=f[i+1][j+1]+1; else f[j][i]=f[j+1][i+1]+1;
  } else if (s[i]<s[j]) f[i][j]=1; else f[j][i]=1;
  /*
  for (i=0; i<=n; i++,puts("")) for (j=0; j<=n; j++) if (f[i][j]) {
    printf("%d ",f[i][j]);
  } else printf("~ ");
  /*
  for (fi=fr=i=0; i<=n; i++) if (v[i]==0) q[fr++]=i;
  while (fi<fr) {
    i=q[fi++];
    for (j=0; j<=n; j++) if (g[i][j]) {
      if (--v[j]==0) q[fr++]=j;
    }
  }
  for (i=0; i<n; i++) printf("%d ",q[i]);
  */
  memset(sb,120,sizeof(sb));
  inf=sb[0][0];
  for (i=1; i<=n; i++) {
    memset(best,120,sizeof(best));
    for (j=1; j<i; j++) if (s[i-j]=='1') {
      k=j-1; p=i-j-j;
      if (p>=0 && s[p]=='1'&& (f[p][i-j]>0 || f[i-j][p]>j)) k=j;
      sum[i][j]=(sum[i-j][k]+sum[i][j-1])%md;
      best[j]=min(best[j],sb[i-j][k]+1);
      sb[i][j]=min(best[j],sb[i][j-1]);
    } else {
      sum[i][j]=sum[i][j-1];
      sb[i][j]=sb[i][j-1];
    }
    sum[i][i]=(sum[i][i-1]+1)%md;
    best[i]=sb[i][i]=1;
    for (j=i+1; j<=n; j++) {
      sum[i][j]=sum[i][j-1];
      sb[i][j]=1;
    }
  }
  r=0; j=0; k=1;
  for (i=1; i<=n; i++) {
    if (s[n-i]=='1') j=(j+k)%md;
    k=(k*2)%md;
    if (best[i]<inf) {
      r=(j+best[i])%md;
      break;
    }
  }
  for (i++; i<=n && i<=20; i++) {
    if (s[n-i]=='1') j+=k;
    k*=2;
    if (best[i]<inf) r=min(r,j+best[i]);
  }
  printf("%d\n%d\n",sum[n][n],r);
  return 0;
}
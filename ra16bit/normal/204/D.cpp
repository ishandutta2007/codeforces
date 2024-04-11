#include <stdio.h>
const int MX=1000010,md=1000000007;
int i,n,m,cur,c[MX],f[MX][2],g[MX][2],nw[MX],nb[MX];
char s[MX];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  nw[n]=nb[n]=n;
  for (i=n-1; i>=0; i--) {
    nw[i]=(s[i]=='W')?i:nw[i+1];
    nb[i]=(s[i]=='B')?i:nb[i+1];
  }
  if (nw[0]>=m) f[m][0]++;
  c[0]=1;
  for (i=0; i<=n; i++) {
    //printf("%d: %d %d %d,  %d %d\n",i,c[i],f[i][0],f[i][1],g[i][0],g[i][1]);
    if (i==n) break;
    c[i+1]=c[i];
    if (s[i]!='W') {
      f[i+1][0]+=f[i][0]; if (f[i+1][0]>=md) f[i+1][0]-=md;
      f[i+1][0]+=f[i][1]; if (f[i+1][0]>=md) f[i+1][0]-=md;
      g[i+1][0]+=g[i][0]; if (g[i+1][0]>=md) g[i+1][0]-=md;
      g[i+1][0]+=g[i][1]; if (g[i+1][0]>=md) g[i+1][0]-=md;
    }
    if (s[i]!='B') {
      f[i+1][1]+=f[i][0]; if (f[i+1][1]>=md) f[i+1][1]-=md;
      f[i+1][1]+=f[i][1]; if (f[i+1][1]>=md) f[i+1][1]-=md;
      g[i+1][1]+=g[i][0]; if (g[i+1][1]>=md) g[i+1][1]-=md;
      g[i+1][1]+=g[i][1]; if (g[i+1][1]>=md) g[i+1][1]-=md;
    }
    if (s[i]=='X') {
      c[i+1]+=c[i]; if (c[i+1]>=md) c[i+1]-=md;
    }
    if (i+m<n && s[i]!='B' && nw[i+1]>i+m) {
      cur=c[i]-f[i+1][1]; if (cur<0) cur+=md;
      //printf("%d %d\n",i+m+1,cur);
      f[i+m+1][0]+=cur; if (f[i+m+1][0]>=md) f[i+m+1][0]-=md;
    }
    if (i+m<=n && nb[i]>=i+m) {
      cur=f[i][0]-g[i][0]; if (cur<0) cur+=md;
      //puts("g");
      g[i+m][1]+=cur; if (g[i+m][1]>=md) g[i+m][1]-=md;
    }
  }
  printf("%d\n",(g[n][0]+g[n][1])%md);
  return 0;
}
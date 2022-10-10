#include <stdio.h>
int n,m,d,i,j,k,x,M,cur,res,a[100100],c[22];
bool f[1100100];
int main() {
  scanf("%d%d%d",&n,&m,&d);
  for (i=0; i<m; i++) {
    scanf("%d",&k);
    for (j=0; j<k; j++) { scanf("%d",&x); a[x]=i; }
  }
  M=(1<<m)-1; res=m;
  for (i=1, j=0; i<=n; i++) {
    if (i>d) {
      if (--c[a[i-d]]==0) j^=(1<<a[i-d]);
    }
    ++c[a[i]];
    j|=(1<<a[i]);
    if (i>=d) f[M^j]=true;
  }
  for (i=M; i>=0; i--) if (f[i]) {
    for (j=0; j<m; j++) if (i&(1<<j)) f[i^(1<<j)]=true;
  } else {
    cur=0;
    for (j=0; j<m; j++) if (i&(1<<j)) cur++;
    if (cur<res) res=cur;
  }
  printf("%d\n",res);
  return 0;
}
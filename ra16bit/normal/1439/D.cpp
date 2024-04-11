#include <bits/stdc++.h>
using namespace std;
int n,m,md,len,i,j,k,prv,c[505][505],dpf[505][505],dpr[505][505];
long long cur,crst,f[505],rst[505];
long long sum(long long x) {
  return (x*(x+1LL))/2;
}
int main() {
  scanf("%d%d%d",&n,&m,&md);
  for (i=0; i<=n; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%md;
  }
  for (i=0; i<n; i++) for (k=0; k<=i; k++) {
    cur=c[i][k];
    crst=0;
    if (k>0) {
      crst=(crst*f[k-1]+cur*rst[k-1])%md;
      cur=(cur*f[k-1])%md;
    }
    if (k<i) {
      crst=(crst*f[i-k-1]+cur*rst[i-k-1])%md;
      cur=(cur*f[i-k-1])%md;
    }
    rst[i]=(rst[i]+crst*(i+2LL)+cur*(sum(k)+sum(i-k)))%md;
    f[i]=(f[i]+(i+2LL)*cur)%md;
    //printf("%d..%d (%d) += %d [cur=%d rst=%d+%d+%d] | %d\n",i,j,k,int((j-i+2LL)*cur),int(cur),int(crst),int(sum(k-i)),int(sum(j-k)),int(rst[i][j]));
  }
  dpf[0][0]=1;
  for (i=1; i<=n; i++) for (j=0; j<=i && j<=m; j++) {
    dpf[i][j]=dpf[i-1][j];
    dpr[i][j]=dpr[i-1][j];
    for (k=1; k<=j; k++) {
      prv=i-k;
      if (prv>0) --prv;
      if (j-k<=prv) {
        dpr[i][j]=(dpr[i][j]+c[j][k]*((dpr[prv][j-k]*f[k-1]+dpf[prv][j-k]*rst[k-1])%md))%md;
        dpf[i][j]=(dpf[i][j]+c[j][k]*((dpf[prv][j-k]*f[k-1])%md))%md;
      }
    }
  }
  printf("%d\n",dpr[n][m]);
  return 0;
}
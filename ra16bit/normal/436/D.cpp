#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,w,best,a[100100],b[2010],f[100100],prv[100100],nxt[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  sort(a+1,a+n+1);
  sort(b,b+m);
  prv[1]=0; nxt[n]=n;
  for (i=2; i<=n; i++) if (a[i]==a[i-1]+1) prv[i]=prv[i-1]; else prv[i]=i-1;
  for (i=n-1; i>0; i--) if (a[i]==a[i+1]-1) nxt[i]=nxt[i+1]; else nxt[i]=i;
  for (i=1; i<=n; i++) {
    w=lower_bound(b,b+m,a[i])-b;
    best=f[i-1];
    for (j=w-1; j>=0; j--) {
      k=i-a[i]+b[j];
      if (k<1) break;
      best=max(best,f[prv[k]]+w-j);
    }
    f[i]=max(f[i],best);
    for (j=w; j<m; j++) {
      k=i+b[j]-a[i];
      if (k>n) break;
      f[nxt[k]]=max(f[nxt[k]],best+j-w+1);
    }
  }
  printf("%d\n",f[n]);
  return 0;
}
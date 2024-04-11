#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,y,i,j,k,r,a[100100],b[1000100],f[1000100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d%d",&x,&y);
  for (i=y+1; i<=x; i++) b[i-y]=i-y-1;
  sort(a,a+n);
  n=unique(a,a+n)-a;
  for (i=0; i<n; i++) for (j=(y/a[i])*a[i]; ; j+=a[i]) {
    k=min(x,j-1)-y;
	if (k>=0 && j-a[i]>=y) b[k]=min(b[k],j-a[i]-y);
	if (j>x) break;
  }
  for (i=x-y-1; i>=0; i--) b[i]=min(b[i],b[i+1]);
  for (i=1; i<=x-y; i++) f[i]=f[b[i]]+1;
  printf("%d\n",f[x-y]);
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,m,N,q,z,x[100100],y[100100],a[100100],b[100100],c[277277];
void modify(int i, int L, int R, int l, int r, int j) {
  if (L==l && R==r) {
    c[i]=j;
    return;
  }
  int h=(L+R)/2;
  if (l<=h) modify(i*2,L,h,l,min(h,r),j);
  if (r>h) modify(i*2+1,h+1,R,max(h+1,l),r,j);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) scanf("%d",&b[i]);
  for (N=1; N<n; N*=2);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&q,&x[i]);
	if (q==1) {
	  scanf("%d%d",&y[i],&z);
	  modify(1,1,N,y[i],y[i]+z-1,i);
	} else {
	  int j=1,l=1,r=N;
	  z=c[j];
	  while (l!=r) {
	    int h=(l+r)/2;
		j*=2;
		if (x[i]>h) {
		  l=h+1; j++;
		} else r=h;
		z=max(z,c[j]);
	  }
	  if (z==0) printf("%d\n",b[x[i]]); else printf("%d\n",a[x[i]-y[z]+x[z]]);
	}
  }
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,r,i,j,cur,res,za,zb,ca,cb,a[100100],b[100100],c[200200],d[200200];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
	if (i==0 || a[i]!=a[i-1]) ca++;
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d",&b[i]);
	if (i==0 || b[i]!=b[i-1]) cb++;
  }
  if (a[n-1]!=b[m-1]) {
    za=max(ca-1,cb)+a[n-1];
	zb=max(ca,cb-1)+b[m-1];
	if (za<zb) cur=a[n-1]; else cur=b[m-1];
	res=min(za,zb);
  } else {
    cur=a[n-1];
	res=max(ca,cb)-1+cur;
  }
  for (i=n-1, j=m-1; i>=0 || j>=0; cur^=1) {
    for (; i>=0 && a[i]==cur; i--) { d[r]=cur; c[r++]=i+1; }
	for (; j>=0 && b[j]==cur; j--) { d[r]=cur; c[r++]=n+j+1; }
  }
  for (i=r-1; i>=0; i--) printf("%d%c",c[i],i==0?'\n':' ');
  printf("%d\n",res);
  reverse(d,d+r);
  for (i=0; res--; ) {
    for (j=i; i<r && d[i]==d[j]; i++);
	printf("%d%c",i,res==0?'\n':' ');
  }
  return 0;
}
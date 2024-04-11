#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,a,b,c[31],d[31],cc[31],dd[31],tot,l,r,h,cur,res;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
	for (j=30; j>=0; j--) if (a>=(1<<j)) {
	  a-=1<<j;
	  c[j]++;
	}
  }
  for (i=0; i<m; i++) {
    scanf("%d",&b);
	if (b<31) d[b]++;
  }
  for (j=0; j<31; j++) { cc[j]=c[j]; dd[j]=d[j]; }
  l=0; r=m;
  while (l<r) {
    h=(l+r)/2+1;
	res=0; tot=h;
	for (j=0; j<31; j++) {
	  c[j]=cc[j];
	  d[j]=min(dd[j],tot);
	  tot-=d[j];
	}
    for (j=30; j>=0; j--) {
      c[j]=min(c[j],2000000);
      cur=min(c[j],d[j]);
	  res+=cur;
	  if (j>0) c[j-1]+=(c[j]-cur)*2;
    }
	if (res<h) r=h-1; else l=h;
  }
  printf("%d\n",r);
  return 0;
}
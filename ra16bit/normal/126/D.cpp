#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,k,t,a[92];
long long m,f[92],r[92][2];
int main() {
  f[1]=1; f[2]=2;
  for (i=3; ; i++) {
    f[i]=f[i-1]+f[i-2];
	if (f[i]>1e18) break;
  }
  n=i;
  scanf("%d",&t);
  while (t--) {
    scanf("%I64d",&m); k=0;
	for (i=n; i>0; i--) if (m>=f[i]) { a[k++]=i; m-=f[i]; }
	reverse(a,a+k);
	r[i][0]=1;
	r[i][1]=a[i]<3?0:((a[i]-1)/2);
	for (i=1; i<k; i++) {
	  r[i][0]=r[i-1][0]+r[i-1][1]; r[i][1]=0;
	  if (a[i-1]<a[i]-2) r[i][1]+=((a[i]-a[i-1]-1)/2)*r[i-1][0];
	  if (a[i-1]<a[i]-1) r[i][1]+=((a[i]-a[i-1])/2)*r[i-1][1];
	}
	//for (i=0; i<k; i++) printf("%d: [%I64d] (%d) = %I64d %I64d\n",i,f[a[i]],a[i],r[i][0],r[i][1]);
	printf("%I64d\n",r[k-1][0]+r[k-1][1]);
  }
  return 0;
}
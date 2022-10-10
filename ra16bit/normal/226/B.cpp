#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,x,n,m,a[100100];
long long cur,d,r,s[100100],sv[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  reverse(a,a+n);
  for (i=0; i<n; i++) s[i+1]=s[i]+a[i];
  scanf("%d",&m);
  while (m--) {
    scanf("%d",&x);
	if (sv[x]==0) {
	  for (r=i=j=0, cur=1; i<n; j++) {
	    d=min(cur,(long long)(n-i));
	    cur*=x;
	    r+=j*(s[i+d]-s[i]);
	    i+=d;
	  }
	  sv[x]=r;
	}
	printf("%I64d",sv[x]);
	if (m==0) putchar('\n'); else putchar(' ');
  }
  return 0;
}
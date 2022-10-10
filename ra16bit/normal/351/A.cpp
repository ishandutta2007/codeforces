#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,x,cnt,a[4040];
long long s[4040],r;
int main() {
  scanf("%d",&n);
  for (i=0; i<2*n; i++) {
    scanf("%d.%d",&x,&a[i]);
	if (a[i]==0) cnt++;
  }
  if (cnt==2*n) { puts("0.000"); return 0; }
  sort(a,a+2*n);
  for (i=0; i<2*n; i++) s[i+1]=s[i]+a[i];
  for (i=n; i<=2*n && i<=n+cnt; i++)
    if (i==n || abs(s[2*n]-(2*n-i)*1000)<r)
	  r=abs(s[2*n]-(2*n-i)*1000);
  printf("%I64d.%03I64d\n",r/1000,r%1000);
  return 0;
}
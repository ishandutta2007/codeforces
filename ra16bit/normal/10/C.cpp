#include <cstdio>
#include <algorithm>
using namespace std;
int n,d[1100000],i,j,ii;
long long c[15],r;
int main() {
  scanf("%d",&n);
  for (i=1; i<=9; i++) {
	  d[i]=i;
	  if (i<=n) c[i]++;
  }
  for (i=10; i<=max(105,n); i++) {
    for (ii=i; ii>0; ii/=10) d[i]+=ii%10;
    d[i]=d[d[i]];
	if (i<=n) c[d[i]]++;
  }
  for (i=1; i<10; i++) for (j=1; j<10; j++) r+=c[i]*c[j]*c[d[i*j]];
  for (i=1; i<=n; i++) for (j=1; i*j<=n; j++) if (d[d[i]*d[j]]==d[i*j]) r--;
  printf("%I64d\n",r);
  return 0;
}
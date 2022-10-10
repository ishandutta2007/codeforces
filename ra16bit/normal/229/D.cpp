#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,p,x,n,r,a[5005],s[5005],f[5005][5005];
int main() {
  scanf("%d",&n); r=n-1;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
	s[i]=s[i-1]+a[i];
	f[i][1]=i-1;
	for (j=2; j<=i; j++) f[i][j]=n;
  }
  for (i=1; i<=n; i++) for (p=i+1, j=i; j>=1; j--) {
    if (i>j) f[i][j]=min(f[i][j],f[i-1][j]+1);
	if (i<n) {
      x=s[i]-s[j-1];
      for (; p<=n && s[p]-s[i]<x; p++);
	  if (p<=n) f[p][i+1]=min(f[p][i+1],f[i][j]+p-i-1);
	} else r=min(r,f[i][j]);
  }
  printf("%d\n",r);
  return 0;
}
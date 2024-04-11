#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=2020;
int n,i,j,c,a[MX],b[MX],z[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
	b[i]=abs(a[i]);
	z[i]=b[i];
  }
  sort(b,b+n);
  for (i=0; i<n; i++) if (i==0 || b[i]!=b[i-1]) {
    for (c=j=0; j<n; j++) if (z[j]<b[i]) c++; else if (z[j]==b[i]) {
	  if (c<i-c) a[j]=-z[j]; else a[j]=z[j];
	}
  }
  for (c=i=0; i<n; i++) for (j=0; j<i; j++) if (a[j]>a[i]) c++;
  printf("%d\n",c);
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,prev,a[2000100];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) a[i]=i;
  for (k=2; k<=n; k++) {
    for (i=0; i<n; i+=k) {
	  j=a[i+k-1];
	  //printf("->%d\n",j);
	  a[i+k-1]=prev;
	  prev=j;
	}
	a[n+k-1]=prev;
	//for (i=0; i<n; i++) printf("%d%c",a[i+k],(i==n-1)?'\n':' ');
  }
  for (i=0; i<n; i++) printf("%d%c",a[i+n],(i==n-1)?'\n':' ');
  return 0;
}
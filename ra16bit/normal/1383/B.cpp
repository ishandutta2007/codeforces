#include <bits/stdc++.h>
using namespace std;
int t,n,x,i,j,w,cnt,a[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
	for (x=i=0; i<n; i++) {
	  scanf("%d",&a[i]);
	  x^=a[i];
	}
	for (w=-1, j=0; j<=30; j++) if ((x>>j)&1) w=j;
	if (w<0) { puts("DRAW"); continue; }
	for (cnt=i=0; i<n; i++) if ((a[i]>>w)&1) ++cnt;
	if (((n-cnt)&1)==0) {
	  if (cnt%4==1) puts("WIN"); else puts("LOSE");
	} else puts("WIN");
  }
  return 0;
}
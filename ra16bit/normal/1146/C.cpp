#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,cnt,r,x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
	for (r=i=0; i<9; i++) {
	  cnt=0;
	  for (j=1; j<=n; j++) if ((j>>i)&1) cnt++;
	  if (cnt==0 || cnt==n) continue;
	  printf("%d %d",cnt,n-cnt);
	  for (j=1; j<=n; j++) if ((j>>i)&1) printf(" %d",j);
	  for (j=1; j<=n; j++) if (!((j>>i)&1)) printf(" %d",j);
	  puts("");
	  fflush(stdout);
	  scanf("%d",&x);
	  r=max(r,x);
	}
    printf("-1 %d\n",r);
	fflush(stdout);
  }
  return 0;	
}
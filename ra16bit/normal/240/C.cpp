#include <stdio.h>
int n,m,r,i,c,a[1111],b[8765];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n); m=n;
  for (r=0; m>1; r++) m=m-m/2;
  printf("%d\n",r); m=n;
  for (i=1; i<=n; i++) a[i]=1;
  while (r--) {
    m=m-m/2; c=0;
	for (i=1; i<=n; i++) {
	  a[i]*=2;
	  if (b[a[i]]==m) a[i]++;
	  b[a[i]]++;
	  if (a[i]&1) c++;
	}
	printf("%d",c);
	for (i=1; i<=n; i++) if (a[i]&1) printf(" %d",i);
	puts("");
  }
  return 0;
}
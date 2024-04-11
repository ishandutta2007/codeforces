#include <stdio.h>
int n,i,j,a,b,r,x[111],y[111],p[111];
bool u[111];
int findset(int x) {
  if (x!=p[x]) p[x]=findset(p[x]);
  return p[x];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
	p[i]=i;
	for (j=0; j<n; j++) if (x[i]==x[j] || y[i]==y[j]) {
	  a=findset(i);
	  b=findset(j);
	  if (a!=b) p[a]=b;
	}
  }
  for (i=0; i<n; i++) u[findset(i)]=true;
  for (i=0; i<n; i++) if (u[i]) r++;
  printf("%d\n",r-1);
  return 0;
}
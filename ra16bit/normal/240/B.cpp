#include <cstdio>
#include <algorithm>
using namespace std;
int n,a,b,i,j,k,r,h[202],s[202],f[202][40004][2];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d%d",&n,&a,&b);
  for (i=0; i<n; i++) {
    scanf("%d",&h[i]);
	s[i+1]=s[i]+h[i];
  }
  f[0][0][0]=1;
  f[0][0][1]=1;
  for (i=0; i<=n; i++) for (j=0; j<=a; j++) if (s[i]-j<=b) for (k=0; k<2; k++) if (f[i][j][k]>0) {
    if (j+h[i]<=a) {
      int& x=f[i+1][j+h[i]][0];
	  int y=f[i][j][k]+int(k==1 && i>0)*min(h[i],h[i-1]);
	  if (x==0 || x>y) x=y;
	}
	if (s[i]-j+h[i]<=b) {
      int& x=f[i+1][j][1];
	  int y=f[i][j][k]+int(k==0 && i>0)*min(h[i],h[i-1]);
	  if (x==0 || x>y) x=y;
	}
  }
  r=1000000000;
  for (j=0; j<=a; j++) if (s[n]-j<=b) for (k=0; k<2; k++) if (f[i][j][k]>0) r=min(r,f[i][j][k]);
  if (r==1000000000) puts("-1"); else printf("%d\n",r-1);
  return 0;
}
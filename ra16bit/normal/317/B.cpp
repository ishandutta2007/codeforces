#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int i,j,k,t,z,n,nx,mx,x,y,ll[202],rr[202],f[202][202],g[202][202];
void solve2() {
  bool q=true;
  while (q) {
    q=false;
	for (i=nx; i<=mx; i++) for (j=ll[i]; j<=rr[i]; j++) if (f[i][j]>=4) {
	  if (i==nx) nx--;
	  if (i==mx) mx++;
	  q=true;
	  z=f[i][j]/4;
	  for (k=0; k<4; k++) {
	    x=i+dx[k];
		y=j+dy[k];
		ll[x]=min(ll[x],y);
		rr[x]=max(rr[x],y);
	    f[x][y]+=z;
	  }
	  f[i][j]&=3;
	}
  }
}
int main() {
  scanf("%d",&n);
  f[100][100]=n;
  nx=mx=100;
  ll[100]=rr[100]=100;
  for (i=0; i<=200; i++) if (i!=100) { ll[i]=200; rr[i]=0; }
  solve2();
  //int le=95,ri=105;
  //for (i=le; i<=ri; i++,puts("")) for (j=le;j<=ri; j++) printf("%d ",f[i][j]);
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&x,&y);
	x+=100; y+=100;
	if (x>=0 && x<=200 && y>=0 && y<=200) printf("%d\n",f[x][y]); else puts("0");
  }
  return 0;
}
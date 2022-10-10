#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,xx,yy,k[100100];
double x[100100],y[100100],amx[100100],amn[100100],bmx[100100],bmn[100100],mn,mx,l,r,h,ch,rh,eps=1e-6;
bool cmp(int i, int j) {
  return x[i]<x[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&xx,&yy);
	x[i]=xx+yy;
	y[i]=xx-yy;
	k[i]=i;
  }
  sort(k,k+n,cmp);
  amn[0]=amx[0]=y[k[0]];
  i=0;
  for (i=1; i<n; i++) {
    amn[i]=min(amn[i-1],y[k[i]]);
	amx[i]=max(amx[i-1],y[k[i]]);
  }
  bmn[n-1]=bmx[n-1]=y[k[n-1]]; i=n-1;
  for (i=n-2; i>=0; i--) {
    bmn[i]=min(bmn[i+1],y[k[i]]);
	bmx[i]=max(bmx[i+1],y[k[i]]);
  }
  l=0; r=3e9;
  for (int it=0; it<60; it++) {
    h=(l+r)*0.5; rh=5e10;
	for (i=j=0; i<n; i++) {
	  for (; j<n; j++) if (x[k[j]]-x[k[i]]>h) break;
	  ch=h;
	  if (i>0) {
	    mn=amn[i-1];
		mx=amx[i-1];
	    if (j<n) {
		  mn=min(mn,bmn[j]);
		  mx=max(mx,bmx[j]);
		}
		ch=max(ch,mx-mn);
	  } else if (j<n) ch=max(ch,bmx[j]-bmn[j]);
	  rh=min(rh,ch);
	}
	if (rh>h+eps) l=h; else r=h;
  }
  printf("%.8lf\n",0.25*(l+r));
  return 0;
}
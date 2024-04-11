#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
const int E=1000100;
int n,i,j,x[100100],y[100100],Cx[2*E],Cy[2*E],Dx[2*E],Dy[2*E];
double d,sqri,ddx,ddy,sqx,sqy,smx,smy,cntx,cnty,sum,eps=1e-9;
double sqr(double x) { return x*x; }
int main() {
  memset(Cx,120,sizeof(Cx));
  memset(Cy,120,sizeof(Cy));
  memset(Dx,140,sizeof(Dx));
  memset(Dy,140,sizeof(Dy));
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
	x[i]+=E;
	y[i]+=E;
  }
  x[n]=x[0]; y[n]=y[0];
  for (i=0; i<n; i++) {
    double A=y[i+1]-y[i];
	double B=x[i]-x[i+1];
	double C=-A*x[i]-B*y[i];
	int cx=min(x[i],x[i+1]),dx=max(x[i],x[i+1]);
	int cy=min(y[i],y[i+1]),dy=max(y[i],y[i+1]);
	if (x[i]==x[i+1]) {
	  Cy[x[i]]=min(Cy[x[i]],cy);
	  Dy[x[i]]=max(Dy[x[i]],dy);
	} else for (j=cx; j<=dx; j++) {
	  d=(-A*j-C)/B;
	  Cy[j]=min(Cy[j],int(d-eps)+1);
	  Dy[j]=max(Dy[j],int(d+eps));
	}
	if (y[i]==y[i+1]) {
	  Cx[y[i]]=min(Cx[y[i]],cx);
	  Dx[y[i]]=max(Dx[y[i]],dx);
	} else for (j=cy; j<=dy; j++) {
	  d=(-B*j-C)/A;
	  Cx[j]=min(Cx[j],int(d-eps)+1);
	  Dx[j]=max(Dx[j],int(d+eps));
	}
  }
  for (i=0; i<2*E; i++) {
    sqri=sqr(i);
	if (Dx[i]>=Cx[i]) {
	  ddx=Dx[i]-Cx[i]+1;
	  sum+=ddx*(sqx-2*smx*i+cntx*sqri);
	  sqx+=sqri*ddx;
	  smx+=i*ddx;
	  cntx+=ddx;
	}
    if (Dy[i]>=Cy[i]) {
	  ddy=Dy[i]-Cy[i]+1;
	  sum+=ddy*(sqy-2*smy*i+cnty*sqri);
	  sqy+=sqri*ddy;
	  smy+=i*ddy;
	  cnty+=ddy;
	}
  }
  printf("%.10lf\n",sum/cntx/(cntx-1.));
  return 0;
}
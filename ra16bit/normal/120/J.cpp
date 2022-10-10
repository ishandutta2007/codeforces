#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4]={1,-1,1,-1};
const int dy[4]={1,1,-1,-1};
struct thr { double x,y; int z; } a[400040];
int n,ri,rj,i,j,k,xx,yy,X,Y;
double r,xc,yc,eps=1e-8,phi=0.74301248;
bool cmp(thr a, thr b) { return a.x<b.x-eps || (fabs(a.x-b.x)<=eps && a.y<b.y); }
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&xx,&yy);
    for (k=0; k<4; k++) {
      X=xx*dx[k];
      Y=yy*dy[k];
      a[(i<<2)+k].x=cos(phi)*X-sin(phi)*Y;
      a[(i<<2)+k].y=sin(phi)*X+cos(phi)*Y;
      a[(i<<2)+k].z=(i<<2)+k;
    }
  }
  n*=4; r=1e20;
  sort(a,a+n,cmp);
  for (i=0; i<n; i++) for (j=i; j<n; j++) if ((a[i].z>>2)!=(a[j].z>>2)) {
    xc=a[j].x-a[i].x;
    if (xc>r) break;
    yc=a[j].y-a[i].y;
    if (xc*xc+yc*yc<r) {
      r=xc*xc+yc*yc;
      ri=i; rj=j;
    }
  }
  printf("%d %d %d %d\n",(a[ri].z>>2)+1,(a[ri].z&3)+1,(a[rj].z>>2)+1,4-(a[rj].z&3));
  return 0;
}
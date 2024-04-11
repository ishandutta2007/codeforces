#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int i,j,k,n,x,y,xx,yy,nx,ny,mx,my,cnx,cny,cmx,cmy,sq,cir,fi,fr,a[2002][2002],qx[2002*2002],qy[2002*2002];
bool u[2002][2002];
long long vmx,vmy,vnx,vny;
int sqr(int x) { return x*x; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  for (i=0; i<n; i++) for (j=0; j<n; j++) if (a[i][j] && !u[i][j]) {
    nx=mx=vmy=vny=qx[0]=i;
    ny=my=vmx=vnx=qy[0]=j;
    cnx=cny=fr=1;
    u[i][j]=true;
    for (fi=0; fi<fr; fi++) {
      x=qx[fi];
      y=qy[fi];
      for (k=0; k<4; k++) {
        xx=x+dx[k];
        yy=y+dy[k];
        if (xx>=0 && xx<n && yy>=0 && yy<n && a[xx][yy] && !u[xx][yy]) {
          if (xx>mx) {
            mx=xx; vmx=yy; cmx=1;
          } else if (xx==mx) { vmx+=yy; cmx++; }
          if (xx<nx) {
            nx=xx; vnx=yy; cnx=1;
          } else if (xx==nx) { vnx+=yy; cnx++; }
          if (yy>my) {
            my=yy; vmy=xx; cmy=1;
          } else if (yy==my) { vmy+=xx; cmy++; }
          if (yy<ny) {
            ny=yy; vny=xx; cny=1;
          } else if (yy==ny) { vny+=xx; cny++; }
          u[xx][yy]=true; qx[fr]=xx; qy[fr++]=yy;
        }
      }
    }
    if (fr>14) {
      if (vmx*cnx==vnx*cmx && vmy*cny==vny*cmy) {
        if (fr==(mx-nx+1)*(my-ny+1) || fr<=1.1*(sqr((mx-nx)/2+1)+sqr((my-ny)/2))) sq++; else cir++;
      } else sq++;
    }
  }
  printf("%d %d\n",cir,sq);
  return 0;
}
#include <cmath>
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
  srand(43);
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
        if (xx>=0 && xx<n && yy>=0 && yy<n && ((a[xx][yy] && rand()%100>=20) || (a[xx][yy]==0 && rand()%100<20)) && !u[xx][yy]) {
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
    if (fr>110) {
    //printf("%d %d %d | %d %d  | %d %.2lf\n",fr,i,j,mx-nx+1,my-ny+1,(mx-nx+1)*(my-ny+1),3.14*(mx-nx+1)*(my-ny+1)/4);
    //printf("%.5lf %.5lf\n",(fr/0.8)/(3.14*(mx-nx+1)*(my-ny+1)/4.0),(fr/0.8)/((mx-nx+1)*(my-ny+1)));
    int rx,ry,rr,r1=0,r2=0,r3=0,r4=0,ro1=0,ro2=0,ro3=0,ro4=0,tot=0;
    rx=(mx+nx)/2;
    ry=(my+ny+1)/2;
    //printf("%d %d\n",rx,ry);
    rr=sqr(mx-nx+my-ny-2)/16;
    //printf("%d %d %d\n",mx-nx,my-ny,rr);
    for (int i=nx+1; i<mx; i++) if (sqr(i-rx)<=rr) tot+=2*(sqrt(rr-sqr(i-rx))+0.5)+1;
    for (fi=0; fi<fr; fi++) if (sqr(qx[fi]-rx)+sqr(qy[fi]-ry)<=rr) {
      if (qx[fi]<=rx) {
        if (qy[fi]<ry) r1++; else r2++;
      } else {
        if (qy[fi]<=ry) r3++; else r4++;
      }
    } else if (qx[fi]<=rx) {
      if (qy[fi]<ry) ro1++; else ro2++;
    } else {
      if (qy[fi]<=ry) ro3++; else ro4++;
    }
    double is=double(tot-r1-r2-r3-r4)/double(tot);
    double os=double(ro1+ro2+ro3+ro4)/double(tot);
    //printf("%.2lf %.2lf\n",is,os);
    if (is<0.27 && os<0.04) cir++; else sq++;
    }
  }
  printf("%d %d\n",cir,sq);
  return 0;
}
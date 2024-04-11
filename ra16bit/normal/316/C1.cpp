#include <cstdio>
#include <memory.h>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const int MX=82*82*2;
int n,m,i,j,k,x,y,z,nx,ny,lx,ly,it,fi,fr,r,res,inf,a[82][82],bx[82][82],by[82][82],u[82][82],p[82][82],frx[82][82],fry[82][82],qx[MX*2],qy[MX*2];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[i][j]);
  memset(bx,255,sizeof(bx));
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (((i+j)&1)==0) for (k=0; k<4; k++) {
    x=i+dx[k];
	y=j+dy[k];
	if (x>=0 && y>=0 && x<n && y<m && a[i][j]==a[x][y]) {
	  bx[i][j]=x; by[i][j]=y;
	  bx[x][y]=i; by[x][y]=j;
	  //printf("%d %d - %d %d | 0\n",i,j,x,y);
	  break;
	}
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (((i+j)&1)==0 && bx[i][j]==-1) for (k=0; k<4; k++) {
    x=i+dx[k];
	y=j+dy[k];
	if (x>=0 && y>=0 && x<n && y<m && bx[x][y]==-1) {
	  bx[i][j]=x; by[i][j]=y;
	  bx[x][y]=i; by[x][y]=j;
	  r++;
	  //printf("%d %d - %d %d\n",i,j,x,y);
	  break;
	}
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) if (((i+j)&1)==0 && bx[i][j]==-1) {
    fi=MX; fr=fi+1; qx[fi]=i; qy[fi]=j;
	memset(p,120,sizeof(p));
	res=inf=p[0][0];
	p[i][j]=0; ++it;
    while (fi<fr) {
	  int i=qx[fi],j=qy[fi];
	  fi++;
	  if (u[i][j]==it) continue;
	  u[i][j]=it;
      for (k=0; k<4; k++) {
        x=i+dx[k];
	    y=j+dy[k];
	    if (x>=0 && y>=0 && x<n && y<m) {
		  if (bx[x][y]==-1) {
		    z=int(a[i][j]!=a[x][y])+p[i][j];
		    if (z<res) {
			  res=z;
			  lx=x; ly=y;
			  frx[x][y]=i;
			  fry[x][y]=j;
			}
		  } else {
		    nx=bx[x][y];
			ny=by[x][y];
			z=int(a[i][j]!=a[x][y])-int(a[nx][ny]!=a[x][y])+p[i][j];
		    if (z<p[nx][ny]) {
			  p[nx][ny]=z;
			  frx[nx][ny]=x; fry[nx][ny]=y;
			  frx[x][y]=i;   fry[x][y]=j;
			  if (z<=p[i][j]) {
			    qx[--fi]=nx; qy[fi]=ny;
			  } else {
			    qx[fr]=nx; qy[fr++]=ny;
			  }
		    }
		  }
	    }
      }
	}
	if (res<inf) {
	  r+=res;
	  for (; lx!=i || ly!=j; lx=x, ly=y) {
	    if (((lx+ly)&1)==0) {
		  bx[lx][ly]=nx;
		  by[lx][ly]=ny;
		}
	    nx=lx; ny=ly;
	    x=frx[lx][ly];
		y=fry[lx][ly];
		if ((lx+ly)&1) {
		  bx[lx][ly]=x;
		  by[lx][ly]=y;
		}
	  }
	} else printf("%d\n",lx/0);
  }
  //for (i=0; i<n; i++) for (j=0; j<m; j++) printf("(%d %d)%c",bx[i][j],by[i][j],(j+1==m)?'\n':' ');
  printf("%d\n",r);
  return 0;
}
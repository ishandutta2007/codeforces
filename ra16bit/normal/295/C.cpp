#include <stdio.h>
#include <memory.h>
const int md=1000000007;
int n,m,x,y,z,i,j,k,c[5],f[55][55][2],r[55][55][2];
long long C[55][55],cnt;
bool a[55][55][2];
int main() {
  for (i=0; i<=50; i++) {
    C[i][0]=1;
	for (j=1; j<=50; j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%md;
  }
  scanf("%d%d",&n,&m);
  m/=50;
  for (i=0; i<n; i++) {
    scanf("%d",&x);
	c[x/50]++;
  }
  memset(f,120,sizeof(f));
  a[0][0][0]=true;
  f[0][0][0]=0;
  r[0][0][0]=1;
  while (true) {
    x=-1;
    for (i=0; i<=c[1]; i++) for (j=0; j<=c[2]; j++) for (k=0; k<2; k++)
	  if (a[i][j][k] && (x==-1 || f[i][j][k]<f[x][y][z])) {
	    x=i; y=j; z=k;
	  }
	if (x==-1) break;
	if (x==c[1] && y==c[2] && z==1) {
	  printf("%d\n%d\n",f[x][y][z],r[x][y][z]);
	  return 0;
	}
	a[x][y][z]=false;
	if (z==0) {
	  int cx=c[1]-x,cy=c[2]-y;
	  for (i=0; i<=cx; i++) for (j=0; j<=cy; j++) if (i+j>0 && i+j*2<=m && f[x][y][z]+1<=f[x+i][y+j][1-z]) {
	    if (f[x][y][z]+1<f[x+i][y+j][1-z]) {
		  f[x+i][y+j][1-z]=f[x][y][z]+1;
		  r[x+i][y+j][1-z]=0;
		}
		cnt=(C[cx][i]*C[cy][j])%md;
		r[x+i][y+j][1-z]=(r[x+i][y+j][1-z]+cnt*r[x][y][z])%md;
		a[x+i][y+j][1-z]=true;
	  }
	} else {
	  for (i=0; i<=x; i++) for (j=0; j<=y; j++) if (i+j>0 && i+j*2<=m && f[x][y][z]+1<=f[x-i][y-j][1-z]) {
	    if (f[x][y][z]+1<f[x-i][y-j][1-z]) {
		  f[x-i][y-j][1-z]=f[x][y][z]+1;
		  r[x-i][y-j][1-z]=0;
		}
		cnt=(C[x][i]*C[y][j])%md;
		r[x-i][y-j][1-z]=(r[x-i][y-j][1-z]+cnt*r[x][y][z])%md;
		a[x-i][y-j][1-z]=true;
	  }
	}
  }
  puts("-1\n0");
  return 0;
}
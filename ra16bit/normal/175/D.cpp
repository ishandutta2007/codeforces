#include <cstdio>
#include <algorithm>
using namespace std;
int i,j,k,x,y,m,n[2],d[2],l[2],r[2],p[2],a[65],b[65];
double f[202][202][65],sx[202][202][65],sy[202][202][65];
bool u[202][202][65];
double F(int x, int y, int z) {
  if (y<=0) return 1.0;
  if (x<=0) return 0.0;
  if (u[x][y][z]) return f[x][y][z];
  u[x][y][z]=true;
  int i,j,k,mom=z;
  double cur=1.0,dd;
  if (z<m-1) {
    i=b[mom];
    mom=(mom+1)%m;
    dd=0.01*(100-p[i])/(r[i]-l[i]+1.0);
    if (i) {
      if (x>l[i]) f[x][y][z]+=(sx[x-l[i]][y][mom]-sx[max(0,x-r[i]-1)][y][mom])*dd;
      //for (k=l[i]; k<=r[i]; k++) f[x][y][z]+=F(x-k,y,mom)*dd;
    } else {
      //for (k=l[i]; k<=r[i]; k++) f[x][y][z]+=F(x,y-k,mom)*dd;
      if (y>l[i]) f[x][y][z]+=(sy[x][y-l[i]][mom]-sy[x][max(0,y-r[i]-1)][mom])*dd;
      if (y<=r[i]) f[x][y][z]+=min(r[i]-l[i]+1,r[i]-y+1)*dd;
    }
    f[x][y][z]+=0.01*p[i]*F(x,y,z+1);
    //printf("%d %d %d = %.5lf\n",x,y,z,f[x][y][z]);
    return f[x][y][z];
  }
  for (j=0; j<m; j++) if (cur>0) {
    i=b[mom];
    mom=(mom+1)%m;
    dd=0.01*(100-p[i])*cur/(r[i]-l[i]+1.0);
    //for (k=l[i]; k<=r[i]; k++) f[x][y][z]+=F(x-k*i,y-k*(1-i),mom)*dd;
    if (i) {
      if (x>l[i]) f[x][y][z]+=(sx[x-l[i]][y][mom]-sx[max(0,x-r[i]-1)][y][mom])*dd;
      //for (k=l[i]; k<=r[i]; k++) f[x][y][z]+=F(x-k,y,mom)*dd;
    } else {
      //for (k=l[i]; k<=r[i]; k++) f[x][y][z]+=F(x,y-k,mom)*dd;
      if (y>l[i]) f[x][y][z]+=(sy[x][y-l[i]][mom]-sy[x][max(0,y-r[i]-1)][mom])*dd;
      if (y<=r[i]) f[x][y][z]+=min(r[i]-l[i]+1,r[i]-y+1)*dd;
    }
    cur*=0.01*p[i];
  }
  if (cur>0) f[x][y][z]/=1.0-cur;
  //printf("%d %d %d = %.5lf\n",x,y,z,f[x][y][z]);
  return f[x][y][z];
}
int main() {
  for (i=0; i<2; i++) scanf("%d%d%d%d%d",&n[i],&d[i],&l[i],&r[i],&p[i]);
  a[0]=0; b[0]=0;
  a[1]=0; b[1]=1;
  for (m=2,x=d[0],y=d[1]; x!=y; m++) if (x<y) {
    a[m]=x; b[m]=0; x+=d[0];
  } else {
    a[m]=y; b[m]=1; y+=d[1];
  }
  for (i=1; i<=n[0]; i++) for (j=1; j<=n[1]; j++) {
    F(i,j,0);
    for (k=0; k<m; k++) sx[i][j][k]=sx[i-1][j][k]+f[i][j][k];
    for (k=0; k<m; k++) sy[i][j][k]=sy[i][j-1][k]+f[i][j][k];
  }
  printf("%.7lf\n",F(n[0],n[1],0));
  return 0;
}
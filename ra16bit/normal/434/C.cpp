#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
const int md=1000000007;
int n,m,k,i,j,num,x,y,fi,fr,q[202],p[202],a[202],b[202][22],f[202][3][202][502];
vector<int> l,r;
int solve(const vector<int>& v, int mj) {
  int r=0;
  f[0][1][0][0]=1;
  for (int i=0; i<=v.size(); i++) for (int j=0; j<3; j++) for (int k=0; k<=num; k++) for (int z=0; z<=n; z++) if (f[i][j][k][z]) {
    if (i<v.size()) {
      r=(r+f[i][j][k][z])%md;
      for (int e=int(i==0); e<m; e++) {
        int nj=j,nk=b[k][e];
        if (j==1 && e!=v[i]) {
          if (e<v[i]) nj=0; else nj=2;
        }
        if (z+a[nk]<=n) f[i+1][nj][nk][z+a[nk]]=(f[i+1][nj][nk][z+a[nk]]+f[i][j][k][z])%md;
      }
    } else if (j<=mj) r=(r+f[i][j][k][z])%md;
    f[i][j][k][z]=0;
  }
  return r;
}
int main() {
  scanf("%d%d%d",&k,&m,&n);
  scanf("%d",&x);
  while (x--) { scanf("%d",&y); l.push_back(y); }
  scanf("%d",&x);
  while (x--) { scanf("%d",&y); r.push_back(y); }
  while (k--) {
    scanf("%d",&x);
    for (i=0; x--; ) {
      scanf("%d",&y);
      if (b[i][y]==0) b[i][y]=++num;
      i=b[i][y];
    }
    scanf("%d",&x);
    a[i]+=x;
  }
  q[0]=fi=0; fr=1;
  while (fi<fr) {
    i=q[fi++];
    a[i]+=a[p[i]];
    for (j=0; j<m; j++) if (b[i][j]) {
      q[fr++]=b[i][j];
      if (i) p[b[i][j]]=b[p[i]][j];
    } else if (i) b[i][j]=b[p[i]][j];
  }
  printf("%d\n",(solve(r,1)+md-solve(l,0))%md);
  return 0;
}
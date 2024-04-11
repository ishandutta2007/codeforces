#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n,m,N,d,e,i,j,x,y,z,Z,fi,fr=1,a[302][302],b[302][302],c[190909],qx[190909],qy[190909],p[190909],s[190909],w[777][777];
bool u[190909];
map <int, int> M,E;
vector <int> vx[190909],vy[190909],vz[190909];
long long r;
bool cmp(int i, int j) { return w[vx[z][i]+302-x][vy[z][i]+302-y]<w[vx[z][j]+302-x][vy[z][j]+302-y]; }
int findset(int x) {
  if (p[x]!=x) p[x]=findset(p[x]);
  return p[x];
}
int main() {
  i=j=302; w[i][j]=N=1; d=0; e=1;
  while (true) {
    i+=dx[d]; j+=dy[d];
    if (i<2 || j<2 || i>770 || j>770) break;
    w[i][j]=++N;
    if (w[i+dx[e]][j+dy[e]]==0) {
      d=e; e=(e+1)&3;
    }
  }
  scanf("%d%d",&n,&m); M[0]=N=0;
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    if (!M.count(a[i][j])) { M[a[i][j]]=e=++N; p[N]=N; c[N]=a[i][j]; } else e=M[a[i][j]];
    s[e]++;
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&b[i][j]);
    if (b[i][j]==-1) continue;
    e=M[a[i][j]];
    vx[e].push_back(i);
    vy[e].push_back(j);
    vz[e].push_back(vz[e].size());
    if (!M.count(b[i][j])) { M[b[i][j]]=++N; p[N]=N; c[N]=b[i][j]; }
  }
  E=M;
  scanf("%d%d",&qx[0],&qy[0]); qx[0]--; qy[0]--;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi++];
    z=findset(M[a[x][y]]);
    Z=E[b[x][y]];
    if (Z==-1) { E[b[x][y]]=Z=++N; p[N]=N; c[N]=b[x][y]; }
    if (z==0 || z==Z) continue;
    r+=s[z]; s[Z]+=s[z]; p[z]=Z; E[c[z]]=-1;
    if (u[z] || vz[z].size()==0) continue; else u[z]=true;
    sort(vz[z].begin(),vz[z].end(),cmp);
    for (i=0; i<vz[z].size(); i++, fr++) {
      qx[fr]=vx[z][vz[z][i]];
      qy[fr]=vy[z][vz[z][i]];
      if (qx[fr]==x && qy[fr]==y) fr--;
    }
  }
  printf("%I64d\n",r);
  return 0;
}
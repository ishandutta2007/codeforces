#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char ds[4]={'R','U','L','D'};
int n,i,k,X[1010],Y[1010],Z[1010],x,y,z,nx,ny,fi,fr,qx[3030*3030],qy[3030*3030];
char s[3];
vector <int> allx,ally;
bool u[3030][3030];
long long xc,yc,res;
int main() {
  scanf("%d",&n);
  allx.push_back(x-1); allx.push_back(x); allx.push_back(x+1);
  ally.push_back(y-1); ally.push_back(y); ally.push_back(y+1);
  for (i=1; i<=n; i++) {
    scanf("%s",s);
    scanf("%d",&z);
    for (k=0; k<4; k++) if (ds[k]==s[0]) {
      x+=z*dx[k];
      y+=z*dy[k];
      Z[i]=k;
    }
    allx.push_back(x-1); allx.push_back(x); allx.push_back(x+1);
    ally.push_back(y-1); ally.push_back(y); ally.push_back(y+1);
    X[i]=x; Y[i]=y;
  }
  sort(allx.begin(),allx.end());
  res=allx.back()-allx[0]+1;
  allx.resize(unique(allx.begin(),allx.end())-allx.begin());
  sort(ally.begin(),ally.end());
  res*=ally.back()-ally[0]+1;
  ally.resize(unique(ally.begin(),ally.end())-ally.begin());
  for (i=0; i<=n; i++) {
    X[i]=lower_bound(allx.begin(),allx.end(),X[i])-allx.begin();
    Y[i]=lower_bound(ally.begin(),ally.end(),Y[i])-ally.begin();
    if (i==0) continue;
    for (x=X[i-1], y=Y[i-1]; x!=X[i] || y!=Y[i]; x+=dx[Z[i]], y+=dy[Z[i]]) u[x][y]=true;
  }
  u[x][y]=true;
  u[0][0]=true;
  for (fr=1; fi!=fr; fi++) {
    x=qx[fi];
    y=qy[fi];
    if (x+1==allx.size()) xc=1; else xc=allx[x+1]-allx[x];
    if (y+1==ally.size()) yc=1; else yc=ally[y+1]-ally[y];
    res-=xc*yc;
    for (k=0; k<4; k++) {
      nx=x+dx[k];
      ny=y+dy[k];
      if (nx<0 || ny<0 || nx>=allx.size() || ny>=ally.size() || u[nx][ny]) continue;
      u[nx][ny]=true;
      qx[fr]=nx; qy[fr++]=ny;
    }
  }
  printf("%I64d\n",res);
  return 0;
}
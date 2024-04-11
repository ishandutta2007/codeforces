#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,m,et,zero,res,i,j,k,p,x[100100],y[100100],c[100100],d[100100],f[100100][2][2][2],bx[2];
long long r[100100][2];
vector<int> g[100100],e[100100],z[100100];
vector<pair<int,int> > b;
bool u[100100];
void solve() {
  for (int j=0; j<=k; j++) for (int fi=0; fi<2; fi++) for (int la=0; la<2; la++) for (int xr=0; xr<2; xr++) f[j][fi][la][xr]=0;
  f[0][0][0][0]=1;
  f[0][1][1][0]=1;
  for (int j=0; j<k; j++) for (int fi=0; fi<2; fi++) for (int la=0; la<2; la++) for (int xr=0; xr<2; xr++) if (f[j][fi][la][xr]) {
    int p=d[j+1];
    for (int ed=0; ed<2; ed++) {
      int curx=0;
      if (x[p]==c[j] && la==1) curx=1;
      if (x[p]==-c[j] && la==0) curx=1;
      if (x[p]==c[j+1] && ed==1) curx=1;
      if (x[p]==-c[j+1] && ed==0) curx=1;
      int cury=0;
      if (y[p]==c[j] && la==1) cury=1;
      if (y[p]==-c[j] && la==0) cury=1;
      if (y[p]==c[j+1] && ed==1) cury=1;
      if (y[p]==-c[j+1] && ed==0) cury=1;
      int nxr=(xr^(curx|cury));
      f[j+1][fi][ed][nxr]=(f[j+1][fi][ed][nxr]+f[j][fi][la][xr])%md;
    }
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d%d",&et,&x[i]);
    if (et==1) {
      z[abs(x[i])].push_back(i);
      continue;
    }
    scanf("%d",&y[i]);
    g[abs(x[i])].push_back(abs(y[i])); e[abs(x[i])].push_back(i);
    g[abs(y[i])].push_back(abs(x[i])); e[abs(y[i])].push_back(i);
  }
  for (i=1; i<=m; i++) if (!u[i]) {
    if (g[i].size()==0) {
      if (z[i].size()==1) {
        b.push_back(make_pair(1,1));
      } else if (z[i].size()==2) {
        b.push_back((x[z[i][0]]==-x[z[i][1]])?make_pair(0,2):make_pair(2,0));
      } else zero++;
      u[i]=true;
    } else if (g[i].size()==1) {
      c[0]=i; u[i]=true;
      for (j=g[i][0], p=e[i][0], k=1; ; k++) {
        u[j]=true; c[k]=j; d[k]=p;
        if (e[j].size()==1) break;
        if (e[j][0]==p) {
          p=e[j][1];
          j=g[j][1];
        } else {
          p=e[j][0];
          j=g[j][0];
        }
      }
      solve();
      for (int fi=0; fi<2; fi++) bx[fi]=0;
      for (int fi=0; fi<2; fi++) for (int la=0; la<2; la++) for (int xr=0; xr<2; xr++) if (f[k][fi][la][xr]) {
        int nxr=xr;
        if (z[c[0]].size()==1) {
          j=z[c[0]][0];
          if (x[j]==c[0] && fi==1) nxr^=1;
          if (x[j]==-c[0] && fi==0) nxr^=1;
        }
        if (z[c[k]].size()==1) {
          j=z[c[k]][0];
          if (x[j]==c[k] && la==1) nxr^=1;
          if (x[j]==-c[k] && la==0) nxr^=1;
        }
        bx[nxr]=(bx[nxr]+f[k][fi][la][xr])%md;
      }
      b.push_back(make_pair(bx[0],bx[1]));
    } else if (g[i].size()==2 && g[i][0]==i) {
      j=e[i][0];
      b.push_back((x[j]==-y[j])?make_pair(0,2):make_pair(1,1));
      u[i]=true;
    }
  }
  for (i=1; i<=m; i++) if (!u[i]) {
    c[0]=i; u[i]=true;
    for (j=g[i][0], p=e[i][0], k=1; ; k++) {
      u[j]=true; c[k]=j; d[k]=p;
      if (e[j][0]==p) {
        p=e[j][1];
        j=g[j][1];
      } else {
        p=e[j][0];
        j=g[j][0];
      }
      if (j==i) break;
    }
    solve();
    for (int fi=0; fi<2; fi++) bx[fi]=0;
    for (int fi=0; fi<2; fi++) for (int la=0; la<2; la++) for (int xr=0; xr<2; xr++) if (f[k][fi][la][xr]) {
      int nxr=xr;
      int curx=0;
      if (x[p]==c[k] && la==1) curx=1;
      if (x[p]==-c[k] && la==0) curx=1;
      if (x[p]==c[0] && fi==1) curx=1;
      if (x[p]==-c[0] && fi==0) curx=1;
      int cury=0;
      if (y[p]==c[k] && la==1) cury=1;
      if (y[p]==-c[k] && la==0) cury=1;
      if (y[p]==c[0] && fi==1) cury=1;
      if (y[p]==-c[0] && fi==0) cury=1;
      bx[xr^(curx|cury)]=(bx[xr^(curx|cury)]+f[k][fi][la][xr])%md;
    }
    b.push_back(make_pair(bx[0],bx[1]));
  }
  r[0][0]=1;
  for (i=0; i<b.size(); i++) for (j=0; j<2; j++) if (r[i][j]) {
    r[i+1][j]=(r[i+1][j]+r[i][j]*b[i].first)%md;
    r[i+1][j^1]=(r[i+1][j^1]+r[i][j]*b[i].second)%md;
  }
  //for (i=0; i<b.size(); i++) printf("%d %d\n",b[i].first,b[i].second);
  int res=r[b.size()][1];
  for (i=0; i<zero; i++) res=(res*2)%md;
  printf("%d\n",res);
  return 0;
}
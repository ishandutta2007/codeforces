#include <bits/stdc++.h>
using namespace std;
const int MX=400400,MXS=715,inf=2000000000;
int n,m,tot,x,y,z,stp,i,j,mm,fi,fr,q[MX],X[MX],Y[MX],Z[MX],k[MX],p[MX],rk[MX],dst[MX],act[MX],g[MXS][MXS];
vector<int> G[MX];//,f[MX];
long long r,res;
set<int> all;
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
bool un(int x, int y, int z) {
  if (x==y) return false;
  r+=z;
  if (rk[x]>=rk[y]) {
    p[y]=x;
    if (rk[x]==rk[y]) ++rk[x];
  } else p[x]=y;
  return true;
}
bool cmp(int i, int j) { return Z[i]<Z[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) p[i]=i;
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x,&y,&z);
    if (n<MXS-5) {
      g[x][y]=z;
      g[y][x]=z;
      tot^=z;
    }
    G[x].push_back(y);// f[x].push_back(z);
    G[y].push_back(x);// f[y].push_back(z);
    k[i]=i;
    X[i]=x;
    Y[i]=y;
    Z[i]=z;
  }
  if (n<MXS-5) {
    m=0;
    for (i=1; i<=n; i++) {
      for (j=i+1; j<=n; j++) {
        k[m]=m;
        X[m]=i;
        Y[m]=j;
        Z[m++]=g[i][j];
      }
    }
    sort(k,k+m,cmp);
    bool was=false;
    for (i=0; i<m && Z[k[i]]==0; i++) if (!un(fs(X[k[i]]),fs(Y[k[i]]),0)) was=true;
    stp=i;
    if (!was) {
      res=inf; res*=inf; mm=0;
      for (int ii=1; ii<=n; ii++) for (int jj=ii+1; jj<=n; jj++) if (g[ii][jj]==0) {
        mm++;
        g[ii][jj]=g[jj][ii]=tot;
        for (i=1; i<=n; i++) dst[i]=inf;
        assert(tot<inf);
        dst[1]=0;
        int cnt=r=0;
        while (true) {
          x=-1;
          for (i=1; i<=n; i++) if (act[i]!=mm && (x==-1 || dst[i]<dst[x])) x=i;
          if (x==-1) break;
          act[x]=mm;
          r+=dst[x];
          for (i=1; i<=n; i++) if (act[i]!=mm && g[x][i]<dst[i]) dst[i]=g[x][i];
          ++cnt;
        }
        assert(cnt==n);
        res=min(res,r);
        g[ii][jj]=g[jj][ii]=0;
      }
      printf("%lld\n",res);
    } else {
      for (i=stp; i<m; i++) un(fs(X[k[i]]),fs(Y[k[i]]),Z[k[i]]);
      printf("%lld\n",r);
    }
  } else {
    sort(k,k+m,cmp);
    for (i=1; i<=n; i++) {
      all.insert(i);
      sort(G[i].begin(),G[i].end());
    }
    for (i=1; i<=n; i++) {
      auto it=all.find(i);
      if (it==all.end()) continue;
      all.erase(it);
      q[0]=i; fi=0; fr=1;
      while (fi<fr) {
        x=q[fi++];
        j=0;
        for (it=all.begin(); it!=all.end(); ) {
          y=*it;
          for (; j<G[x].size() && G[x][j]<y; j++);
          if (j>=G[x].size() || G[x][j]!=y) {
            q[fr++]=y;
            un(fs(x),fs(y),0);
            it=all.erase(it);
          } else ++it;
        }
      }
    }
    for (r=i=0; i<m; i++) un(fs(X[k[i]]),fs(Y[k[i]]),Z[k[i]]);
    printf("%lld\n",r);
  }
  return 0;
}
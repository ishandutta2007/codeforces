#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int MX=1010,inf=1000000000;
int n,m,i,j,k,x,y,fi,fr,pt,num,cur,r,aa,a[MX],b[MX],q[MX],pv[MX],pe[MX],u[MX],fl[MX],f[MX],c[MX];
vector<int> g[MX],v[MX],e[MX];
set<int> s;
set<int>::iterator it;
void edge(int i, int j, int k) {
  e[i].push_back(num); v[i].push_back(j); f[num]=0; c[num++]=k;
  e[j].push_back(num); v[j].push_back(i); f[num]=0; c[num++]=0;
}
bool path() {
  fi=0; fr=1; q[0]=0;
  u[0]=++pt; fl[0]=inf;
  while (fi<fr) {
    int x=q[fi++];
    for (int j=0; j<v[x].size(); j++) {
      int y=v[x][j],z=e[x][j];
      if (u[y]!=pt && f[z]<c[z]) {
        pv[y]=x; pe[y]=z; u[y]=pt;
        fl[y]=min(fl[x],c[z]-f[z]);
        if (y==n+1) return true;
        q[fr++]=y;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]); aa=a[i];
    for (j=2; j*j<=aa; j++) if (aa%j==0) {
      s.insert(j);
      while (aa%j==0) aa/=j;
    }
    if (aa>1) s.insert(aa);
  }
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    if (y&1) swap(x,y);
    g[x].push_back(y);
  }
  for (it=s.begin(); it!=s.end(); it++) {
    cur=*it;
    num=0;
    v[0].clear(); v[n+1].clear();
    e[0].clear(); e[n+1].clear();
    for (i=1; i<=n; i++) {
      v[i].clear();
      e[i].clear();
      aa=a[i];
      for (b[i]=0; aa%cur==0; aa/=cur) b[i]++;
    }
    for (i=1; i<=n; i++) if (b[i]>0) {
      if (i&1) {
        edge(0,i,b[i]);
        for (j=0; j<g[i].size(); j++) {
          k=g[i][j];
          if (b[k]>0) edge(i,k,inf);
        }
      } else edge(i,n+1,b[i]);
    }
    while (path()) {
      aa=fl[n+1];
      r+=aa;
      for (i=n+1; i!=0; i=pv[i]) {
        f[pe[i]]+=aa;
        f[pe[i]^1]-=aa;
      }
    }
  }
  printf("%d\n",r);
  return 0;
}
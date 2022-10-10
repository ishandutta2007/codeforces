#include <cstdio>
#include <vector>
using namespace std;
const int MX=500005;
int n,m,mm,i,cur,x,y,up[MX],vp[MX],uw[MX],vw[MX],last[MX];
vector<int> u[MX],v[MX],ut[MX],o[MX];
vector<long long> us[MX];
long long cnt[MX],s;
char st[5];
int pu(int x) {
  if (x!=up[x]) up[x]=pu(up[x]);
  return up[x];
}
int pv(int x) {
  if (x!=vp[x]) vp[x]=pv(vp[x]);
  return vp[x];
}
void recalc(int i) {
  int x=vw[i];
  if (o[x].size()>0 && o[x].back()>last[i]) {
    last[i]=o[x].back();
    cnt[i]=0;
  }
  x=uw[i];
  if (ut[x].back()>last[i]) {
    int j=lower_bound(ut[x].begin(),ut[x].end(),last[i])-ut[x].begin();
    cnt[i]+=us[x].back()-us[x][max(0,j-1)];
  }
  last[i]=m;
}
int main() {
  scanf("%d%d",&n,&mm);
  for (i=1; i<=n; i++) {
    up[i]=vp[i]=uw[i]=vw[i]=i;
    ut[i].push_back(0);
    us[i].push_back(0);
    u[i].push_back(i);
    v[i].push_back(i);
  }
  for (m=1; m<=mm; m++) {
    scanf("%s",st);
    scanf("%d",&x);
    if (st[0]=='U') {
      scanf("%d",&y);
      x=pu(x); y=pu(y);
      if (u[x].size()<u[y].size()) swap(x,y);
      up[y]=x;
      for (i=0; i<u[y].size(); i++) {
        cur=u[y][i];
        recalc(cur);
        uw[cur]=x;
        u[x].push_back(cur);
      }
      u[y].clear();
    }
    if (st[0]=='M') {
      scanf("%d",&y);
      x=pv(x); y=pv(y);
      if (v[x].size()<v[y].size()) swap(x,y);
      vp[y]=x;
      for (i=0; i<v[y].size(); i++) {
        cur=v[y][i];
        recalc(cur);
        vw[cur]=x;
        v[x].push_back(cur);
      }
      v[y].clear();
    }
    if (st[0]=='A') {
      x=pu(x);
      s=us[x].back()+int(u[x].size());
      us[x].push_back(s);
      ut[x].push_back(m);
    }
    if (st[0]=='Z') {
      x=pv(x);
      o[x].push_back(m);
    }
    if (st[0]=='Q') {
      recalc(x);
      printf("%I64d\n",cnt[x]);
    }
  }
  return 0;
}
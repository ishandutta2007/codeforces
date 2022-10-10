#include <bits/stdc++.h>
using namespace std;
const int MX=1010,md=998244353;
int t,n,m,st,i,ii,i1,x,y,res,a[MX],f[2][MX];
vector<int> g[MX];
bool was,w[2][MX];
void upd(int i, int j, int x, int y) {
  if ((f[i][j]+=f[x][y])>=md) {
    f[i][j]-=md;
    w[i][j]=true;
  }
  if (w[x][y]) w[i][j]=true;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    set<int> s;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      g[i].clear();
      s.insert(i);
    }
    while (m--) {
      scanf("%d%d",&x,&y);
      g[y].push_back(x);
      s.erase(x);
    }
    st=*s.begin();
    res=a[st];
    was=false;
    if (res>=md) {
      res%=md;
      was=true;
    }
    for (x=1; x<=n; x++) {
      f[0][x]=int(x==st);
      w[0][x]=false;
    }
    for (i=0; i<n; i++) {
      ii=(i&1); i1=(ii^1);
      for (x=1; x<=n; x++) {
        f[i1][x]=0;
        w[i1][x]=false;
      }
      for (x=1; x<=n; x++) if (f[ii][x] || w[ii][x]) for (int nxt: g[x]) upd(i1,nxt,ii,x);
      for (x=1; x<=n; x++) if (a[x]>0 && (f[i1][x] || w[i1][x])) {
        if (was==false && res<i+1) res=i+1;
        long long cur=f[i1][x];
        bool curwas=w[i1][x];
        cur*=a[x];
        if (cur>=md) { cur%=md; curwas=true; }
        res+=cur;
        if (res>=md) {
          res-=md;
          was=true;
        }
        if (curwas) was=true;
      }
    }
    printf("%d\n",res);
  }
  return 0;
}
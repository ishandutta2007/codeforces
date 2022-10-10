#include <cstdio>
#include <vector>
using namespace std;
const int MX=100100,BS=314,BX=MX/BS+2;
int n,m,ii,tt,i,j,t,l,r,x,b,lb,lp,rb,rp,old,cur,res,a[MX],s[MX][BX],u[MX][BX];
vector<int> v[BX];
void add(int x, int i, int v) {
  if (u[x][i]!=tt) {
    u[x][i]=tt;
    s[x][i]=0;
  }
  s[x][i]+=v;
}
int cnt(int x, int i) {
  if (u[x][i]!=tt) return 0;
  return s[x][i];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b=i/BS;
    v[b].push_back(a[i]);
    s[a[i]][b]++;
  }
  scanf("%d",&m);
  for (ii=1; ii<=m; ii++) {
    scanf("%d%d%d",&t,&l,&r);
    l=(l+res-1)%n+1;
    r=(r+res-1)%n+1;
    if (l>r) swap(l,r);
    if (t==1) {
      for (cur=i=0; i<=b; i++) if (!v[i].empty()) {
        old=cur+1;
        cur+=v[i].size();
        if (l>=old && l<=cur) { lb=i; lp=l-old; }
        if (r<=cur) { rb=i; rp=r-old; break; }
      }
      x=v[rb][rp];
      for (j=rp; j+1<v[rb].size(); j++) v[rb][j]=v[rb][j+1];
      v[rb].pop_back();
      add(x,rb,-1);
      v[lb].push_back(0);
      for (j=int(v[lb].size())-1; j>lp; j--) v[lb][j]=v[lb][j-1];
      v[lb][lp]=x;
      add(x,lb,1);
    } else {
      scanf("%d",&x);
      x=(x+res-1)%n+1;
      for (res=cur=i=0; i<=b; i++) if (!v[i].empty()) {
        old=cur+1;
        cur+=v[i].size();
        if (l<old) res+=cnt(x,i); else if (l<=cur)
          for (j=l-old; j<v[i].size(); j++) if (v[i][j]==x) res++;
        if (r>=old && r<=cur) {
          for (j=r-old+1; j<v[i].size(); j++) if (v[i][j]==x) res--;
          break;
        }
      }
      printf("%d\n",res);
    }
    if (ii%BS==0) {
      for (cur=i=0; i<=b; i++) if (!v[i].empty()) {
        for (j=0; j<v[i].size(); j++) a[cur+j]=v[i][j];
        cur+=v[i].size();
        v[i].clear();
      }
      tt++;
      for (i=0; i<n; i++) {
        b=i/BS;
        v[b].push_back(a[i]);
        add(a[i],b,1);
      }
    }
  }
  return 0;
}
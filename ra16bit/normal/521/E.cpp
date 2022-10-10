#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,x,y,T,cc,ct,ut,t[200200],l[200200],c[200200],cyc[200200],u[200200],pr[200200],pru[200200],a[200200],b[200200];
vector<int> g[200200];
bool w[200200],q;
void dfs(int i, int p) {
  t[i]=l[i]=++T;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    if (t[k]==0) {
      dfs(k,i);
      l[i]=min(l[i],l[k]);
    } else l[i]=min(l[i],t[k]);
  }
}
int rfs(int i, int p) {
  u[i]=ut; pru[i]=p;
  if (cyc[i]==ct) return i;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    if (u[k]!=ut) {
      int e=rfs(k,i);
      if (e!=0) return e;
    }
  }
  return 0;
}
void printb(int bm) {
  printf("%d",bm);
  for (int y=0; y<bm; y++) printf(" %d",b[y]);
  puts(""); 
}
void cfs(int i, int cur, int p) {
  c[i]=cur; pr[i]=p; w[i]=true;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p) continue;
    if (c[k]==0) {
      cfs(k,(l[k]>=t[i])?(++cc):cur,i);
      if (q) return;
    } else if (w[k]) {
      int m=0;
      ++ct;
      for (int e=i; ; e=pr[e]) {
        a[m++]=e;
        cyc[e]=ct;
        if (e==k) break;
      }
      for (int e=0; e<m; e++) if (c[i]==cur) {
        int prv=a[(e+m-1)%m];
        int v=a[e];
        int nxt=a[(e+1)%m];
        for (int x=0; x<g[v].size(); x++) {
          int now=g[v][x];
          if (c[now]==c[i] && now!=prv && now!=nxt && l[now]<t[v]) {
            u[v]=++ut;
            int lst=rfs(now,v);
            if (lst==0) {
            puts("0");
            continue;
            }
            int bm=0;
            for (int y=lst; ; y=pru[y]) {
              b[bm++]=y;
              if (y==v) break;
            }
            reverse(b,b+bm);
            puts("YES"); q=true;
            printb(bm); bm=0;
            for (int y=e; ; y++) {
              if (y>=m) y=0;
              b[bm++]=a[y];
              if (a[y]==lst) break;
            }
            printb(bm); bm=0;
            for (int y=e; ; y--) {
              if (y<0) y=m-1;
              b[bm++]=a[y];
              if (a[y]==lst) break;
            }
            printb(bm); bm=0;
            break;
          }
        }
        if (q) return;
      }
    }
  }
  w[i]=false;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (t[i]==0) dfs(i,0);
  for (i=1; i<=n; i++) if (c[i]==0) {
    ++cc; cfs(i,cc,0);
    if (q) break;
  }
  if (!q) puts("NO");
  return 0;
}
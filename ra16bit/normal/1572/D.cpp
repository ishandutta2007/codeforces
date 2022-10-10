#include <bits/stdc++.h>
using namespace std;
const int MX=(1<<20)+5,ME=100100;
int n,m,e,S,T,i,j,it,qt,cur,r,t[ME],cap[ME],cst[ME],a[MX],b[MX],cnt[MX*2],lst[MX],u[MX],dst[MX],pre[MX];
vector<int> g[MX];
void addedge(int fr, int to, int cost) {
  g[fr].push_back(e); t[e]=to; cap[e]=1; cst[e++]=cost;
  g[to].push_back(e); t[e]=fr; cap[e]=0; cst[e++]=-cost;
}
int main() {
  scanf("%d%d",&n,&m);
  S=(1<<n); T=S+1;
  for (i=0; i<S; i++) {
    scanf("%d",&a[i]);
    b[i]=b[i/2]+(i&1);
  }
  for (i=0; i<S; i++) if (b[i]&1) for (j=0; j<n; j++) ++cnt[a[i]+a[i^(1<<j)]];
  cur=(n*2-1)*m;
  for (i=MX*2-1; i>=0; i--) {
    cur-=cnt[i];
    if (cur<0) { cnt[i]+=cur; cur=0; }
  }
  for (i=0; i<S; i++) if (b[i]&1) {
    for (j=0; j<n; j++) {
      cur=a[i]+a[i^(1<<j)];
      if (cnt[cur]>0) {
        --cnt[cur];
        addedge(i,i^(1<<j),cur);
      }
    }
    if (!g[i].empty()) addedge(S,i,0);
  }
  for (i=0; i<S; i++) if ((b[i]&1)==0 && !g[i].empty()) addedge(i,T,0);
  for (it=1; it<=m; it++) {
    vector<int> q{S},nq;
    lst[S]=it;
    dst[S]=0;
    while (!q.empty()) {
      nq.clear(); ++qt;
      for (int x: q) for (int ed: g[x]) if (cap[ed]>0) {
        i=t[ed];
        cur=dst[x]+cst[ed];
        if (lst[i]!=it || cur>dst[i]) {
        //printf("upd %d -[%d:%d]-> %d = %d\n",x,ed,cap[ed],i,cur);
          lst[i]=it;
          pre[i]=ed;
          dst[i]=cur;
          if (u[i]!=qt) {
            u[i]=qt;
            nq.push_back(i);
          }
        }
      }
      swap(q,nq);
    }
    if (lst[T]!=it) break;
    r+=dst[T];
    for (i=T; i!=S; i=t[pre[i]^1]) {
      --cap[pre[i]];
      ++cap[pre[i]^1];
    }
  }
  printf("%d\n",r);
  return 0;
}
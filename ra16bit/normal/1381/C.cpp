#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int it,t,n,x,y,i,a,b,pos,bpos,cnt,rst,r[MX],w[MX],p[MX],aa[MX],fi,fr;
priority_queue<pair<int,int>> q;
vector<int> g[MX];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d%d",&n,&x,&y);
    for (i=1; i<=n+1; i++) g[i].clear();
    for (i=0; i<n; i++) {
      scanf("%d",&aa[i]);
      g[a=aa[i]].push_back(i);
    }
    while (!q.empty()) q.pop();
    for (i=1; i<=n+1; i++) if (g[i].size()>0) q.push({g[i].size(),i}); else rst=i;
    for (i=0; i<x; i++) {
      pos=q.top().first;
      a=q.top().second;
      q.pop(); --pos;
      if (pos>0) q.push({pos,a});
      pos=g[a][pos];
      w[pos]=it; r[pos]=a;
    }
    if (!q.empty()) {
      bpos=q.top().first;
      b=q.top().second;
      q.pop();
      for (fi=fr=0; fr<bpos; fr++) p[fr]=g[b][fr];
      while (!q.empty()) {
        pos=q.top().first;
        a=q.top().second;
        q.pop();
        for (i=0; i<pos; i++) {
          r[p[fi++]]=a;
          p[fr++]=g[a][i];
        }
      }
      for (; fi<fr; fi++) r[p[fi]]=b;
    }
    cnt=n-y;
    for (i=0; i<n; i++) if (w[i]!=it && r[i]==aa[i]) { r[i]=rst; --cnt; }
    if (cnt<0) { puts("NO"); continue; }
    for (i=0; i<n && cnt>0; i++) if (w[i]!=it && r[i]!=rst) { r[i]=rst; --cnt; }
    if (cnt!=0) { puts("NO"); continue; }
    puts("YES");
    for (i=0; i<n; i++) printf("%d%c",r[i],(i+1==n)?'\n':' ');
  }
  return 0;
}
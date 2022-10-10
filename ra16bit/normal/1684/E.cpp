#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,m,x,st,v,i,res,tot,holes,steps,d,cur,cnt[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    m=min(m,n);
    set<int> all;
    map<int,int> e;
    for (i=0; i<=n; i++) cnt[i]=0;
    for (i=0; i<n; i++) {
      scanf("%d",&x);
      ++e[x];
    }
    for (auto it=e.begin(); it!=e.end(); it++) if (++cnt[it->second]==1) all.insert(it->second);
    for (st=0; e.count(st); st++);
    res=int(e.size())-st;
    if (m==0) {
      printf("%d\n",res);
      continue;
    }
    for (d=i=0; d<=m; i++) {
      steps=m;
      auto it=e.find(i);
      tot=holes=d;
      if (it==e.end()) ++d; else {
        steps-=it->second;
        holes=max(0,holes-(it->second));
        if (--cnt[it->second]==0) all.erase(it->second);
      }
      if (steps>=0 && holes<=steps) {
        v=0;
        for (auto at=all.begin(); at!=all.end(); at++) {
          cur=min(cnt[*at],steps/(*at));
          if (cur==0) break;
          holes=max(0,holes-cur*(*at));
          steps-=cur*(*at);
          v+=cur;
        }
        res=min(res,tot+int(e.size())-v-i);
      }
    }
    printf("%d\n",res);
  }
  return 0;
}
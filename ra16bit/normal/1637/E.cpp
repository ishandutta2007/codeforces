#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,n,m,i,x,y,iter,u[MX],a[MX],all[MX];
vector<int> w[MX],g[MX];
long long cur,res;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    map<int,int> cnt;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      all[i]=a[i];
      g[i].clear();
    }
    sort(all,all+n);
    for (i=0; i<n; i++) {
      x=lower_bound(all,all+n,a[i])-all;
      ++cnt[x];
    }
    vector<int> b;
    for (auto it=cnt.begin(); it!=cnt.end(); it++) w[it->second].push_back(it->first);
    for (i=0; i<=n; i++) if (!w[i].empty()) {
      reverse(w[i].begin(),w[i].end());
      b.push_back(i);
    }
    while (m--) {
      scanf("%d%d",&x,&y);
      x=lower_bound(all,all+n,x)-all;
      y=lower_bound(all,all+n,y)-all;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (i=0; i<n; i++) if (!g[i].empty()) {
      sort(g[i].begin(),g[i].end());
      reverse(g[i].begin(),g[i].end());
    }
    for (res=i=0; i<n; i++) if (i==0 || all[i]!=all[i-1]) {
      cur=cnt[i];
      u[i]=++iter;
      for (int j: g[i]) u[j]=iter;
      for (int j: b) for (int k: w[j]) if (u[k]!=iter) {
        res=max(res,(cur+j)*(all[i]+all[k]));
        break;
      }
    }
    printf("%lld\n",res);
    for (int j: b) w[j].clear();
  }
  return 0;
}
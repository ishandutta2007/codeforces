#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=200200,inf=2100000000;
const long long inf2=inf*2LL;
int n,m,q,i,j,tp,x[MX],y[MX],z[MX],cnt[MX];
map<pii,int> e;
set<pii> g[MX],all;
set<pair<long long,int>> triples;
long long tr[MX];
pii ngh[22];
void rmvcalc(int i) {
  auto it=g[i].begin();
  for (int j=0; it!=g[i].end() && j<3; it++, j++) {
    if (--cnt[it->second]==1) all.erase(all.find(*it));
  }
}
void recalc(int i) {
  auto it=triples.find({tr[i],i});
  if (it!=triples.end()) triples.erase(it);
  int j=0;
  tr[i]=0;
  for (auto it=g[i].begin(); it!=g[i].end() && j<3; it++, j++) {
    tr[i]+=it->first;
    if (++cnt[it->second]==2) all.insert(*it);
  }
  if (j>=3 && tr[i]<inf2) triples.insert({tr[i],i});
}
long long solve() {
  long long res=inf2;
  if (!triples.empty()) res=min(res,triples.begin()->first);
  int i=0;
  for (auto it=all.begin(); it!=all.end() && i<20; it++, i++) {
    int idx=it->second;
    for (int j=0; j<i; j++) if (ngh[j].first+(it->first)<res) {
      int jdx=ngh[j].second;
      if (x[idx]!=x[jdx] && x[idx]!=y[jdx] && y[idx]!=x[jdx] && y[idx]!=y[jdx]) {
        res=ngh[j].first+(it->first);
        break;
      }
    }// else break;
    ngh[i]=*it;
  }
  return res;
}
void addedge(int i) {
  if (x[i]>y[i]) swap(x[i],y[i]);
  rmvcalc(x[i]);
  rmvcalc(y[i]);
  g[x[i]].insert(make_pair(z[i],i));
  g[y[i]].insert(make_pair(z[i],i));
  e[{x[i],y[i]}]=i;
  recalc(x[i]);
  recalc(y[i]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    addedge(i);
  }
  printf("%lld\n",solve());
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d%d",&tp,&x[m],&y[m]);
    if (tp==1) {
      scanf("%d",&z[m]);
      addedge(m);
      m++;
    } else {
      if (x[m]>y[m]) swap(x[m],y[m]);
      assert(e.find({x[m],y[m]})!=e.end());
      i=e[{x[m],y[m]}];
      rmvcalc(x[m]);
      rmvcalc(y[m]);
      g[x[m]].erase(g[x[m]].find({z[i],i}));
      g[y[m]].erase(g[y[m]].find({z[i],i}));
      recalc(x[m]);
      recalc(y[m]);
    }
    printf("%lld\n",solve());
  }
  return 0;
}
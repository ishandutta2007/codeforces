#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=100100,inf=2000000000;
int n,m,mn,i,j,px,py,x[MX],y[MX],kx[MX],ky[MX];
set<pii> s;
map<int,vector<pii>> v;
bool cmpx(int i, int j) { return x[i]<x[j]; }
bool cmpy(int i, int j) { return y[i]<y[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    kx[i]=i;
    ky[i]=i;
    s.insert({x[i],y[i]});
  }
  s.insert({0,0});
  sort(kx,kx+n,cmpx);
  sort(ky,ky+n,cmpy);
  for (px=py=i=j=0; i<n || j<n; ) {
    mn=inf;
    if (i<n) mn=min(mn,x[kx[i]]-px);
    if (j<n) mn=min(mn,y[ky[j]]-py);
    //printf("%d %d | %d %d [%d]\n",i,j,px,py,mn);
    bool ox,oy;
    for (ox=false; i<n && x[kx[i]]-px==mn; ++i) if (y[kx[i]]-py<=mn) ox=true;
    for (oy=false; j<n && y[ky[j]]-py==mn; ++j) if (x[ky[j]]-px<=mn) oy=true;
    if (ox || oy) {
      if (mn>0) v[py-px].push_back({px,px+mn-1});
      px+=mn;
      py+=mn;
      if (ox) ++px;
      if (oy) ++py;
      if (!ox && s.count({px,py})) ++px;
      if (!oy && s.count({px,py})) ++py;
    }
  }
  v[py-px].push_back({px,inf});
  while (m--) {
    scanf("%d%d",&px,&py);
    if (s.count({px,py})) { puts("LOSE"); continue; }
    py-=px;
    auto vt=v.find(py);
    if (vt!=v.end()) {
      auto it=lower_bound(vt->second.begin(),vt->second.end(),make_pair(px+1,-1));
      if (it!=vt->second.begin()) {
        --it;
        if (px<=it->second) { puts("LOSE"); continue; }
      }
    }
    puts("WIN");
  }
  return 0;
}
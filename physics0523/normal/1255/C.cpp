#include<bits/stdc++.h>

using namespace std;
using Graph=vector<unordered_set<int>>;

int fl=0;
void rep(int v,int pv,Graph &g){
  if(fl){cout << ' ';}
  cout << v;
  fl=1;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    rep(nx,v,g);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  Graph g(n+1);
  vector<int> cnt(n+1);
  map<pair<int,int>,int> mp,mc;
  for(int i=0;i<(n-2);i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(b>c){swap(b,c);}
    if(a>b){swap(a,b);}
    if(b>c){swap(b,c);}
    
    cnt[a]++;cnt[b]++;cnt[c]++;
    mp[make_pair(a,b)]=c;
    mp[make_pair(a,c)]=b;
    mp[make_pair(b,c)]=a;
    
    mc[make_pair(a,b)]++;
    if(mc[make_pair(a,b)]==2){
      g[a].insert(b);
      g[b].insert(a);
    }
    mc[make_pair(a,c)]++;
    if(mc[make_pair(a,c)]==2){
      g[a].insert(c);
      g[c].insert(a);
    }
    mc[make_pair(b,c)]++;
    if(mc[make_pair(b,c)]==2){
      g[b].insert(c);
      g[c].insert(b);
    }
  }
  int p=0,q=0,r=0,s=0;
  for(int i=1;i<=n;i++){
    if(cnt[i]==1){
      if(p==0){p=i;}else{q=i;}
    }
    if(cnt[i]==2){
      if(r==0){r=i;}else{s=i;}
    }
  }
  int ha,hb,hc;
  ha=p;hb=r;
  if(ha>hb){swap(ha,hb);}
  if(mp[make_pair(ha,hb)]==0){swap(r,s);}

  g[p].insert(r);
  g[r].insert(p);
  g[q].insert(s);
  g[s].insert(q);

  ha=p;hb=r;
  if(ha>hb){swap(ha,hb);}
  hc=mp[make_pair(ha,hb)];
  g[r].insert(hc);
  g[hc].insert(r);
  
  ha=q;hb=s;
  if(ha>hb){swap(ha,hb);}
  hc=mp[make_pair(ha,hb)];
  g[s].insert(hc);
  g[hc].insert(s);

  rep(p,-1,g);
  return 0;
}
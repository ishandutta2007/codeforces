#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> dis(int v,Graph &g){
  int n=g.size();
  vector<int> res(n,1e9);
  queue<int> q;
  res[v]=0;
  q.push(v);
  while(!q.empty()){
    int cv=q.front();q.pop();
    for(auto &nx : g[cv]){
      if(res[nx]<1e9){continue;}
      res[nx]=res[cv]+1;
      q.push(nx);
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    a--;b--;c--;
    vector<long long> eg(m);
    for(auto &nx : eg){cin >> nx;}
    eg.push_back(0);
    sort(eg.begin(),eg.end());
    for(int i=1;i<=m;i++){eg[i]+=eg[i-1];}
    Graph g(n);
    for(int i=0;i<m;i++){
      int u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> ad=dis(a,g);
    vector<int> bd=dis(b,g);
    vector<int> cd=dis(c,g);
    long long res=1e18;
    for(int i=0;i<n;i++){
      int de=bd[i];
      int se=ad[i]+cd[i];
      if(se+de>m){continue;}
      //cerr << i << ' ' << eg[de] << ' ' << eg[se+de] << '\n';
      long long cr=eg[de]+eg[se+de];
      res=min(res,cr);
    }
    cout << res << '\n';
  }
  return 0;
}
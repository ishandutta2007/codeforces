#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int n,m,s,t;
vector<int> cdist(int v,Graph &g){
  vector<int> d(n,1e9);
  queue<int> q;
  q.push(v);
  d[v]=0;
  while(!q.empty()){
    int od=q.front();q.pop();
    for(auto &nx : g[od]){
      if(d[nx]>5e8){
        d[nx]=d[od]+1;
        q.push(nx);
      }
    }
  }
  return d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> s >> t;
  s--;t--;
  Graph g(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> sd=cdist(s,g);
  vector<int> td=cdist(t,g);
  set<pair<int,int>> st;
  int res=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(sd[i]+1+td[j]<sd[t]){
        st.insert({min(i,j),max(i,j)});
      }
    }
  }
  cout << ((n*(n-1))/2)-m-st.size() << '\n';
  return 0;
}
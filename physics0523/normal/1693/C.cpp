#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;

  // vector<int> odeg(n,0);
  vector<int> cdeg(n,0);
  // Graph g(n);
  Graph rev(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    // g[u].push_back(v);
    rev[v].push_back(u);
    // odeg[u]++;
    cdeg[u]++;
  }

  vector<int> d(n,1e9);
  priority_queue<pi,vector<pi>,greater<pi>> pq;
  vector<bool> run(n,false);

  d[n-1]=0;
  pq.push({0,n-1});

  while(!pq.empty()){
    pi od=pq.top();pq.pop();
    int cv=od.second;
    int cd=od.first;

    if(run[cv]){continue;}
    run[cv]=true;
    if(cv==0){
      cout << cd << '\n';
      return 0;
    }

    for(auto &nx : rev[cv]){
      int nd=cd+cdeg[nx];
      cdeg[nx]--;
      if(d[nx]>nd){
        d[nx]=nd;
        pq.push({nd,nx});
      }
    }
  }

  cout << "-1\n"; // invalid input
  return 0;
}
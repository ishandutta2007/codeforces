#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

vector<int> a;
map<pi,int> mp;
int up(int v,int pv,Graph &g){
  int cur=a[v];
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    cur+=max(0,up(nx,v,g));
  }
  mp[{v,pv}]=cur;
  return cur;
}

void down(int v,int pv,Graph &g){
  int cur=a[v];
  for(auto &nx : g[v]){
    cur+=max(0,mp[{nx,v}]);
  }

  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    int dv=cur-max(0,mp[{nx,v}]);
    mp[{v,nx}]=dv;
    down(nx,v,g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  a.resize(n);
  for(auto &nx : a){
    cin >> nx;
    if(nx==0){nx=-1;}
  }
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  up(0,-1,g);
  down(0,-1,g);
  // for(auto &nx : mp){
  //   cout << nx.first.first << "->" << nx.first.second << " : ";
  //   cout << nx.second << "\n";
  // }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    int res=a[i];
    for(auto &nx : g[i]){
      // cerr << nx << "->" << i << " : " << mp[{nx,i}] << '\n';
      res+=max(0,mp[{nx,i}]);
    }
    cout << res;
  }cout << '\n';
  return 0;
}
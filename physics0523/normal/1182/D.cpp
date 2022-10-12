#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> calcdist(int v,Graph &g,int n){
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

bool jud(int v,Graph &g,int n){
  vector<int> d=calcdist(v,g,n);
  map<int,set<int>> mp;
  for(int i=0;i<n;i++){
    mp[d[i]].insert(g[i].size());
    if(mp[d[i]].size()>1){return false;}
  }
  return true;
}

void findcand(int v,int pv,int d,map<int,int> &mp,Graph &g){
  if(d>0){
    if(g[v].size()>=3){return;}
    else if(g[v].size()==1){mp[d]=v;}
  }
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    findcand(nx,v,d+1,mp,g);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if(n<=2){
    cout << "1\n";
    return 0;
  }

  int p=0,q=0;
  vector<int> fd=calcdist(0,g,n);
  for(int i=1;i<n;i++){
    if(fd[i]>fd[p]){p=i;}
  }
  vector<int> pd=calcdist(p,g,n);
  for(int i=1;i<n;i++){
    if(pd[i]>pd[q]){q=i;}
  }
  vector<int> qd=calcdist(q,g,n);
  if(jud(p,g,n)){cout << p+1 << '\n';return 0;}
  if(jud(q,g,n)){cout << q+1 << '\n';return 0;}
  int len=qd[p];
  if(len%2){cout << "-1\n";return 0;}
  int ct;
  for(int i=0;i<n;i++){
    if(pd[i]==(len/2) && qd[i]==(len/2)){ct=i;}
  }
  if(jud(ct,g,n)){
    cout << ct+1 << '\n';
    return 0;
  }
  map<int,int> mp;
  findcand(ct,-1,0,mp,g);
  if(mp.size()>5){cout << "-1\n";return 0;}
  for(auto &nx : mp){
    if(jud(nx.second,g,n)){
      cout << nx.second+1 << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
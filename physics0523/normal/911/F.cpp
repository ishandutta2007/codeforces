#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

vector<int> calcdist(int v,Graph &g,int n){
  vector<int> d(n+1,1e9);
  queue<int> q;
  d[v]=0;
  q.push(v);
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
  int n;
  cin >> n;
  Graph g(n+1);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> fd=calcdist(1,g,n);
  int p=1;
  for(int i=1;i<=n;i++){
    if(fd[p]<fd[i]){p=i;}
  }
  vector<int> pd=calcdist(p,g,n);
  int q=1;
  for(int i=1;i<=n;i++){
    if(pd[q]<pd[i]){q=i;}
  }
  vector<int> qd=calcdist(q,g,n);
  //cout << p << ' ' << q << '\n';

  vector<int> bk(n+1,0);
  queue<int> qu;
  for(int i=1;i<=n;i++){
    bk[i]=g[i].size();
    if(bk[i]==1 && i!=p && i!=q){qu.push(i);}
  }

  long long res=0;
  vector<pi> pv;
  while(!qu.empty()){
    int od=qu.front();qu.pop();
    if(pd[od]>qd[od]){
      res+=pd[od];
      pv.push_back({od,p});
    }
    else{
      res+=qd[od];
      pv.push_back({od,q});
    }
    for(auto &nx : g[od]){
      bk[nx]--;
      if(bk[nx]==1){qu.push(nx);}
    }
  }
  qu.push(q);
  while(!qu.empty()){
    int od=qu.front();qu.pop();
    if(od==p){break;}
    res+=pd[od];
    pv.push_back({od,p});
    for(auto &nx : g[od]){
      bk[nx]--;
      if(bk[nx]==1){qu.push(nx);}
    }
  }

  cout << res << '\n';
  for(auto &nx : pv){
    cout << nx.first << ' ';
    cout << nx.second << ' ';
    cout << nx.first << '\n';
  }
  return 0;
}
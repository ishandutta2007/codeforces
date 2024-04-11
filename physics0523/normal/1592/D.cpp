#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int query(vector<int> &a){
  cout << "? " << a.size();
  for(auto &nx : a){cout << ' ' << nx;}
  cout << "\n";
  fflush(stdout);
  int v;
  cin >> v;
  return v;
}

int main(){
  int n;
  cin >> n;
  Graph g(n+1);
  vector<int> b(n+1,0);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    b[u]++;b[v]++;
  }
  queue<int> q;
  vector<int> seq;
  for(int i=1;i<=n;i++){
    if(b[i]==1){q.push(i);}
  }
  while(!q.empty()){
    int od=q.front();q.pop();
    seq.push_back(od);
    for(auto &nx : g[od]){
      b[nx]--;
      if(b[nx]==1){q.push(nx);}
    }
  }
  reverse(seq.begin(),seq.end());
  int tg=query(seq);
  int st=2,fi=n;
  while(st<=fi){
    int te=(st+fi)/2;
    vector<int> ask;
    for(int i=0;i<te;i++){ask.push_back(seq[i]);}
    if(query(ask)==tg){fi=te-1;}else{st=te+1;}
  }
  int fv=seq[st-1],sv;
  for(int i=0;i<st;i++){
    for(auto &nx : g[seq[i]]){
      if(nx==fv){sv=seq[i];break;}
    }
  }
  cout << "! " << fv << ' ' << sv << '\n';
  fflush(stdout);
  return 0;
}
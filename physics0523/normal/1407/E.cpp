#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  Graph g(n);
  for(int i=0;i<m;i++){
    int u,v,c;
    cin >> u >> v >> c;
    u--;v--;
    g[v].push_back(make_pair(u,c));
  }
  string res;
  for(int i=0;i<n;i++){res.push_back('-');}
  int rd=-1;
  
  queue<pi> qu;
  vector<bool> fl(2*n,false);
  qu.push(make_pair(2*(n-1),0));
  fl[2*(n-1)]=true;
  qu.push(make_pair(2*(n-1)+1,0));
  fl[2*(n-1)+1]=true;
  
  while(!qu.empty()){
    pi od=qu.front();
    qu.pop();
    int v=od.first/2;
    int c=od.first%2;
    int d=od.second;
    if(res[v]=='-'){
      res[v]='0'+(1-c);
    }
    else{
      if(v==0){rd=d;break;}
      for(auto &nx : g[v]){
        int nid=nx.first*2+nx.second;
        if(fl[nid]){continue;}
        fl[nid]=true;
        qu.push(make_pair(nid,d+1));
      }
    }
  }
  cout << rd << '\n';
  for(int i=0;i<n;i++){if(res[i]=='-'){res[i]='0';}}
  cout << res << '\n';
  return 0;
}
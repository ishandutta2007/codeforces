#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

vector<int> dist(int v,Graph &g,int n){
  vector<int> d(n,1e9);
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

void solve(int root,Graph &g,int n,int node,set<int> &res){
  int cand=-1;
  for(int i=0;i<node;i++){
    int ef=0;
    if(root==i){ef=1;}
    if(((g[i].size()%2)+ef)%2==0){
      if(cand!=-1){return;}
      cand=i;
    }
  }
  if(cand==-1){return;}

  //cout << cand << '\n';
  for(auto &tg : g[cand]){
    map<int,int> mp;
    queue<int> q;
    vector<bool> fl(node,false);
    q.push(root);
    fl[root]=true;
    bool isok=true;
    mp[root]=1;
    while(!q.empty() && isok){
      int od=q.front();q.pop();
      //cout << od << ',';
      if(od==cand){
        int d1=1,d2=0;
        for(auto &nx : g[od]){
          if(fl[nx]){continue;}
          if(tg==nx){mp[nx]=2*mp[od]+d1;d1++;}
          else{mp[nx]=4*mp[od]+d2;d2++;}
          if(mp[nx]>=(1<<n)){isok=false;}
          fl[nx]=true;
          q.push(nx);
        }
        if(d1>2 || d2>2){isok=false;}
      }
      else{
        int dlt=0;
        for(auto &nx : g[od]){
          if(fl[nx]){continue;}
          mp[nx]=2*mp[od]+dlt;
          if(mp[nx]>=(1<<n)){isok=false;}
          fl[nx]=true;
          q.push(nx);
          dlt++;
        }
        if(dlt>2){isok=false;}
      }
    }
    // for(auto &nx : mp){
    //   cout << nx.first << ':' << nx.second << '\n';
    // }cout << '\n';
    set<int> st;
    for(auto &nx : mp){
      st.insert(nx.second);
    }
    if(st.size()!=mp.size()){isok=false;}
    if(isok){res.insert(cand);return;}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int m=(1<<n)-3;
  int node=m+1;
  Graph g(node);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if(n==2){
    cout << "2\n";
    cout << "1 2\n";
    return 0;
  }
  vector<int> fd=dist(0,g,node);
  int u=0;
  for(int i=0;i<node;i++){
    if(fd[u]<fd[i]){u=i;}
  }
  vector<int> ud=dist(u,g,node);
  int v=0;
  for(int i=0;i<node;i++){
    if(ud[v]<ud[i]){v=i;}
  }
  vector<int> vd=dist(v,g,node);
  int diam=vd[u];

  set<int> res;
  for(int i=0;i<node;i++){
    if(ud[i]<=(n-1) && vd[i]<=(n-1) && ud[i]+vd[i]==diam){
      //cout << i << '\n';
      solve(i,g,n,node,res);
    }
  }

  cout << res.size() << '\n';
  bool spa=false;
  for(auto &nx : res){
    if(spa){cout << ' ';}
    spa=true;
    cout << nx+1;
  }cout << '\n';
  return 0;
}
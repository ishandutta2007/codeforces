#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
using pi=pair<int,int>;

int n,k;
Graph g;
vector<int> a;
map<pi,vector<int>> mp;

vector<int> up(int v,int pv){
  vector<int> vec(k+1,0);
  vec[0]^=a[v];
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    vector<int> mem=up(nx,v);
    for(int i=0;i<=k;i++){vec[i]^=mem[i];}
  }
  int sp=vec[k-1];
  for(int i=k-1;i>=1;i--){vec[i]=vec[i-1];}
  vec[0]=sp;
  vec[k]^=sp;
  mp[{v,pv}]=vec;
  return vec;
}

vector<int> gnum;
void down(int v,int pv){
  vector<int> cur(k+1,0);
  cur[0]^=a[v];
  for(auto &nx : g[v]){
    for(int i=0;i<=k;i++){
      cur[i]^=mp[{nx,v}][i];
    }
  }
  gnum[v]=cur[k];
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    vector<int> send=cur;
    for(int i=0;i<=k;i++){
      send[i]^=mp[{nx,v}][i];
    }
    int sp=send[k-1];
    for(int i=k-1;i>=1;i--){send[i]=send[i-1];}
    send[0]=sp;
    send[k]^=sp;
    mp[{v,nx}]=send;
    down(nx,v);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  g.resize(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  a.resize(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  up(0,-1);
  gnum.resize(n);
  down(0,-1);
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    if(gnum[i]==0){cout << "0";}
    else{cout << "1";}
  }cout << '\n';
  return 0;
}
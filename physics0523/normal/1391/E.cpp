//https://codeforces.com/blog/entry/81265?#comment-677328

#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

void path(vector<int> &res){
  cout << "PATH\n";
  cout << res.size() << '\n';
  for(int i=0;i<res.size();i++){
    if(i){cout << ' ';}
    cout << res[i];
  }cout << '\n';
}

void pairing(unordered_set<int> &a,unordered_set<int> &c){
  int n=min(a.size(),c.size());
  vector<pair<int,int>> res(n);
  int pt=0;
  for(auto &nx : a){
    res[pt].first=nx;
    pt++;
    if(pt==n){break;}
  }
  pt=0;
  for(auto &nx : c){
    res[pt].second=nx;
    pt++;
    if(pt==n){break;}
  }
  cout << "PAIRING\n";
  cout << n << '\n';
  for(int i=0;i<n;i++){
    cout << res[i].first << ' ' << res[i].second << '\n';
  }
}

int bd;
bool term;
unordered_set<int> a,c;
vector<int> b;
vector<bool> fl;
void dfs(int v,int pv,Graph &g){
  if(term){return;}
  fl[v]=true;
  c.erase(v);
  b.push_back(v);
  if(b.size()>=bd){
    term=true;
    path(b);
    return;
  }
  for(auto &nx : g[v]){
    if(fl[nx]){continue;}
    dfs(nx,v,g);
    if(term){return;}
  }
  b.pop_back();
  a.insert(v);
  if(min(a.size(),c.size())*2 >= bd){
    term=true;
    pairing(a,c);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    Graph g(n+1);
    for(int i=0;i<m;i++){
      int p,q;
      cin >> p >> q;
      g[p].push_back(q);
      g[q].push_back(p);
    }
    bd=(n+1)/2;
    fl.clear();fl.resize(n+1);
    a.clear();
    b.clear();
    for(int i=1;i<=n;i++){c.insert(i);}
    term=false;
    dfs(1,-1,g);
  }
  return 0;
}
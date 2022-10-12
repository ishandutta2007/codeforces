#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

using pi=pair<int,int>;
using info=pair<int,pi>;
using Graph=vector<vector<int>>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  UnionFind uf(2*n);
  vector<info> d(m);
  for(int i=0;i<m;i++){
    cin >> d[i].first >> d[i].second.first >> d[i].second.second;
    d[i].second.first--;
    d[i].second.second--;
    uf.unionSet(2*d[i].second.first+1,2*d[i].second.second);
    uf.unionSet(2*d[i].second.first,2*d[i].second.second+1);
  }
  set<int> st;
  vector<int> col(n);
  for(int i=0;i<n;i++){
    if(uf.findSet(2*i,2*i+1)){cout << "NO\n";return 0;}
    if(st.find(uf.root(2*i))!=st.end()){
      col[i]=1;
      continue;
    }
    if(st.find(uf.root(2*i+1))!=st.end()){
      col[i]=-1;
      continue;
    }
    col[i]=1;
    st.insert(uf.root(2*i));
  }
  //for(auto &nx : col){cout << nx << ' ';}

  vector<int> deg(n),res(n);
  Graph g(n);
  for(int i=0;i<m;i++){
    int u=d[i].second.first;
    int v=d[i].second.second;
    if(col[d[i].second.first]==-1){swap(u,v);}
    // u...1 v...-1
    if(d[i].first==2){
      g[u].push_back(v);
      deg[v]++;
    }
    else{
      g[v].push_back(u);
      deg[u]++;
    }
  }
  queue<int> q;
  for(int i=0;i<n;i++){
    if(deg[i]==0){q.push(i);}
  }

  int num=0;
  while(!q.empty()){
    int od=q.front();q.pop();
    res[od]=num;
    num++;
    for(auto &nx : g[od]){
      deg[nx]--;
      if(deg[nx]==0){q.push(nx);}
    }
  }
  if(num!=n){cout << "NO\n";return 0;}
  cout << "YES\n";
  for(int i=0;i<n;i++){
    if(col[i]==1){cout << "R ";}
    else{cout << "L ";}
    cout << res[i] << '\n';
  }
  return 0;
}
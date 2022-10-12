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

int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    UnionFind uf(2*n);
    vector<int> x(n-1),y(n-1),v(n-1);
    for(int i=0;i<(n-1);i++){
      cin >> x[i] >> y[i] >> v[i];
      x[i]--;y[i]--;
      if(v[i]!=-1){
        int pc=dsumb(v[i],2);
        if(pc%2==0){
          uf.unionSet(2*x[i],2*y[i]);
          uf.unionSet(2*x[i]+1,2*y[i]+1);
        }
        else{
          uf.unionSet(2*x[i]+1,2*y[i]);
          uf.unionSet(2*x[i],2*y[i]+1);
        }
      }
    }
    for(int i=0;i<m;i++){
      int a,b,p;
      cin >> a >> b >> p;
      a--;b--;
      if(p==0){
        uf.unionSet(2*a,2*b);
        uf.unionSet(2*a+1,2*b+1);
      }
      else{
        uf.unionSet(2*a+1,2*b);
        uf.unionSet(2*a,2*b+1);
      }
    }
    bool err=false;
    for(int i=0;i<n;i++){
      if(uf.findSet(2*i,2*i+1)){err=true;}
    }
    if(err){cout << "NO\n";continue;}
    cout << "YES\n";
    vector<int> npr(n,-1);
    set<int> get,dust;
    for(int i=0;i<n;i++){
      int r0=uf.root(2*i);
      int r1=uf.root(2*i+1);
      if(get.find(r0)!=get.end()){
        npr[i]=0;
        dust.insert(r1);
      }
      else if(dust.find(r0)!=dust.end()){
        npr[i]=1;
        get.insert(r1);
      }
      else if(get.find(r1)!=get.end()){
        npr[i]=1;
        dust.insert(r0);
      }
      else if(dust.find(r1)!=dust.end()){
        npr[i]=0;
        get.insert(r0);
      }
      else{
        npr[i]=0;
        get.insert(r0);
        dust.insert(r1);
      }
    }
    for(int i=0;i<(n-1);i++){
      if(v[i]==-1){v[i]=npr[x[i]]^npr[y[i]];}
      cout << x[i]+1 << ' ' << y[i]+1 << ' ' << v[i] << '\n';
    }
  }
  return 0;
}
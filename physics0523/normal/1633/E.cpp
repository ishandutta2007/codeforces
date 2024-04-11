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

using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> u(m),v(m),w(m);
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
  }
  set<int> st;
  st.insert(0);
  st.insert(2e8);
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      int cent=(w[i]+w[j])/2;
      st.insert(cent-1);
      st.insert(cent);
    }
  }
  vector<int> tg;
  vector<pl> f;
  for(auto &nx : st){
    tg.push_back(nx);
    vector<pair<int,int>> eg;
    for(int i=0;i<m;i++){
      eg.push_back({abs(w[i]-nx),i});
    }
    sort(eg.begin(),eg.end());
    pl cf={0,0};
    UnionFind uf(n);
    for(auto &ny : eg){
      int id=ny.second;
      if(uf.findSet(u[id],v[id])){continue;}
      uf.unionSet(u[id],v[id]);
      if(nx<=w[id]){cf.first--;cf.second+=w[id];}
      else{cf.first++;cf.second-=w[id];}
    }
    f.push_back(cf);
  }
  long long p,k,a,b,c,prev;
  long long oup=0;
  cin >> p >> k >> a >> b >> c;
  for(long long i=0;i<k;i++){
    long long cq;
    if(i<p){cin >> cq;}
    else{cq=(prev*a+b)%c;}
    int l=0,r=tg.size()-1;
    while(l<=r){
      int te=(l+r)/2;
      if(tg[te]<cq){l=te+1;}
      else{r=te-1;}
    }
    long long cr=(f[l].first*cq+f[l].second);
    oup^=cr;
    prev=cq;
  }
  cout << oup << '\n';
  return 0;
}
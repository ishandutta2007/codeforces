#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<pi> pv;
    pv.push_back({0,0});
    pv.push_back({0,1});
    pv.push_back({n+1,0});
    pv.push_back({n+1,1});
    for(int i=0;i<m;i++){
      int p,q;
      cin >> p >> q;
      p--;
      pv.push_back({q,p});
    }
    sort(pv.begin(),pv.end());
    vector<pi> cpv=pv;
    int sub=0;
    for(int i=1;i<pv.size();i++){
      int d=(pv[i].first-pv[i-1].first);
      if(d>=4){
        int tg;
        if(d%2==0){tg=2;}
        else{tg=3;}
        sub+=(d-tg);
      }
      cpv[i].first-=sub;
    }
    pv=cpv;

    int k=pv[pv.size()-1].first+1;
    vector<int> fv(2*k,0);
    UnionFind uf(2*k);
    for(auto &nx : pv){
      fv[nx.second*k+nx.first]=1;
    }
    for(int i=0;i<2*k;i++){
      if(fv[i]==1){continue;}
      if(fv[i-1]==0){uf.unionSet(i-1,i);}
      if(fv[i+1]==0){uf.unionSet(i+1,i);}
      if(fv[(i+k)%(2*k)]==0){uf.unionSet(i,(i+k)%(2*k));}
    }
    for(int i=1;i<(k-1);i++){
      if(fv[i]==0 && fv[i+k]==0){
        fv[i]=1;fv[i+k]=1;
      }
      if(fv[i]==0 && fv[i+1]==0){
        fv[i]=1;fv[i+1]=1;
      }
      if(fv[i+k]==0 && fv[i+1+k]==0){
        fv[i+k]=1;fv[i+1+k]=1;
      }
    }
    bool fl=true;
    for(int i=0;i<2*k;i++){
      //if(i==k){cerr << '\n';}
      //cerr << fv[i];
      if(fv[i]==0){fl=false;}
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}
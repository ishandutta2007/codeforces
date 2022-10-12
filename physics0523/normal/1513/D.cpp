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
    int n,p;
    cin >> n >> p;
    UnionFind uf(n);
    vector<int> a(n);
    vector<pi> vp(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      vp[i].first=a[i];
      vp[i].second=i;
    }
    sort(vp.begin(),vp.end());
    long long res=0;
    for(int i=0;i<n;i++){
      int cp=vp[i].second;
      int pt=cp-1;
      if(a[cp]>=p){break;}
      while(pt>=0){
        if((a[pt]%a[cp])!=0){break;}
        if(uf.findSet(pt,cp)){break;}
        uf.unionSet(pt,cp);
        res+=a[cp];
        pt--;
      }
      pt=cp+1;
      while(pt<n){
        if((a[pt]%a[cp])!=0){break;}
        if(uf.findSet(pt,cp)){break;}
        uf.unionSet(pt,cp);
        res+=a[cp];
        pt++;
      }
    }
    for(int i=1;i<n;i++){
      if(!uf.findSet(i-1,i)){
        res+=p;
        uf.unionSet(i-1,i);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
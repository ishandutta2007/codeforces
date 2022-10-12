#include<bits/stdc++.h>
#define mod 998244353

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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    cin >> a[i];
    mp[a[i]]=i;
  }
  for(auto &nx : a){nx=mp[nx];}

  vector<int> bk(n,0);
  stack<int> st;
  UnionFind uf(n);
  for(int i=0;i<n;i++){
    st.push(a[i]);
    bk[a[i]]++;
    
    if(i==a[i]){
      int trig=a[i];

      while(bk[a[i]]>0){
        int od=st.top();
        st.pop();
        trig=max(trig,od);
        bk[od]--;
        uf.unionSet(od,a[i]);
      }

      st.push(trig);
      bk[trig]++;
    }
  }
  long long res=1;
  for(int i=1;i<n;i++){
    if(!uf.findSet(a[i-1],a[i])){res*=2;res%=mod;}
  }
  cout << res << '\n';
  return 0;
}
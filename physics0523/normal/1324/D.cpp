#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

// https://algo-logic.info/binary-indexed-tree/
template <typename T>
struct BIT {
    int n;
    vector<T> bit;
    BIT(int n_) : n(n_ + 1), bit(n, 0) {}
    void add(int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[idx] += x;
        }
    }
    T sum(int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n+5);
  for(int i=1;i<=n;i++){cin >> a[i];}
  vector<int> b(n+5);
  for(int i=1;i<=n;i++){cin >> b[i];}
  vector<pi> ev;
  for(int i=1;i<=n;i++){
    // a[i]-b[i] > b[j]-a[j]
    ev.push_back({a[i]-b[i],-i});
    ev.push_back({b[i]-a[i],i});
  }
  BIT<int> bit(n+5);
  long long res=0;
  sort(ev.begin(),ev.end());
  for(auto &nx : ev){
    // cout << nx.first << ' ' << nx.second << '\n';
    if(nx.second>0){
      bit.add(nx.second,1);
    }
    else{
      res+=bit.sum(n);
      res-=bit.sum(-nx.second);
    }
  }
  cout << res << '\n';
  return 0;
}
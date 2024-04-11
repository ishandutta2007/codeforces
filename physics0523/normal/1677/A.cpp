#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

// https://algo-logic.info/binary-indexed-tree/
template <typename T>
struct BIT {
    int n;          // (+1)
    vector<T> bit;  // 
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
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    long long res=0;
    for(int i=0;i<n;i++){
      BIT<int> sb(n+5);
      BIT<int> lb(n+5);
      long long del=0;
      for(int j=i+1;j<n;j++){sb.add(p[j],1);}
      for(int j=i+1;j<n;j++){
        sb.add(p[j],-1);
        del-=lb.sum(n+1-p[j]);
        if(p[i]<p[j]){res+=del;}
        del+=sb.sum(p[j]);
        lb.add(n+1-p[j],1);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
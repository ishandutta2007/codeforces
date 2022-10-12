#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

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
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<pl> pv;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      pv.push_back({v,-i});
    }
    sort(pv.begin(),pv.end());
    long long res=0;
    BIT<long long> bit(n+5);
    for(int i=0;i<n;i++){
      long long tg=(-pv[i].second)+1;
      res+=i;
      res-=bit.sum(tg);
      bit.add(tg,1);
    }
    cout << res << '\n';
  }
  return 0;
}
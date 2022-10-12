#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  long long res=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      for(int k=j;k<n;k++){
        res=max(res,(a[i]|a[j]|a[k]));
      }
    }
  }
  cout << res << '\n';
  return 0;
}
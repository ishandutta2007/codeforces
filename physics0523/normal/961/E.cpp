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
  vector<int> a(n+1);
  vector<vector<int>> mem(n+1);
  long long res=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]=min(a[i],n);
    mem[a[i]].push_back(i);
    if(i<=a[i]){res--;}
  }
  bitset<200064> bs;
  for(int i=n;i>=1;i--){
    for(auto &nx : mem[i]){bs.set(n-nx);}
    res+=(bs>>(n-a[i])).count();
  }
  cout << (res/2) << '\n';
  return 0;
}
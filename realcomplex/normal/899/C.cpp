#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f(int n){
   return 1LL*n*(n+1)/2;
}

int main(){
  int n;
  cin >> n;
  ll k = f(n);
  cout << k%2 << "\n";
  k/=2;
  vector<int>ans;
  for(int i = n;i>=1;i--){
    if(i<=k){
      k-=i;
      ans.push_back(i);
    }
  }
  cout << ans.size() << " ";
  for(auto x : ans) cout << x << " ";
  return 0;
}
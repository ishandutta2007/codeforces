#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n; ll L;
  cin >> n >> L;
  ll c[n];
  for(int i = 0;i<n;i++){
    cin >> c[i];
    if(i!=0)c[i]=min(c[i],c[i-1]*2);
  } 
  ll ans = (ll)1e18;
  ll cur = 0;
  ll v;
  for(int i = n-1;i>=0;i--){
    v=(1LL<<i);
    cur+=(L/v)*c[i];
    L%=v;
    if(L>0){
      ans=min(ans,cur+c[i]);
    }
  }
  ans=min(ans,cur);
  cout << ans << "\n";
  return 0;
}
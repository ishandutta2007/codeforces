#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  ll n,m,k; 
  cin >> n >> m >> k;
  ll v = n+m-2;
  if(k>v){
    cout << -1 << "\n";
    return 0;
  }
  ll ans = 1;
  ++k;
  if(k<=n){
    ans=max(ans,(n/k)*m);
  }
  if(k<=m){
    ans=max(ans,(m/k)*n);
  }
  if(k==n)ans=max(ans,m);
  if(k==m)ans=max(ans,n);
  ll l;
  if(k>n){
    l=k-n+1;//split n into n parts and split m into k-n parts
    //cout <<  m/l << "\n";
    ans=max(ans,m/l);
  }
  if(k>m){
    l=k-m+1;//split m into m parts and split n int k-m parts
    //cout << n/l << "\n";
    ans=max(ans,n/l);
  }
  cout << ans << "\n";
  return 0; 
}
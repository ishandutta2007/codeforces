#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,v,l,r;
    cin >> n >> v >> l >> r;
    long long res=n/v;
    res-=r/v;
    res+=(l-1)/v;
    cout << res << '\n';
  }
  return 0;
}
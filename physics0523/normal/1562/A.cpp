#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long l,r;
    cin >> l >> r;
    long long ma=(r-1)/2;
    long long res=min(r-l,ma);
    cout << res << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  //cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long mi=8e18;
    long long ma=-8e18;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      mi=min(mi,v);
      ma=max(ma,v);
    }
    cout << ma-mi+1-n << '\n';
  }
  return 0;
}
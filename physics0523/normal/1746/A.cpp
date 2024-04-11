#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int mx=0;
    for(auto &nx : a){
      cin >> nx;
      mx=max(mx,nx);
    }
    if(mx==1){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
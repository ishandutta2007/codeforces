#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){
      cin >> nx;
      nx%=2;
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
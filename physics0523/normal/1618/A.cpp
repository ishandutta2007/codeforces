#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<int> a(7);
    for(auto &nx : a){cin >> nx;}
    if(a[0]+a[1]==a[2]){
      cout << a[0] << ' ' << a[1] << ' ' << a[3] << '\n';
    }
    else{
      cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    }
  }
  return 0;
}
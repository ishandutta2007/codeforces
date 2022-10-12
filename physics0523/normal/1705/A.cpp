#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x;
    cin >> n >> x;
    vector<int> a(2*n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    bool ok=true;
    for(int i=0;i<n;i++){
      if(a[i]+x > a[i+n]){ok=false;}
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
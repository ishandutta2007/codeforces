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
    for(auto &nx : a){cin >> nx;}
    bool fl=true;
    for(int i=1;i<n;i++){
      if(a[i]%a[0]){fl=false;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}
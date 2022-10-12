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
    for(int i=0;i<n;i++){
      int m;
      cin >> m;
      string s;
      cin >> s;
      for(auto &nx : s){
        if(nx=='D'){a[i]++;}
        else{a[i]+=9;}
      }
      a[i]%=10;
      if(i){cout << " ";}
      cout << a[i];
    }cout << "\n";
  }
  return 0;
}
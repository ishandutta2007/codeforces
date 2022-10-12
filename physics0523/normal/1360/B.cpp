#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,res=1e9;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
      res=min(a[i]-a[i-1],res);
    }
    cout << res << '\n';
  }
  return 0;
}
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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long res=8e18;
    for(int i=2;i<n;i++){res=min(res,a[i]-a[i-2]);}
    cout << res << "\n";
  }
  return 0;
}
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
    long long res=a[0];
    for(int i=1;i<n;i++){
      res=max(res,a[i]-a[i-1]);
    }
    cout << res << '\n';
  }
  return 0;
}
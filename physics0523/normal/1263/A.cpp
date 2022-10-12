#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    int res=(a[0]+a[1]+a[2])/2;
    res=min(res,a[0]+a[1]);
    cout << res << '\n';
  }
  return 0;
}
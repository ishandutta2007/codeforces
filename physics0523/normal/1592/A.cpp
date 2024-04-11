#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,h;
    cin >> n >> h;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int res=2*(h/(a[0]+a[1]));
    h%=(a[0]+a[1]);
    if(h==0){res+=0;}else if(h<=a[0]){res++;}else{res+=2;}
    cout << res << '\n';
  }
  return 0;
}
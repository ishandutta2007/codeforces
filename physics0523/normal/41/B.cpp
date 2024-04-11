#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  int h=1e9,res=m;
  vector<int> a(n);
  for(auto &nx : a){
    cin >> nx;
    int g=m/h;
    res=max(res,(m%h)+g*nx);
    h=min(h,nx);
  }
  cout << res << '\n';
  return 0;
}
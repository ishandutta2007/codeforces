// x/u + y/v = (x+y)/(u+v)
// (xv+uy)/uv = (x+y)/(u+v)
// (xv+uy)*(u+v) = (x+y)uv
// xuv+xvv+uyu+uyv = xuv+yuv
// xvv+uyu=0

#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long u,v;
    cin >> u >> v;
    cout << u*u << ' ' << -v*v << '\n';
  }
  return 0;
}
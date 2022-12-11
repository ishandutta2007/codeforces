#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,pos,l,r;
  cin >> n >> pos >> l >> r;
  if(l==1 and r==n){
    cout << "0\n";
    return 0;
  }
  if(l==1){
    cout << abs(r-pos)+1 << "\n";
    return 0;
  }
  if(r==n){
    cout << abs(pos-l)+1 << "\n";
    return 0;
  }
  int ans = min(abs(pos-l),abs(pos-r))+2+abs(r-l);
  cout << ans << "\n";
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int m=(n+2)/2;
  cout << m << '\n';
  int p=1,q=1;
  for(int i=0;i<n;i++){
    cout << p << ' ' << q << '\n';
    if(q==m){p++;}else{q++;}
  }
  return 0;
}
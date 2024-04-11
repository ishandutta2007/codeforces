#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  if(n<3*k){cout << "-1\n";return 0;}

  for(int i=0;i<3*k;i++){
    if(i){cout << ' ';}
    if(i<2*k){cout << (i%k)+1;}
    else{cout << ((i+1)%k)+1;}
  }
  for(int i=3*k;i<n;i++){
    if(i){cout << ' ';}
    cout << 1;
  }
  cout << '\n';
  return 0;
}
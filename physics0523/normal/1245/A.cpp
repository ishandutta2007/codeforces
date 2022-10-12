#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b;
    cin >> a >> b;
    if(gcd(a,b)==1){cout << "Finite\n";}
    else{cout << "Infinite\n";}
  }
  return 0;
}
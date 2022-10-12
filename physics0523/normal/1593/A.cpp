#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c;
    cin >> a >> b >> c;
    long long ma=max(a,max(b,c));
    long long da,db,dc;
    if(ma==b || ma==c){da=1;}else{da=0;}
    if(ma==a || ma==c){db=1;}else{db=0;}
    if(ma==a || ma==b){dc=1;}else{dc=0;}
    cout << ma-a+da << ' ' << ma-b+db << ' ' << ma-c+dc << '\n';
  }
  return 0;
}
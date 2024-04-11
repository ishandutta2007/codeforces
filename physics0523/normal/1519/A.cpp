#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long r,b,d;
    cin >> r >> b >> d;
    d++;
    if(r<=b && b<=r*d){cout << "Yes\n";}
    else if(b<=r && r<=b*d){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}
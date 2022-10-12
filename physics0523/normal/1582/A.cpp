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
    cout << (a+2*b+3*c)%2 << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x;
    cin >> x;
    long long rem=1;
    while(rem*10<=x){rem*=10;}
    cout << x-rem << '\n';
  }
  return 0;
}
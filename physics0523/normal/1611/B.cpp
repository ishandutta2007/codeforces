#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b;
    cin >> a >> b;
    long long res=(a+b)/4;
    res=min(res,min(a,b));
    cout << res << '\n';
  }
  return 0;
}
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
    long long v=2;
    while(1){
      if(x%((1ll<<v)-1)==0){
        cout << x/((1ll<<v)-1) << '\n';
        break;
      }
      v++;
    }
  }
  return 0;
}
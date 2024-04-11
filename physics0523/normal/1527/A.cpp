#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    for(int i=30;i>=0;i--){
      if(n&(1<<i)){
        cout << (1<<i)-1 << '\n';
        break;
      }
    }
  }
  return 0;
}
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
    cout << n << '\n';
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << i;
    }cout << '\n';
  }
  return 0;
}
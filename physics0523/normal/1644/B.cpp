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
    for(int i=1;i<=n;i++){
      int bs=n;
      for(int j=1;j<=n;j++){
        if(j-1){cout << ' ';}
        if(i==j){cout << 1;continue;}
        cout << bs;
        bs--;
      }cout << '\n';
    }
  }
  return 0;
}
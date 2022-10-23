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
      for(int j=1;j<=i;j++){
        if(j-1){cout << " ";}
        if(j==1 || j==i){cout << "1";}else{cout << "0";}
      }cout << "\n";
    }
  }
  return 0;
}
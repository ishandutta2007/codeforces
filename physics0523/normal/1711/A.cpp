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
      if(i-1){cout << " ";}
      if(i==1){cout << n;}
      else{cout << i-1;}
    }cout << "\n";
  }
  return 0;
}
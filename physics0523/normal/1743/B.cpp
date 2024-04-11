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
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      int res=(i+1)%n;
      res++;
      cout << res;
    }cout << "\n";
  }
  return 0;
}
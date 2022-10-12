#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int res=0;
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      res=max(v-i,res);
    }
    cout << res << '\n';
  }
  return 0;
}
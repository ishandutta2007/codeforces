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
    int res=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      res|=v;
    }
    cout << res << '\n';
  }
  return 0;
}
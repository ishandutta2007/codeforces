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
    int x=-2e9,y=2e9;
    for(int i=0;i<n;i++){
      int l,r;
      cin >> l >> r;
      x=max(x,l);
      y=min(y,r);
    }
    cout << max(0,x-y) << '\n';
  }
  return 0;
}
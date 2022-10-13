#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int x,y;
    cin >> x >> y;
    if(y%x){cout << "0 0\n";continue;}
    cout << 1 << ' ' << (y/x) << '\n';
  }
  return 0;
}
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
    vector<long long> u(n),d(n);
    for(auto &nx : u){cin >> nx;}
    for(auto &nx : d){cin >> nx;}
    long long res=(1ll<<60),up=0,dw=0;
    for(int i=1;i<n;i++){up+=u[i];}
    res=min(max(up,dw),res);
    //cout << up << ',' << dw << '\n';
    for(int i=1;i<n;i++){
      up-=u[i];
      dw+=d[i-1];
      //cout << up << ',' << dw << '\n';
      res=min(max(up,dw),res);
    }
    cout << res << '\n';
  }
  return 0;
}
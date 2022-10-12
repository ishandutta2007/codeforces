#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}

    int res=0;
    for(int i=0;i<30;i++){
      int cnt=0;
      for(auto &nx : a){if(nx&(1<<i)){cnt++;}}
      if(2*cnt>=n){res|=(1<<i);}
    }

    cout << res << '\n';
  }
  return 0;
}
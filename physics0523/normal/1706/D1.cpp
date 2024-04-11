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
    int res=1e9;
    for(int ma=0;ma<=3005;ma++){
      int mi=ma,p=1;
      for(auto &nx : a){
        while((nx/p)>ma && p<=k){p++;}
        if(p>k){mi=-1e9;break;}
        mi=min(mi,nx/p);
      }
      res=min(res,ma-mi);
    }
    cout << res << "\n";
  }
  return 0;
}
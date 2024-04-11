#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    int res=0;
    int mi=1e9,ma=-1e9;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mi=min(v,mi);
      ma=max(v,ma);
      if((ma-mi)>2*m){
        res++;
        mi=v;ma=v;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
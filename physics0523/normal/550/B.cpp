#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,l,r,x;
  cin >> n >> l >> r >> x;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  int res=0;
  for(int i=0;i<(1<<n);i++){
    int sig=0,mi=1e9,ma=-1e9,pc=0;
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        sig+=a[j];
        mi=min(mi,a[j]);
        ma=max(ma,a[j]);
        pc++;
      }
    }
    if(pc<2){continue;}
    if((ma-mi)<x){continue;}
    if(!(l<=sig && sig<=r)){continue;}
    res++;
  }
  cout << res << '\n';
  return 0;
}
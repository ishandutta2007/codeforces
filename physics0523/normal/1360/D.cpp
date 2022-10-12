#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k,res=2e9;
    cin >> n >> k;
    for(int i=1;i*i<=n;i++){
      if(n%i){continue;}
      int v=i;
      if(v<=k){res=min(res,n/v);}
      v=(n/i);
      if(v<=k){res=min(res,n/v);}
    }
    cout << res << '\n';
  }
  return 0;
}
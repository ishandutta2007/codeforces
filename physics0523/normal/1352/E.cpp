#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
    vector<int> a(n+1);
    vector<bool> fl((n+1)*(n+1),false);
    int res=0;
    for(int i=1;i<=n;i++){cin >> a[i];}
    for(int i=1;i<=n;i++){
      int sig=0;
      for(int j=i;j<=n;j++){
        sig+=a[j];
        if(i!=j){fl[sig]=true;}
      }
    }
    for(int i=1;i<=n;i++){
      if(fl[a[i]]){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}
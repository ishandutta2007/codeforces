#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n),f(n+1,-1e18);
    for(auto &nx : a){cin >> nx;}
    for(int i=0;i<n;i++){
      long long sig=0;
      for(int j=i;j<n;j++){
        sig+=a[j];
        f[j-i+1]=max(f[j-i+1],sig);
      }
    }
    for(int i=n-1;i>=0;i--){f[i]=max(f[i],f[i+1]);}
    for(int i=0;i<=n;i++){f[i]+=x*i;}
    f[0]=max(f[0],0ll);
    for(int i=1;i<=n;i++){f[i]=max(f[i],f[i-1]);}
    for(int i=0;i<=n;i++){
      if(i){cout << ' ';}
      cout << f[i];
    }cout << '\n';
  }
  return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n+1);
    for(long long i=1;i<=n;i++){cin >> a[i];}
    long long res=-(1ll<<60);

    for(long long i=n;i>=1;i--){
      for(long long j=i-1;j>=1;j--){
        long long lim=(i*j);
        if(lim<res){break;}
        res=max(i*j-k*(a[i]|a[j]),res);
        //cout << i << ' ' << j << ' ' << (i*j-k*(a[i]|a[j])) << '\n';
      }
    }
    cout << res << '\n';
  }
  return 0;
}
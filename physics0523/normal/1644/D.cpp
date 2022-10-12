#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m,k,q;
    cin >> n >> m >> k >> q;
    vector<long long> x(q),y(q);
    for(int i=0;i<q;i++){
      cin >> x[i] >> y[i];
      x[i]--;y[i]--;
    }
    long long res=1;
    vector<bool> xf(n,false),yf(m,false);
    for(int i=q-1;(i>=0 && n>0 && m>0);i--){
      if((!xf[x[i]]) || (!yf[y[i]])){
        if(!xf[x[i]]){n--;xf[x[i]]=true;}
        if(!yf[y[i]]){m--;yf[y[i]]=true;}
        res*=k;res%=mod;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
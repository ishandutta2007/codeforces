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
    long long n,k;
    cin >> n >> k;
    vector<long long> v(n);
    for(auto &nx : v){cin >> nx;}
    bool err=false;
    for(long long i=0;i<k;i++){
      if(v[n-1-i]!=0 && v[n-1-i]!=-1){err=true;break;}
    }
    for(long long i=0;i<n;i++){
      if(v[i]>i){err=true;break;}
    }
    if(err){cout << "0\n";continue;}

    long long res=1;
    for(long long i=1;i<=k;i++){res*=i;res%=mod;}

    for(long long i=0;i<(n-k);i++){
      if(v[i]==-1){
        long long mxm=k+i;
        res*=(mxm+1);res%=mod;
      }
      if(v[i]==0){res*=(k+1);res%=mod;}
    }
    cout << res << '\n';
  }
  return 0;
}
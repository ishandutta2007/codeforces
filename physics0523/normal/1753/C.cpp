#include<bits/stdc++.h>

using namespace std;

int f(vector<int> a){
  vector<int> b=a;
  sort(b.begin(),b.end());
  int res=0;
  for(int i=0;i<a.size();i++){
    if(a[i]!=b[i]){res++;}
  }
  return res;
}
//
// int main(){
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//
//   int n;
//   cin >> n;
//   for(int att=0;att<(1<<n);att++){
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//       if(att&(1<<i)){a[i]=1;}
//       else{a[i]=0;}
//     }
//
//     int s=0;
//     for(int i=0;i<n;i++){
//       s|=(a[i]<<i);
//     }
//     vector<double> dp(1<<n,0.0);
//     dp[s]=1.0;
//
//     double res=0.0;
//     for(int i=0;i<(1<<n);i++){
//       if(dp[i]<=0.0){continue;}
//
//       int tot=0,pot=0;
//       for(int j=0;j<n;j++){
//         for(int k=j+1;k<n;k++){
//           tot++;
//           if((i&(1<<j))!=0 && (i&(1<<k))==0){pot++;}
//         }
//       }
//
//       if(pot==0){continue;}
//       double del=tot;
//       del/=pot;
//       res+=dp[i]*del;
//       // cout << dp[i] << " " << del << "\n";
//
//       double dvd=pot;
//       for(int j=0;j<n;j++){
//         for(int k=j+1;k<n;k++){
//           if((i&(1<<j))!=0 && (i&(1<<k))==0){
//             int nx=i;
//             nx^=(1<<j);
//             nx^=(1<<k);
//             dp[nx]+=dp[i]/dvd;
//           }
//         }
//       }
//     }
//
//     for(auto &nx : a){cout << nx << " ";}cout << "= ";
//     cout << f(a) << " : ";
//     cout << res << "\n";
//   }
//   return 0;
// }

#define mod 998244353

long long power(long long a,long long b){
  long long x=1,y=a;
  while(b>0){
    if(b&1ll){
      x=(x*y)%mod;
    }
    y=(y*y)%mod;
    b>>=1;
  }
  return x%mod;
}

long long modular_inverse(long long n){
  return power(n,mod-2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int fv=f(a);
    long long res=0;
    long long whole=n;
    whole*=(n-1);
    whole/=2;
    whole%=mod;

    for(long long i=1;i<=(fv/2);i++){
      // cout << whole << " " << i*i << "\n";
      long long del=whole;
      del*=modular_inverse((i*i)%mod);del%=mod;
      res+=del;res%=mod;
    }
    cout << res << "\n";
  }
  return 0;
}
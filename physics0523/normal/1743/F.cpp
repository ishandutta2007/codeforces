#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

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
  long long n;
  cin >> n;
  vector<long long> l(n),r(n);
  for(int i=0;i<n;i++){
    cin >> l[i] >> r[i];
  }

  long long res=0,ce=1;
  set<int> st;
  for(int i=0;i<=300005;i++){st.insert(i);}

  for(int i=n-1;i>=0;i--){
    long long del=0;
    while(1){
      auto it=st.lower_bound(l[i]);
      if((*it)>r[i]){break;}
      st.erase(it);
      del++;
    }

    // cout << del << "\n";

    del*=ce;del%=mod;
    if(i==0){
      res+=del;res%=mod;
      break;
    }

    del*=2;del%=mod;
    del*=power(3,i-1);del%=mod;
    res+=del;res%=mod;
    ce*=2;ce%=mod;
  }
  cout << res << "\n";
  return 0;
}
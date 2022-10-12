#pragma GCC optimize("Ofast")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
#include<bits/stdc++.h>
#define mod 998244353

using namespace __gnu_pbds;
using namespace std;

#include <chrono>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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

long long factorial[524288];
long long invfact[524288];

void cfact(){
  long long i;
  factorial[0]=1;
  factorial[1]=1;
  for(i=2;i<524288;i++){
    factorial[i]=factorial[i-1]*i;
    factorial[i]%=mod;
  }
  invfact[524287]=modular_inverse(factorial[524287]);
  for(i=524286;i>=0;i--){
    invfact[i]=invfact[i+1]*(i+1);
    invfact[i]%=mod;
  }
}

long long calcnCr(long long n,long long k){
  if(k<0 || n<k){return 0;}
  return (factorial[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}

long long calcnCr_inv(long long n,long long k){
  return (invfact[n]*((factorial[k]*factorial[n-k])%mod))%mod;
}

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  for(auto &nx : a){cin >> nx;}
  for(auto &nx : b){cin >> nx;}
  while(n>m){
    m++;
    b.push_back(0);
  }

  vector<int> bk(200005,0);
  for(int i=0;i<n;i++){bk[a[i]]++;}
  //vector<int> cbk(200005,0);
  unordered_set<int,custom_hash> st;
  vector<tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>> tr(200005);

  long long res=1,rem=n;
  for(int i=0;i<200005;i++){
    if(bk[i]>0){
      //cbk[bk[i]]++;
      st.insert(bk[i]);
      tr[bk[i]].insert(i);
      res*=calcnCr(rem,bk[i]);res%=mod;
      rem-=bk[i];
    }
  }

  long long cpt=res;
  res=0;

  rem=n;
  for(int i=0;i<n;i++){
    for(auto &nx : st){
      long long cnt=tr[nx].order_of_key(b[i]);
      long long ce=(calcnCr_inv(rem,nx)*calcnCr(rem-1,nx-1))%mod;
      long long dlt=(((cpt*ce)%mod)*cnt)%mod;
      res+=dlt;res%=mod;
    }
    //cerr << i << ' ' << cpt << ' ' << res << ' ' << bk[b[i]] << '\n';
    if(bk[b[i]]==0){break;}
    long long ce=(calcnCr_inv(rem,bk[b[i]])*calcnCr(rem-1,bk[b[i]]-1))%mod;
    cpt*=ce;cpt%=mod;
    rem--;
    tr[bk[b[i]]].erase(b[i]);
    if(tr[bk[b[i]]].empty()){st.erase(bk[b[i]]);}
    bk[b[i]]--;
    if(bk[b[i]]>0){
      if(tr[bk[b[i]]].empty()){st.insert(bk[b[i]]);}
      tr[bk[b[i]]].insert(b[i]);
    }
    if(i==n-1 && n<m){res++;res%=mod;}
  }
  cout << res << '\n';
  return 0;
}
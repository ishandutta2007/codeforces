#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
using Graph=vector<vector<int>>;

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

using pi=pair<int,int>;
long long n,k;
map<pi,int> mp;

int rep(int v,int pv,Graph &g){
  int cur=1;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    cur+=rep(nx,v,g);
  }
  mp[{v,pv}]=cur;
  mp[{pv,v}]=n-cur;
  return cur;
}

int main(){
  cfact();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(0,-1,g);
  long long res=0;
  for(int i=0;i<n;i++){
    vector<int> arr;
    vector<long long> f;
    long long sig=0;
    for(auto &nx : g[i]){
      arr.push_back(mp[{nx,i}]);
      f.push_back(calcnCr(arr.back(),k));
      sig+=f.back();sig%=mod;
    }
    for(int j=0;j<arr.size();j++){
      long long del=(calcnCr(n-arr[j],k)-sig+f[j]+mod)%mod;
      // cout << i << ' ' << g[i][j] << ' ' << del << '\n';
      del*=(n-arr[j]);del%=mod;
      del*=arr[j];del%=mod;
      res+=del;res%=mod;
    }
    long long del=calcnCr(n,k);
    del+=(mod-sig);del%=mod;
    del*=n;del%=mod;
    res+=del;res%=mod;
  }
  cout << res << '\n';
  return 0;
}
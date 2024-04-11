#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define EACH(i,x)   for(auto & i : x)
#define ALL(x)      begin(x),end(x)

using namespace std;

typedef vector<int> vecint;
using ll=int64_t;
constexpr ll INF=1000000000000ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll gcd2(ll a,ll b){
  return (a<b)?gcd(b,a):gcd(a,b);
}
ll pt(ll n,vector<ll> b,vector<ll> pl){
  ll point=0;
  for(int i:pl){
    if(i*i>n)break;
    while((n%i)==0){
      bool ise = binary_search(ALL(b),i);
      if(ise)
        point--;
      else
        point++;
      n/=i;
    }
  }
  if(n!=1){
    if(binary_search(ALL(b),n)){
      point--;
    }else{
      point++;
    }
  }
  return point;
}
vector<ll> pl(int n){
  vector<ll> l;
  vector<ll> v(n+1,1);
  v[0]=v[1]=0;
  for(int i=2;i*i<=n;++i){
    if(v[i]){
      for(int j=i*i;j<=n;j+=i){
        v[j]=0;
      }
    }
  }
  REP(i,n+1){
    if(v[i])
      l.push_back(i);
  }
  return l;
}

int main()
{
  int n,m;cin>>n>>m;
  vector<ll> primes=pl(33000);
  vector<ll> a(n);
  vector<ll> b(m);
  REP(i,n)cin>>a[i];
  REP(i,m)cin>>b[i];
  vector<ll> g(n);
  g[0]=a[0];
  FOR(i,1,n)g[i]=gcd2(a[i],g[i-1]);
  vector<ll> pa(n);
  REP(i,n)pa[i]=pt(a[i],b,primes);
  vector<ll> pg(n);
  REP(i,n)pg[i]=-pt(g[i],b,primes);
  vector<ll> dp(n);
  ll sum=accumulate(ALL(pa),0);
  for(ll i=n-1;i>=0;i--){
    dp[i]=(i+1)*pg[i];
    FOR(j,i+1,n){
      dp[i]=max(dp[i],dp[j]+(i+1)*(pg[i]-pg[j]));
    }
  }
  auto mxi=max_element(ALL(dp));
  if(*mxi>0){
    cout<<sum+(*mxi)<<endl;
  }else{
    cout<<sum<<endl;
  }
  return 0;
}
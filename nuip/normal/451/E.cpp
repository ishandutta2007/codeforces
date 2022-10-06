#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (ll (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (ll (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll n,s,f[30],MOD=1e9+7,rinv=1;

ll mod_pow(ll a,ll n){
  if(n==0)return 1;
  ll tmp=mod_pow(a,n/2);
  return tmp*tmp%MOD*(n%2?a:1)%MOD;
}

ll comb(ll m,ll r){
  ll re=rinv;
//  cout<<m<<","<<r<<endl;
  rep(i,r){
    re*=(m-i)%MOD;
    re%=MOD;
  }
  return re%MOD;
}

int main(){
  ll i,j,k;
  ll re=0;
  cin>>n>>s;
  rep(i,n)
    cin>>f[i];
  rep(i,n-1)
    rinv=rinv*(i+1)%MOD;
//  cout<<rinv<<endl;
  rinv=mod_pow(rinv,MOD-2);
//  cout<<rinv*pow(rinv,MOD-2)%MOD<<endl;
//  if(n==20)rep(i,10)cout<<f[i+10]<<",";
  rep(i,(1<<n)){
    ll sum=0,sign=1;
    rep(j,n){
      if(i&(1<<j)){
        sum+=(f[j]+1);
        sign*=-1;
      }
      if(sum>s)break;
    }
//    cout<<i<<","<<sum<<endl;
    if(sum>s)continue;
    re+=sign*comb(n+s-sum-1,n-1);
    re=re%MOD+MOD;
    re%=MOD;
  }
  cout<<re<<endl;
  return 0;
}
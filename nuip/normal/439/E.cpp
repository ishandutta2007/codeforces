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
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
ll fact[112345],factInv[112345];
int co[112345],prime[112345];
vector<int> primes;

ll modPow(ll a,ll n){
  ll re=1,aa=a%MOD;
  while(n){
    if(n%2)
      re=re*aa%MOD;
    n/=2;
    aa=aa*aa%MOD;
  }
  return re;
}

ll comb(int n,int r){
  if(n<r || r<0 || n<0)
    return 0;
  return fact[n]*factInv[r]%MOD*factInv[n-r]%MOD;
}

ll solve(int n,int m,int r){
  //if(m*
  ll re=comb(n/m-1,r-1);
//  cout<<co[m]*re<<",";
  return (MOD+co[m]*re)%MOD;
}

void primef(){
  co[1]=prime[0]=prime[1]=1;
  for(ll i=2;i<=112000;i++){
    if(prime[i])continue;
    primes.pb(i);
    for(ll j=i*2;j<=112000;j+=i){
      prime[j]=1;
    }
    rrep(j,112000/i)
      co[j*i]=-co[j];
  }
}

int main(){
  int i,j,k;
  ll n,f;
  fact[0]=factInv[0]=1;
  rep(i,112300){
    fact[i+1]=fact[i]*(i+1)%MOD;
    factInv[i+1]=modPow(fact[i+1],MOD-2);
  }
  primef();
  
  ll re=0,q;
  cin>>q;
  rep(j,q){
    cin>>n>>f;
    re=0;
 //   cout<<j<<","<<n<<","<<f<<endl;
    for(i=1;i*i<=n;i++){
      if(n%i)continue;
      re=(re+solve(n,i,f))%MOD;
      if(i*i<n)
        re=(re+solve(n,n/i,f))%MOD;
 //     cout<<re<<"_";
    }
    cout<<re<<endl;
  }
  return 0;
}
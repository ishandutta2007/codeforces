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
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const ll MOD=1e9+7;
ll modpow(ll r,ll n,ll m=MOD){
  if(n<0)return modpow(modpow(r,-n,m),m-2);
  if(n==0)return 1ll;
  ll tmp=modpow(r,n/2,m);
  return tmp*tmp%m*(n%2?r:1ll)%m;
}

vector<ll> fact(112345),inv(112345);

ll comb(ll n,ll r){
  return n<r?0:fact[n]*inv[n-r]%MOD*inv[r]%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,t;
  string str;
  cin>>n>>t>>str;
  vector<ll> cnt(10),pw(n+10),m(n);
  rep(i,n)
    m[i]=str[i]-'0';
  pw[0]=fact[0]=1;
  rep(i,n+2){
    pw[i+1]=pw[i]*10%MOD;
    fact[i+1]=fact[i]*(i+1)%MOD;
    inv[i]=modpow(fact[i],-1);
  }
  ll re=0;
  rep(i,n){
    (re+=comb(i,t)*m[i]%MOD*pw[n-1-i]%MOD)%=MOD;
  }
  //cout<<re<<endl;
  if(t)for(i=n-1;i>=1;--i){
    ++cnt[m[n-1-i]];
    rep(j,10){
      (re+=comb(n-i-1,t-1)*j%MOD*pw[i-1]%MOD*cnt[j]%MOD)%=MOD;
    }
  }
  cout<<re<<endl;
  return 0;
}
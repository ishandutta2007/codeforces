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
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;
const ll INF=1e16;
const int PRIME_MAX=112345;
vector<int> primes;
int prime[PRIME_MAX];
void findPrime(){
  for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
      primes.pb(i);
      for(int j=i*2;j<PRIME_MAX;j+=i)
	prime[j]=1;
  }
}

ll dp[2][1123456];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  findPrime();
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> v(n);
  rep(i,n) cin>>v[i];
  vector<int> cand;
  for(int x:{v[0],v[n-1]})
    rep(i,3){
      int t=x-1+i;
      for(int p:primes){
	if(p>t) break;
	if(t%p==0){
	  cand.pb(p);
	  while(t%p==0) t/=p;
	}
      }
      if(t>1) cand.pb(t);
    }
  sort(all(cand));
  UNIQUE(cand);
  ll re=1ll*a*(n-1);
  for(int p:cand){
    //cout<<"["<<p<<"]"<<endl;
    dp[0][0]=dp[1][0]=0;
    int f=1;
    rep(i,n){
      dp[0][i+1]=INF;
      dp[1][i+1]=dp[1][i]+a;
      rep(j,3)
	if((v[i]-1+j)%p==0){
	  dp[0][i+1]=min(dp[0][i+1],dp[0][i]+b*(1-j%2));
      }
      dp[1][i+1]=min(dp[1][i+1],dp[0][i+1]);
    }
    ll sum=0;
    re=min(re,dp[1][n]);
    //rep(i,n+1)cout<<dp[0][i]<<",";cout<<endl;
    //rep(i,n+1)cout<<dp[1][i]<<",";cout<<endl;
    //cout<<dp[1][n]<<endl;
    rrep(i,n){
      int r=v[i]%p;
      if(r){
	if(r==1 || r==p-1){
	  sum+=b;
	}else{
	  break;
	}
      }
      //cout<<i<<":"<<sum<<endl;
      re=min(sum+dp[1][i],re);
    }
  }
  cout<<re<<endl;
  return 0;
}
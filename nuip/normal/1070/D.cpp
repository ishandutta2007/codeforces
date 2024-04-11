#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;++(X))
#define all(x) (x).begin(),(x).end()
#define eb pb

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X)=(Y)-1;(X)>=(S);--(X))

template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

const ll INF=1e15;
ll dp[212345];

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n,t;
  cin>>n>>t;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll rem=0;
  ll re=0;
  for(ll x:a){
    ll m=(rem+t-1)/t;
    re+=m;
    rem=max(0ll,x-m*t+rem);
  }
  cout<<re+(rem+t-1)/t<<endl;
  // fill(dp,dp+212345,INF);
  // dp[0]=0;
  // rep(i,n){
  //   MN(dp[i+2],dp[i]+(a[i]+a[i+1]+t-1)/t);
  //   MN(dp[i+1],dp[i]+(a[i]+t-1)/t);
  // }
  // rep(i,n+1) cout<<dp[i]<<",";cout<<endl;
  // cout<<dp[n]<<endl;
  // cout<<(accumulate(all(a),0ll)+t-1)/t<<endl;
  return 0;
}
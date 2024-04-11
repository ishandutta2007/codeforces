#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X)=(0);(X)<(Y);++(X))
#define REP rep
#define rrep(X,Y) for(int (X)=(Y)-1;(X)>=0;--(X))
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


int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int T;
  cin>>T;
  while(T--){
    int n,m,t;
    cin>>n>>m>>t;
    array<int,26> cnt;
    fill(all(cnt),0);
    {
      string s;
      cin>>s;
      for(char c:s) ++cnt[c-'A'];
    }
    vector<int> dp(t+1);
    dp[0]=1;
    for(int x:cnt)if(x)rrep(i,t+1-x) dp[i+x]+=dp[i];
    ll re=MOD*MOD;
    for(int x:cnt){
      if(x)rep(i,t+1-x) dp[i+x]-=dp[i];
      // rep(i,t) cout<<dp[i]<<",";cout<<endl;
      rep(i,t)if(dp[i]){
	int l=max(0,n-i);
	int r=max(0,m-(t-x-i));
	// cout<<l<<","<<r<<endl;
	if(l+r<=x) MN(re,1ll*l*r);
      }
      if(x)rrep(i,t+1-x) dp[i+x]+=dp[i];
    }
    cout<<re<<endl;
  }
  return 0;
}
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

int dp[112][112];
int prvi[112][112];
pii prv[112][112];

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<pii> heros(m);
  rep(i,m) cin>>heros[i].X>>heros[i].Y, --heros[i].X;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  auto check=
    [&](int hp,int l,int r,int d){
      for(int i=l;i!=r;i+=d){
	hp+=a[i];
	if(hp<0) return 0;
      }
      return 1;
    };
  rep(i,n) dp[i][i]=1;
  rep(d,n)rep(l,n-d){
    int r=l+d;
    if(!dp[l][r]) continue;
    rep(i,m){
      auto p=heros[i];
      if(p.X<l && check(p.Y,p.X,l+(l==r),1)){
	dp[p.X][r+(l==r)]=1;
	prvi[p.X][r+(l==r)]=i;
	prv[p.X][r+(l==r)]=pii(l,r);
      }
      if(p.X>=r && check(p.Y,p.X,r-1,-1)){
	dp[l][p.X+1]=1;
	prvi[l][p.X+1]=i;
	prv[l][p.X+1]=pii(l,r);
      }
    }
  }
  // rep(i,n+1){rep(j,n+1)cout<<dp[i][j];cout<<endl;}
  int L=min_element(all(heros))->X;
  int R=max_element(all(heros))->X+1;
  rep(l,L+1)reps(r,R,n+1)if(dp[l][r]){
    vector<int> re;
    while(r-l>0){
      re.pb(prvi[l][r]);
      tie(l,r)=prv[l][r];
    }
    reverse(all(re));
    cout<<l+1<<endl;
    vector<int> usd(m);
    for(int x:re) usd[x]=1;
    rep(i,m)if(!usd[i]) re.pb(i);
    rep(i,m) cout<<re[i]+1<<" \n"[i+1==m];
    return 0;
  }
  cout<<-1<<endl;
  return 0;
}
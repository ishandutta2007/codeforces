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

const int INF=10000;
pii dp[555][5555];
pii prv[555][5555];

const int D=10000;
int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int d,S;
  cin>>d>>S;
  // rep(i,d+1) cout<<pw[i]<<",";cout<<endl;
  fill(dp[0],dp[555],pii(INF,0));
  dp[0][0]=pii();
  using p4=pair<pii,pii>;
  queue<pii> que; que.emplace();
  pii re(MOD,MOD);
  while(que.size()){
    int v,s,dig;
    tie(v,s)=que.front(); que.pop();
    // cout<<v<<","<<s<<":"<<A.X<<","<<A.Y<<endl;
    dig=dp[v][s].X;
    if(v==0 && s==S){
      int D=dp[v][s].X;
      vector<int> pw(D+1);
      pw[0]=1;
      rep(i,D) pw[i+1]=pw[i]*10%d;
      // cout<<D<<endl;
      rrep(ind,D){
	rep(i,10){
	  int nxt=v+d-pw[ind]*i%d;
	  nxt%=d;
	  // cout<<i<<","<<dp[nxt][s-i].X<<","<<ind<<endl;
	  if(dp[nxt][s-i].X<=ind){
	    cout<<i;//cout<<endl;
	    v=nxt;
	    s-=i;
	    break;
	  }
	  assert(i<9);
	}
	// cout<<v<<","<<s<<endl;
      }
      cout<<endl;
      return 0;
    }
    rep(i,10){
      int dn=dig+1;
      int nv=(v*10+i)%d;
      int ns=s+i;
      if(ns<=S && MN(dp[nv][ns],pii(dn,i))){
	que.emplace(nv,ns);
	prv[nv][ns]=pii(v,s);
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
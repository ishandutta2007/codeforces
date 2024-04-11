#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for( int (X) =(Y)-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

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
#define rreps(X,S,Y) for(int (X) =(Y)-1; (X)>=(S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

int dst[512][512];

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n);
  rep(i,m){
    int t;
    cin>>t;
    int v;
    cin>>v; --v;
    reps(i,1,t){
      int w;
      cin>>w; --w;
      g[v].pb(w);
      g[w].pb(v);
      v=w;
    }
  }
  fill(dst[0],dst[512],MOD);
  rep(rt,n){
    queue<int> que; que.emplace(rt);
    dst[rt][rt]=0;
    while(que.size()){
      int v=que.front(); que.pop();
      for(int w:g[v])if(MN(dst[rt][w],dst[rt][v]+1)) que.emplace(w);
    }
  }
  // rep(i,n){rep(j,n) cout<<dst[i][j]<<",";cout<<endl;}
  rep(_,n){
  vector<int> ex(n); iota(all(ex),0);
  rep(_,10){
    int mn=n;
    int ind;
    vector<int> cnt(n);
    rep(v,n){
      for(int i:ex){
	for(int w:g[v])if(dst[i][v]>dst[i][w]) ++cnt[w];
      }
      int mx=0;
      for(int w:g[v]){
	MX(mx,cnt[w]);
	cnt[w]=0;
      }
      if(MN(mn,mx)) ind=v;
    }
    cout<<ind+1<<endl;
    string s;
    cin>>s;
    if(s.size()==5) break;
    int w;
    cin>>w; --w;
    vector<int> nxt;
    for(int i:ex){
      if(dst[i][ind]>dst[i][w]) nxt.pb(i);
    }
    ex=nxt;
    // for(int x:ex) cout<<x<<",";cout<<endl;
  }
  }
  return 0;
}
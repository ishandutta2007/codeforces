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

int dp[6][4][422][422];
pii prv[6][4][422][422];

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  dp[0][0][0][0]=1;
  vector<pii> ps;
  rep(i,24){
    ps.eb(25,i);
    ps.eb(i,25);
  }
  reps(i,26,201){
    ps.eb(i,i-2);
    ps.eb(i-2,i);
  }
  rep(i,4)reps(win,max(0,i-2),3)rep(j,201)rep(k,201)
    for(pii p:ps)if(MX(dp[i+1][win+(p.X>p.Y)][j+p.X][k+p.Y],dp[i][win][j][k])){
	prv[i+1][win+(p.X>p.Y)][j+p.X][k+p.Y]=p;
    }
  ps.clear();
  rep(i,14){
    ps.eb(15,i);
    ps.eb(i,15);
  }
  reps(i,16,201){
    ps.eb(i,i-2);
    ps.eb(i-2,i);
  }
  reps(win,2,3)rep(j,201)rep(k,201)
    for(pii p:ps)if(MX(dp[5][win+(p.X>p.Y)][j+p.X][k+p.Y],dp[4][win][j][k])){
	prv[5][win+(p.X>p.Y)][j+p.X][k+p.Y]=p;
      }
  int T;
  cin>>T;
  while(T--){
    int a,b;
    cin>>a>>b;
    // a=min(200,T/201);
    // b=T%201;
    pii input(a,b);
    int ind=-1;
    int A,B;
    rep(i,6)if(dp[i][3][a][b]){
      ind=i;
      A=3; B=ind-3;
      break;
    }
    if(ind<0)rreps(i,3,6)if(dp[i][i-3][a][b]){
	ind=i;
	A=ind-3;
	B=3;
	break;
      }
    if(ind<0){
      cout<<"Impossible"<<endl;
      continue;
    }
    if(A<3 && B<3){
      cout<<"Impossible"<<endl;
      continue;
    }
    cout<<A<<":"<<B<<"\n";
    vector<pii> re;
    for(int win=A;ind;--ind){
      auto p=prv[ind][win][a][b];
      re.pb(p);
      a-=p.X;
      b-=p.Y;
      win-=(p.X>p.Y);
    }
    reverse(all(re));
    rep(i,re.size())
      cout<<re[i].X<<":"<<re[i].Y<<(" \n"[i+1==re.size()]);
    assert(a==0 && b==0);
    if(0){
      cout<<input.X<<","<<input.Y<<endl;
      int sa=0,sb=0;
      for(pii p:re) sa+=p.X, sb+=p.Y;
      assert(pii(sa,sb)==input);
      int win=0,lose=0;
      for(pii p:re){
	assert(max(win,lose)<3);
	if(p.X<p.Y) ++lose;
	else ++win;
      }
      assert(max(win,lose)==3);
    }
  }
  return 0;
}
/*
6
75 0
90 90
20 0
0 75
78 50
80 100
3:0
25:0 25:0 25:0
4:1
15:13 25:23 25:23 25:6 0:25
Impossible
0:3
0:25 0:25 0:25
3:0
28:26 25:23 25:1
3:2
30:28 25:22 25:0 0:25 0:25*/
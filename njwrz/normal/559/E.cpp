#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int pos[305],len;
int n;
P<int,int> p[105];
int l[105],r[105],mid[105];
V<int> op[305];
int dp[105][305][305],f[305];
const int inf=1e18;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	V<int> v;
	FOR(i,1,n)cin>>p[i].F>>p[i].S,v.PB(p[i].F),v.PB(p[i].F-p[i].S),v.PB(p[i].F+p[i].S);
	sort(ALL(v));v.erase(unique(ALL(v)),v.end());
	for(auto u:v)pos[++len]=u;
	FOR(i,1,n){
		mid[i]=lwb(ALL(v),p[i].F)-v.begin()+1;
		l[i]=lwb(ALL(v),p[i].F-p[i].S)-v.begin()+1;
		r[i]=lwb(ALL(v),p[i].F+p[i].S)-v.begin()+1;
		op[mid[i]].PB(i);
	}
	FOR(i,0,n)FOR(j,0,len)FOR(k,0,len)dp[i][j][k]=-inf;
	int cnt=0;
	FOR(i,0,len)dp[0][i][i]=-pos[i];
	int ans=0;
	FOR(t,1,len){
		for(auto u:op[t]){
			++cnt;
			FOR(i,0,len)gmax(dp[cnt-1][i][i],f[i]-pos[i]);
			FOR(i,1,len)FOR(j,i,len)if(dp[cnt-1][i][j]>=-1e9){
				int to=max(t,j);
				if(l[u]<=i){
					gmax(dp[cnt][to][to],dp[cnt-1][i][j]);
				}else{
					gmax(dp[cnt][i][to],dp[cnt-1][i][j]);
				}
				to=max(j,r[u]);
				if(t<=i){
					gmax(dp[cnt][to][to],dp[cnt-1][i][j]);
				}else{
					gmax(dp[cnt][i][to],dp[cnt-1][i][j]);
				}
			}
			FOR(i,0,len)gmax(f[i],dp[cnt][i][i]+pos[i]);
			FOR(i,1,len)gmax(f[i],f[i-1]);
		}
	}
	FOR(i,0,len)gmax(ans,f[i]);
	cout<<ans;
	RE 0;
}
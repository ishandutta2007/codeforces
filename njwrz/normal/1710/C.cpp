#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n;
int f[200005];
int dp[200005][2][2][2][2][2][2];
const int mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	n=s.size();
	rep(i,0,n)f[i]=s[i]-'0';
	dp[0][1][1][1][0][0][0]=1;
	rep(i,0,n)rep(e1,0,2)rep(e2,0,2)rep(e3,0,2){
		rep(t1,0,2)rep(t2,0,2)rep(t3,0,2)if(dp[i][e1][e2][e3][t1][t2][t3]){
			FOR(a,0,(e1?f[i]:1))FOR(b,0,(e2?f[i]:1))FOR(c,0,(e3?f[i]:1)){
				int ta=a^b,tb=a^c,tc=b^c,toa=t1,tob=t2,toc=t3;
				if(ta&&tb)toa=1;
				if(ta&&tc)tob=1;
				if(tb&&tc)toc=1;
				add(dp[i+1][e1&&a==f[i]][e2&&b==f[i]][e3&&c==f[i]][toa][tob][toc],
				dp[i][e1][e2][e3][t1][t2][t3]);
			}
//				cout<<i<<' '<<e1<<' '<<e2<<' '<<e3<<' '<<t1<<' '<<t2<<' '<<t3<<' '<<dp[i][e1][e2][e3][t1][t2][t3]<<'\n';
		}
	}
	int ans=0;
	rep(e1,0,2)rep(e2,0,2)rep(e3,0,2){
		add(ans,dp[n][e1][e2][e3][1][1][1]);
	}
	cout<<ans;
	RE 0;
}
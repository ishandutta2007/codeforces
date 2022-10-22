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
int n,a[105];
int dp[105][105][2][2];
int dfs(int x,int y,int t1,int t2){// 
	if(!x&&!y){
		RE t2==0;
	}
	if(dp[x][y][t1][t2]!=-1)RE dp[x][y][t1][t2];
	if(t1==0){
		if(x&&dfs(x-1,y,1,t2))RE dp[x][y][t1][t2]=1;
		if(y&&dfs(x,y-1,1,t2^1))RE dp[x][y][t1][t2]=1;
		RE dp[x][y][t1][t2]=0;
	}else{
		if(x&&!dfs(x-1,y,0,t2))RE dp[x][y][t1][t2]=0;
		if(y&&!dfs(x,y-1,0,t2))RE dp[x][y][t1][t2]=0;
		RE dp[x][y][t1][t2]=1;
	}
}
void solve(){
	cin>>n;
	int t1=0,t0=0;
	FOR(i,1,n){
		cin>>a[i];
		if(a[i]%2==0)t0++;else t1++;
	}
	if(dfs(t0,t1,0,0)){
		cout<<"Alice\n";
	}else cout<<"Bob\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	FILL(dp,-1);
	while(T--)solve();
	RE 0;
}
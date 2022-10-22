#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
V<int> v[2][5005],g[5005];
int cnt,co[5005],ans[5005];
bool dp[5005][5005],last[5005][5005];
void dfs(int p,bool color){
	if(co[p]!=-1){
		if(co[p]!=color){
			cout<<"NO";exit(0);
		}else{
			RE;
		} 
	}
	co[p]=color;
	v[color][cnt].PB(p);
	for(auto u:g[p])dfs(u,!color);
}
void solve(int x,int y){
	if(!x)RE;
	if(last[x][y]){
		for(auto u:v[1][x])ans[u]=2;
		solve(x-1,y-v[1][x].size());
	}else{
		for(auto u:v[0][x])ans[u]=2;
		solve(x-1,y-v[0][x].size());
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x,y,n1,n2,n3;
	cin>>n>>m>>n1>>n2>>n3;
	FOR(i,1,m){
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	FILL(co,-1); 
	FOR(i,1,n){
		if(co[i]==-1){
			cnt++;
			dfs(i,0);
		}
	}
	dp[0][0]=1;
	FOR(i,1,cnt){
		int l1=v[0][i].size(),l2=v[1][i].size();
		for(int j=n2;j>=l1;j--){
			if(dp[i-1][j-l1]){
				dp[i][j]=1;
				last[i][j]=0;
			}
		}
		for(int j=n2;j>=l2;j--){
			if(dp[i-1][j-l2]){
				dp[i][j]=1;
				last[i][j]=1;
			}
		}
	}
	if(!dp[cnt][n2]){
		cout<<"NO";RE 0;
	}
	solve(cnt,n2);
	FOR(i,1,n){
		if(!ans[i]){
			if(n1>0){
				n1--;
				ans[i]=1;
			}else ans[i]=3;
		} 
	}
	cout<<"YES\n";
	FOR(i,1,n)cout<<ans[i];
	RE 0;
}
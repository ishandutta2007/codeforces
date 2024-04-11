#include<bits/stdc++.h>
using namespace std;
long long dp[605];
vector<pair<int,int> > v[605];
bool vis[605];
#define rep(i,a,b) for(int i=a;i<b;i++)
#define gmin(a,b) a=min(a,b)
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back(make_pair(y,z));
	}
	rep(i,0,n){
		rep(j,0,n)dp[j]=1e18;
		memset(vis,0,sizeof(vis));
		for(auto u:v[i]){
			gmin(dp[u.first],(long long)u.second);
		} 
		rep(_,0,n){
			int mini=-1;
			rep(j,0,n)if(!vis[j]){
				if(mini==-1||dp[j]<dp[mini])mini=j;
			}
//			cout<<mini<<' ';
			vis[mini]=1;
			gmin(dp[(mini+1)%n],dp[mini]+1);
			for(auto u:v[mini]){
				int to=(u.first+dp[mini])%n;
				gmin(dp[to],dp[mini]+u.second);
			}
		}
		dp[i]=0;
		rep(j,0,n){
			cout<<dp[j]<<' ';
		}
		cout<<'\n';
	}
	return 0; 
}
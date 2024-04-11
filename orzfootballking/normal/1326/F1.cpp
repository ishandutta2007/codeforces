#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> dp[1<<14][14];
int f[14][14];
int n,l[1<<14];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	char c;
	rep(i,0,n){
		rep(j,0,n){
			cin>>c;
			f[i][j]=c-'0';
		}
	}
	rep(i,1,1<<n){
		rep(j,0,n)if(i&(1<<j))l[i]++;
		rep(j,0,n)if(i&(1<<j))dp[i][j].resize(1<<(l[i]-1));
		if(l[i]==1){
			rep(j,0,n)if(i&(1<<j))dp[i][j][0]=1;
		}
	}
	rep(i,1,(1<<n)-1){
		rep(j,0,1<<(l[i]-1)){
			rep(last,0,n)if(i&(1<<last)){
				rep(start,0,n)if(!(i&(1<<start)))dp[i|(1<<start)][start][j|(f[last][start]<<(l[i]-1))]+=dp[i][last][j];
			}
		}
	}
	rep(i,0,1<<(n-1)){
		int ans=0;
		rep(j,0,n)ans+=dp[(1<<n)-1][j][i];
		cout<<ans<<' ';
	}
	RE 0;
}
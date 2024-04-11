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
int dp[2][150005]; 
int b[305],a[305],ti[305],inf=1e17;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int now=0;
	int n,m,d;
	cin>>n>>m>>d;
	FOR(i,1,m){
		cin>>a[i]>>b[i]>>ti[i];
	}
	int t,l,r;
	FOR(i,1,m){
		t=ti[i]-ti[i-1];
		now^=1;
		deque<int> q;
		FOR(j,1,min(t*d,n)){
			while(!q.empty()&&dp[now^1][q.back()]<dp[now^1][j])q.pop_back();
			q.PB(j);
		} 
		FOR(j,1,n){
			l=max(1ll,j-t*d);r=min(n,j+t*d);
			if(j+t*d<=n){
				while(!q.empty()&&dp[now^1][q.back()]<dp[now^1][r])q.pop_back();
				q.PB(r);
			}
			if(q.front()<l)q.pop_front();
			dp[now][j]=dp[now^1][q.front()];
			dp[now][j]+=b[i]-abs(a[i]-j);
		}
	}
	int ans=-inf;
	FOR(i,1,n){
		gmax(ans,dp[now][i]);
	}
	cout<<ans;
	RE 0;
}
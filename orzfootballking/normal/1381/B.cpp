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
int dp[4005],a[4005],lst[4005];
bool vis[4005]; 
void solve(){
	int n;
	cin>>n;n*=2;
	int now=n,p=0;
	FOR(i,1,n)cin>>a[i],dp[i]=0,vis[i]=0;
	dp[0]=1;
	for(int i=n;i>=1;i--){
		vis[a[i]]=1;
		p++;
		if(a[i]==now){
			while(now>0&&vis[now])now--;
			for(int j=n/2;j>=p;j--)dp[j]|=dp[j-p];
			p=0;
		}
	}
	if(dp[n/2]){
		cout<<"YES\n";
	}else cout<<"NO\n";
}	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}
/*

DP





ll int
 dp 










*/
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
int n;
int p[300005],dp[300005],log_2[300005],lst[300005];P<int,int> maxi[300005][20];
bool f[300005];
P<int,int> get(int l,int r){
	if(l>r)RE MP(-1e9,-1e9);
	int len=r-l+1;
	RE max(maxi[l][log_2[len]],maxi[r-(1<<log_2[len])+1][log_2[len]]);
}
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>p[i],maxi[i][0]=MP(i+p[i],i),f[i]=0;
	FOR(i,1,19){
		FOR(j,1,n)if(j+(1<<i)-1<=n){
			maxi[j][i]=max(maxi[j][i-1],maxi[j+(1<<(i-1))][i-1]);
		}
	}
	FOR(i,2,n){
		if(dp[i-1]>=i){
			dp[i]=max(dp[i-1],i+p[i]);
			f[i]=1;lst[i]=i-1;
		}else dp[i]=dp[i-1];
		int it=lwb(dp,dp+i,i-p[i]-1)-dp;
		if(it<i){
			P<int,int> now=get(it+1,i-1);
			if(max(i-1,now.F)>dp[i]){
				dp[i]=max(i-1,now.F);
				lst[i]=it;
			}
		}
	}
	if(dp[n]<n){
		cout<<"NO\n";
	}else {
		cout<<"YES\n";
		int now=n;
		while(now>=1){
			int to=lst[now];
			if(to<now-1){
			FOR(i,to+1,now-1){
				f[i]=1;
			}
			f[now]=0;
			} 
			now=to;
		}
		FOR(i,1,n){
			if(f[i]){
				cout<<'R';
			}else cout<<'L';
		}
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,300000)log_2[i]=log_2[i/2]+1;
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}
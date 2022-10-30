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
int p[200005][20];
int dp[1<<17];
char a[200005];
int cnt[200005][20],k;
int lst[20];
bool check(int x){
	FILL(lst,-1);FILL(p,-1);
	for(int i=n-x+1;i>=1;i--){
		rep(j,0,k)if(cnt[i+x-1][j]-cnt[i-1][j]==x)lst[j]=i+x-1;
		rep(j,0,k)p[i][j]=lst[j];
	}
	rep(i,1,1<<k)dp[i]=n+1;
	rep(i,0,1<<k)if(dp[i]<=n){
		rep(j,0,k)if(!(i&(1<<j)))if(p[dp[i]+1][j]!=-1){
			gmin(dp[i|(1<<j)],p[dp[i]+1][j]);
		}
	}
	RE dp[(1<<k)-1]<=n;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		if(a[i]=='?'){
			rep(j,0,k)cnt[i][j]=cnt[i-1][j]+1;
		}else{
			rep(j,0,k){
				if(a[i]==j+'a'){
					cnt[i][j]=cnt[i-1][j]+1;
				}else cnt[i][j]=cnt[i-1][j];
			}
		}
	}
	int l=0,r=n,mid,ans;
	while(r>=l){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans; 
	RE 0;
}
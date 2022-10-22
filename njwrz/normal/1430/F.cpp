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
using namespace std;
int n,k,l[2005],r[2005],a[2005],dp[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)dp[i]=1e18;
	FOR(i,1,n)cin>>l[i]>>r[i]>>a[i];
	int ans=1e18;
	int inf=ans;
	l[n+1]=inf;
	rep(i,0,n){
		int now=k,cost=dp[i];
		bool f=1;
		FOR(j,i+1,n){
			if((r[j]-l[j])*k+now<a[j]){
				f=0;break;
			}
			int lim=min(r[j],l[j+1]-1);
			if(lim>=l[j]&&(lim-l[j])*k+now>=a[j]){
				gmin(dp[j],cost+(max(0ll,a[j]-now)+k-1)/k*k+now);
			}
			cost+=a[j];
			if(a[j]<=now)now-=a[j];
			else now=((now-a[j])%k+k)%k;
		}
		if(f)gmin(ans,cost);
	}
	if(ans!=inf)cout<<ans;else cout<<-1;
	RE 0;
}
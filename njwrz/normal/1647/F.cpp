#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int a[500005],it[500005];
int dp[500005][2],nd[500005],n,maxi[500005];
int num[10];
bool f[500005];
int solve(){
	FOR(i,1,n)it[a[i]]=i;
	int mid=it[n];
	int len=0;
	FILL(num,0);
	FOR(i,1,mid){
		int now=lwb(num+1,num+len+1,-a[i])-num;
		num[now]=-a[i];
		gmax(len,now);
		if(len>2)RE 0;
	}
	int num2=-num[2];
	FILL(num,0);
	len=0;
	FILL(f,0);
	for(int i=n;i>mid;i--){
		int now=lwb(num+1,num+len+1,-a[i])-num;
		num[now]=-a[i];
		gmax(len,now);
		if(len>2)break;
		nd[i]=-num[2];
		f[i]=1;
		maxi[i]=-num[1];
	}
	FOR(i,mid,n)dp[i][0]=1e9,dp[i][1]=0;
	dp[mid][0]=num2;
	FOR(i,mid+1,n){
		if(a[i]<a[i-1])dp[i][0]=dp[i-1][0];
		if(a[i]>a[i-1])dp[i][1]=dp[i-1][1];
		if(a[i]>dp[i-1][0])gmax(dp[i][1],a[i-1]);
		if(a[i]<dp[i-1][1])gmin(dp[i][0],a[i-1]);
	}
	f[n+1]=1;
	int re=0;
	FOR(i,mid+1,n){
		if(f[i+1]&&(dp[i][1]>nd[i+1]&&maxi[i+1]<a[i]||dp[i][1]>maxi[i+1]&&a[i]>nd[i+1]))re++;
//		cout<<re<<' ';
	}
//	cout<<'\n';
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	V<int> num;
	FOR(i,1,n)cin>>a[i],num.PB(a[i]);
	sort(ALL(num));
	FOR(i,1,n)a[i]=lwb(ALL(num),a[i])-num.begin()+1;
	int ans=solve();
	reverse(a+1,a+n+1);
//	cout<<ans<<' ';
//	FOR(i,1,n)cout<<a[i]<<' ';
//	cout<<'\n';
	ans+=solve();
	cout<<ans;
	RE 0;
}
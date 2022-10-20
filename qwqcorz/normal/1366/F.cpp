#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
using namespace std;
const int N=2e3+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
#define point complex<ll>
#define x real()
#define y imag()

vector<pair<int,int>>e[N];
int dp[N][N];
ll cross(point a,point b){return a.x*b.y-a.y*a.x;}
ld slope(point a){if (a.x==0) return 1e18;return 1.L*a.y/a.x;}
int top=0;
point st[N];

signed main()
{
	int n=read(),m=read(),k=read(),ans=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	memset(dp,0xc0,sizeof(dp));
	dp[0][1]=0;
	for (int k=1;k<=m;k++)
	{
		int mx=0;
		for (int i=1;i<=n;i++)
		for (auto [j,w]:e[i])
		if (dp[k-1][j]>=0) dp[k][i]=max(dp[k][i],dp[k-1][j]+w);
		for (int i=1;i<=n;i++) mx=max(mx,dp[k][i]);
		ans=(1LL*ans+mx)%p;
	}
	k-=m;
	vector<point>a;
	for (int i=1;i<=n;i++)
	for (auto [j,w]:e[i]) if (dp[m][i]>=0) a.push_back((point){w,dp[m][i]});
	sort(a.begin(),a.end(),[&](point a,point b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	});
	for (auto i:a)
	{
		while (top>1&&slope(st[top]-st[top-1])<=slope(i-st[top])) top--;
//		while (top>1&&cross(st[top]-st[top-1],i-st[top])>=0) top--;
		st[++top]=i;
	}
	ld last=1;
	for (int i=1;i<=top&&last<=k;i++)
	{
		ld now=0;
		if (i==top) now=p;
			   else now=-slope(st[i+1]-st[i]);
		now=min(now,k+1.L);
		if (now<last) continue;
		int l=ceil(last),r=ceil(now)-1;
		if (l<=r) ans=(ans+1LL*(r-l+1)*st[i].y+1LL*(l+r)*(r-l+1)/2%p*st[i].x)%p;
		last=now;
	}
	print(ans);
	
	return 0;
}
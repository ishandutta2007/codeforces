//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e5+10;
int n,q,dp[M],c[M],v[M];

int solve(int a,int b)
{
	for (int i=1;i<=n;i++)
		dp[i]=-inf;
	pair<int,int>p1=mp(0,0),p2=mp(-inf,1);
	for (int i=1;i<=n;i++)
	{
		if (p1.y==c[i])
			dp[c[i]]=max(dp[c[i]],max(p1.x+a*v[i],p2.x+b*v[i])),
			p1.x=dp[c[i]];
		else
		{
			dp[c[i]]=max(dp[c[i]],max(dp[c[i]]+a*v[i],p1.x+b*v[i]));
			if (p2.y==c[i])p2.x=dp[c[i]];
			else p2=max(p2,mp(dp[c[i]],c[i]));
			if (p2>p1)swap(p1,p2);
		}
	}int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	return ans;
}

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)v[i]=read();
	for (int i=1;i<=n;i++)c[i]=read();
	while(q--)
	{
		int a=read(),b=read();
		printf("%lld\n",solve(a,b));
	}
	return 0;
}
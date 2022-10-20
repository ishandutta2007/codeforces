#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct seg
{
	int x,l;
	bool operator <(const seg &a)const
	{
		return x<a.x;
	}
}a[N];
int dp[N][N][2];
int calc(int l,int r,int x){return max(r,x)-max(l,x);}

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].l=read();
	sort(a+1,a+1+n),a[0].x=-inf;
	memset(dp,0xc0,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++)
	for (int k=0,l=a[i].x-a[i].l,r=a[i].x;k<=1;k++,l+=a[i].l,r+=a[i].l)
	{
		int mx=r,u=i,v=k;
		for (int j=i-1;j>=0;j--)
		{
			for (int x=0;x<=j;x++)
			for (int y=0;y<=1;y++)
			{
				int tu=u,tv=v;
				if (a[x].x+y*a[x].l>mx) tu=x,tv=y;
				dp[i][tu][tv]=max(dp[i][tu][tv],dp[j][x][y]+calc(l,mx,a[x].x+y*a[x].l));
				ans=max(ans,dp[i][tu][tv]);
			}
			if (a[j].x+a[j].l>mx)
			{
				mx=a[j].x+a[j].l;
				u=j,v=1;
			}
		}
	}
	print(ans);
	
	return 0;
}
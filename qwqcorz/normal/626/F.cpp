#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e2+5;
const ll M=1e3+5;
const ll mod=1e9+7;

inline ll read()
{
	register ll s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register ll x,const register char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N],dp[2][N][M];//dp[i][j][k]ijk(MLEi) 

int main()
{
	memset(dp,0,sizeof(dp));
	ll n=read(),m=read(),p=1;
	for (ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	dp[0][0][0]=1;
	for (ll i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	for (ll i=1;i<=n;i++,p^=1)
	{
		for (ll j=0;j<=n;j++)
		for (ll k=0;k<=m;k++)
		{
			if (j&&k>=a[i]*(j-1)) (dp[p][j][k]+=dp[p^1][j-1][k-a[i]*(j-1)])%=mod;// 
			if (k>=a[i]*j) (dp[p][j][k]+=dp[p^1][j][k-a[i]*j])%=mod;// 
			if (k>=a[i]*j) (dp[p][j][k]+=dp[p^1][j][k-a[i]*j]*j)%=mod;// 
			if (k>=a[i]*(j+1)) (dp[p][j][k]+=dp[p^1][j+1][k-a[i]*(j+1)]*(j+1))%=mod;// 
		}
		for (ll j=0;j<=n;j++)
		for (ll k=0;k<=m;k++) dp[p^1][j][k]=0;
	}
//	for (ll i=1;i<=n;i++)
//	{
//		for (ll j=0;j<=i;j++)
//		{
//			for (ll k=0;k<=m;k++) print(dp[i][j][k],' ');
//			puts("");
//		}
//		puts("");
//	}
	ll ans=0;
	for (ll i=0;i<=m;i++) (ans+=dp[p^1][0][i])%=mod;
	print(ans);

	return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e2+5;
const ll M=1e3+5;
const ll p=1e9+7;

inline ll read()
{
	register ll s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register ll x,const register char c='\n')
{
	write(x);
	putchar(c);
}
ll a[N],dp[N][N][M];//dp[i][j][k]ijk 

int main()
{
	memset(dp,0,sizeof(dp));
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	dp[0][0][0]=1;
	for (ll i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	for (ll i=1;i<=n;i++)
	for (ll j=0;j<=i;j++)
	for (ll k=0;k<=m;k++)
	{
		if (j&&k>=a[i]*(j-1)) (dp[i][j][k]+=dp[i-1][j-1][k-a[i]*(j-1)])%=p;// 
		if (k>=a[i]*j) (dp[i][j][k]+=dp[i-1][j][k-a[i]*j])%=p;// 
		if (k>=a[i]*j) (dp[i][j][k]+=dp[i-1][j][k-a[i]*j]*j)%=p;// 
		if (k>=a[i]*(j+1)) (dp[i][j][k]+=dp[i-1][j+1][k-a[i]*(j+1)]*(j+1))%=p;// 
	}
//	for (ll i=1;i<=n;i++)
//	{
//		for (ll j=0;j<=i;j++)
//		{
//			for (ll k=0;k<=m;k++) print(dp[i][j][k],' ');
//			puts("");
//		}
//		puts("");
//	}
	ll ans=0;
	for (ll i=0;i<=m;i++) (ans+=dp[n][0][i])%=p;
	print(ans);

	return 0;
}
*/
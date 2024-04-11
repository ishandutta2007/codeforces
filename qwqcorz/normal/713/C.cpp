#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+5;
const ll inf=1e18;

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
ll dp[N][N],a[N],b[N];

int main()
{
	ll n=read();
	for (ll i=1;i<=n;i++) b[i]=a[i]=read()-i;
	sort(b+1,b+1+n);
	ll m=unique(b+1,b+1+n)-b-1;
	for (ll i=1;i<=n;i++) dp[i][0]=inf;
	for (ll i=1;i<=m;i++) dp[1][i]=min(dp[1][i-1],abs(a[1]-b[i]));
	for (ll i=2;i<=n;i++)
	for (ll j=1;j<=m;j++) dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[i]-b[j]));
	print(dp[n][m]);

	return 0;
}
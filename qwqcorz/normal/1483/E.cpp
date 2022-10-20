#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
void answer(ll x)
{
	printf("! %lld\n",x);
	fflush(stdout);
}
ll p,dp[99][99];
bool ask(ll x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	string s; cin>>s;
	if (s=="Fired!") exit(114514);
	p+=(s=="Lucky!"?1:-1)*x;
	return s=="Lucky!";
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (ll i=1;i<=60;i++) dp[0][i]=1;
	for (ll i=1;i<=60;i++)
	{
		for (ll j=1;j<=60;j++) dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
		dp[i][0]=dp[i-1][1];
	}
	ll T=read();
	while (T--)
	{
		p=1;
		if (!ask(1)) {answer(0); continue;}
		ll l=1LL<<46,r=(ll)1e14+1,k=0,b=0;
		for (ll i=1;i<=46;i++)
		if (!ask(1LL<<i))
		{
			l=1LL<<(i-1),r=1LL<<i;
			break;
		}
		for (ll i=0;i<=60;i++) if (dp[i][0]>=r-l) {k=i; break;}
		ask(l),ask(l),ask(l);
		while (l+1<r)
		{
			if (!b) ask(l),b++,k--;
			ll len=min(dp[k-1][b-1],r-l-1);
			if (ask(l+len)) b++,l=l+len;
					   else b--,r=l+len;
			k--;
		}
		answer(l);
	}
	
	return 0;
}
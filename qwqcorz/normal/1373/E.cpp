#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1ll<<62;

ll read()
{
	ll s=0ll;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10ll+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0ll)
	{
		putchar('-');
		x=-x;
	}
	if (x<10ll) putchar(x+'0');
	else
	{
		write(x/10ll);
		putchar(x%10ll+'0');
	}
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll sum[10ll];// 
ll num[20ll];// 

int main()
{
	ll T=read();
	while (T--)
	{
		ll ans=inf;
		ll m=read(),n=read();//sigma f(x~x+n)=m
		for (ll i=0ll;i<=9ll;i++) sum[i]=0ll;
		for (ll i=0ll;i<=9ll;i++)
		for (ll j=i;j<=i+n;j++) sum[i]+=j%10ll;
		for (ll i=0ll;i<=9ll;i++)// 
		if (i+n>9ll)// 
		{
			/*
			(10-i)*(9j+num)+(i+n-9)*(num+1)+sum[i]=m
			9j(10-i)+num(10-i)+(i+n-9)num+(i+n-9)+sum[i]=m
			(10-i+i+n-9)num=m-9j(10-i)-(i+n-9)-sum[i]
			(n+1)num=m-9j(10-i)-(i+n-9)-sum[i]
			num=(m-9j(10-i)-(i+n-9)-sum[i])/(n+1)
			*/
			for (ll j=0ll;j<=17ll;j++)// 
			if ((m-9ll*j*(10ll-i)-(i+n-9ll)-sum[i])%(n+1ll)==0ll&&m-9ll*j*(10ll-i)-(i+n-9ll)-sum[i]>=0ll)
			{
				ll now=(m-9ll*j*(10ll-i)-(i+n-9ll)-sum[i])/(n+1ll);
				ll cnt=0ll,tmp=0ll;
				num[++cnt]=i;
				for (ll k=1ll;k<=j;k++) num[++cnt]=9ll;
				num[++cnt]=min(now,8ll);
				now-=min(now,8ll);
				while (now)
				{
					num[++cnt]=min(now,9ll);
					now-=min(now,9ll);
				}
				for (ll i=cnt;i>=1ll;i--) tmp=tmp*10ll+num[i];
				ans=min(ans,tmp);
			}
		}
		else
		if ((m-sum[i])%(n+1ll)==0ll&&m-sum[i]>=0ll)
		{
			ll cnt=0ll,now=(m-sum[i])/(n+1ll),tmp=0ll;
			num[++cnt]=i;
			while (now)
			{
				num[++cnt]=min(now,9ll);
				now-=min(now,9ll);
			}
			for (ll i=cnt;i>=1;i--) tmp=tmp*10ll+num[i];
			ans=min(ans,tmp);
		}
		if (ans==inf) puts("-1");
				 else print(ans);
	}

	return 0;
}
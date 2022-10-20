#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll a[4][5]={{0,0,0,0,0},
				  {0,1,2,3,4},
				  {0,1,3,4,2},
				  {0,1,4,2,3}};

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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
void calc(ll &ans,ll w,ll tot,ll num)
{
	if (tot==4) return void(ans+=a[w][num]);
	ll div=(num-1)/(tot/4);
	ll mod=num%(tot/4);
	ll wh=a[w][div+1];
	ans+=(wh-1)*(tot/4);
	if (mod==0) mod=tot/4;
	calc(ans,w,tot/4,mod);
}

int main()
{
	ll T=read();
	while (T--)
	{
		ll n=read();
		if (n<=3)
		{
			print(n);
			continue;
		}
		ll m=log2(n);
		m-=m&1;
		ll tot=((1ll<<(m+2))-(1ll<<m))/3;
		ll w=n%3;
		if (w==0) w=3;
		ll ans=(1ll<<m)-1+tot*(w-1);
		ll num=(n-((1ll<<m)-1)-1)/3+1;
		calc(ans,w,tot,num);
		print(ans);
	}

	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0) return x=1,y=0,a;
	ll g=exgcd(b,a%b,x,y),tx=x,ty=y;
	x=ty;
	y=tx-a/b*ty;
	return g;
}
ll ask(ll p1,ll a,ll p2,ll b)
{
	if (a<0||b<0) return 1e18;
	ll x=0,y=0,g=exgcd(p1,p2,x,y),l=lcm(p1,p2);
	x=(x%p2+p2)%p2;
	if ((a-b)%g) return 1e18;
	return (a-(a-b)/g*x%l*p1%l+l)%l;
}

signed main()
{
	int n=read(),m=read(),Q=read();
	while (Q--)
	{
		int x=read(),y=read(),a1=-1,a2=-1,b1=-1,b2=-1;
		if (x<n) a1=x;
		if (x>0) a2=n+n-x;
		if (y<m) b1=y;
		if (y>0) b2=m+m-y;
		ll ans=1e18;
		ans=min(ans,ask(n*2,a1,m*2,b1));
		ans=min(ans,ask(n*2,a1,m*2,b2));
		ans=min(ans,ask(n*2,a2,m*2,b1));
		ans=min(ans,ask(n*2,a2,m*2,b2));
		if (ans==1e18) puts("-1");
				  else print(ans);
	}
	
	return 0;
}
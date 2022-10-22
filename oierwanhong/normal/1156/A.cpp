//Wan Hong 2.1
//home
#include<iostream>
#include<cstdio>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}

#define maxn 100011
ll a[maxn];
int main()
{
	ll n=read(),ans=0;
	a[1]=read();
	for(ll i=2;i<=n;++i)
	{
		a[i]=read();
		if(a[i]==1)
		{
			if(a[i-1]==2)ans+=3;
			else ans+=4;
		}
		else if(a[i]==2)
		{
			if(a[i-1]==1)
			{
				if(i>2&&a[i-2]==3)ans+=2;
				else ans+=3;
			}
			else ans=-INF;
		}
		else
		{
			if(a[i-1]==1)ans+=4;
			else ans=-INF;
		}
	}
	if(ans<0)puts("Infinite");
	else puts("Finite"),std::cout<<ans;
	return 0;
}
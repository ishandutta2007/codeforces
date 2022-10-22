//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
#include<set>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
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
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}

#define maxn 5011
std::set<ll>s;
int main()
{
	ll n=read(),ans;
	while(n--)s.insert((read()));
	if(s.size()==1)ans=0;
	else if(s.size()==2)
	{
		ll a=*s.begin(),b;s.erase(a);
		b=*s.begin();
		if((b-a)&1)ans=b-a;
		else ans=(b-a)>>1;
	}
	else if(s.size()==3)
	{
		ll a=*s.begin(),b,c;s.erase(a); 
		b=*s.begin();s.erase(b);
		c=*s.begin();
		if(c-b==b-a)ans=b-a;
		else ans=-1;
	}
	else ans=-1;
	std::cout<<ans;
	return 0;
}
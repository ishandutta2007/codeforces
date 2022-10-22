//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 200011
char a[MAXN];
ll n,k,ans;
void upd(const char* t)
{
	ll l=1,r=1,res=0;
	while(l<=n)
	{
		while(r<=n&&r-l<k)
		{
			res+=(a[r]==t[r%3==0?3:r%3]);
			++r;
		}
		if(r-l<k)break;
		ans=max(ans,res);
		res-=(a[l]==t[l%3==0?3:l%3]);
		++l;
	}
}
void work()
{
	ans=0;
	n=read(),k=read();
	std::cin>>(a+1);
	upd(" RGB");upd(" GBR");upd(" BRG");
	if(ans>=k)std::cout<<0<<std::endl;
	else std::cout<<k-ans<<std::endl;
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}
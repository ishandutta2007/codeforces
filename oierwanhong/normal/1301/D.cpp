//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
typedef std::pair<ll,str> pls;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
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
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
ll n,m,k;
std::vector<pls>ans;
void solve()
{
	if(m==1)
	{
		ans.push_back(pls(min(k,n-1),"D"));
		k-=n-1;
		if(k<=0)return;
		ans.push_back(pls(min(k,n-1),"U"));
		k-=n-1;
		return;
	}
	ans.push_back(pls(min(k,m-1),"R"));
	k-=m-1;
	if(k<=0)return;
	ans.push_back(pls(min(k,m-1),"L"));
	k-=m-1;
	if(k<=0)return;
	
	for(ll i=2;i<=n;++i)
	{
		ans.push_back(pls(1,"D"));
		--k;
		if(k<=0)return;
		ans.push_back(pls(min(k,m-1),"R"));
		k-=m-1;
		if(k<=0)return;
		if(k/3)ans.push_back(pls(min(k/3,m-1),"UDL"));
		ll t=min(k/3,m-1);
		k-=3*t;
		if(t<m-1&&k&&k<3)
		{
			ans.push_back(pls(1,"U"));
			if(k>1)ans.push_back(pls(1,"D"));
			return;
		}
		if(k<=0)return;
	}
	ans.push_back(pls(k,"U"));
}
int main()
{
	n=read(),m=read(),k=read();
	if(k>4*n*m-2*n-2*m)
	{
		puts("NO");return 0;
	}
	puts("YES");
	solve();
	std::cout<<ans.size()<<'\n';
	for(std::vector<pls>::iterator it=ans.begin();it!=ans.end();++it)
		std::cout<<it->first<<" "<<it->second<<'\n';
	return 0;
}
//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
#define MAXN 300011
ll a[MAXN],n,m,k;
ll calc(ll l,ll r)
{
	if(l==r)return max(a[l]-k,0);
	ll mid=(l+r)>>1;
	ll fl=calc(l,mid),fr=calc(mid+1,r);
	ll ans=max(fl,fr);
	ll f[11],sum=0;
	memset(f,0,sizeof f);
	for(ll i=mid;i>=l;--i)
	{
		sum+=a[i];
		f[(mid-i+1)%m]=max(f[(mid-i+1)%m],sum-k*((mid-i+1)/m));
	}
	sum=0;
	for(ll i=mid+1;i<=r;++i)
	{
		sum+=a[i];
		for(ll j=0;j<m;++j)
			ans=max(ans,sum+f[j]-k*ceil(double(i-mid+j)/m));
	}
	return max(ans,0);
}
int main()
{
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	std::cout<<calc(1,n);
	return 0;
}
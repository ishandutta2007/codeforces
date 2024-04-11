//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
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
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
ll c[MAXN][31];
char a[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),k=read();
        for(ll i=0;i<n;++i)
			for(ll j=0;j<26;++j)c[i][j]=0; 
        scanf("%s",a);
        for(ll i=0;i<n;++i)++c[i%k][a[i]-'a'];
        ll l=k/2-1,r=k/2,ans=0;
        if(k&1)
        {
        	ll mid=k/2;
        	ll tmp=INF;
        	for(ll j=0;j<26;++j)umin(tmp,n/k-c[mid][j]);
        	ans+=tmp;++r;
		}
		while(l>=0&&r<k)
		{
			ll tmp=INF;
			for(ll j=0;j<26;++j)umin(tmp,n/k-c[l][j]+n/k-c[r][j]);
			ans+=tmp;
			--l,++r;
		}
        printf("%lld\n",ans);
    }
    return 0;
}
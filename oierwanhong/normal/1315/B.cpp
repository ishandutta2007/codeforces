//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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
#define MAXN 100011
char s[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll a=read(),b=read(),p=read(),cost=0;
        scanf("%s",s+1);
        ll n=strlen(s+1);
        s[n]='$';
        for(ll i=n-1;i;--i)
            if(s[i]!=s[i+1])
            {
                cost+=(s[i]=='A'?a:b);
                if(cost>p)
                {
                    printf("%lld\n",i+1);
                    break;
                }
            }
        if(cost<=p)puts("1");
    }
}
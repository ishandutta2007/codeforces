//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
ll s[MAXN][27],ans[27];
char arr[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        memset(ans,0,sizeof ans);
        ll n=read(),m=read();
        scanf("%s",arr+1);
        for(ll i=1;i<=n;++i)
        {
            for(ll j=0;j<26;++j)
                s[i][j]=s[i-1][j]+(arr[i]=='a'+j);
        }
        for(ll i=1;i<=m;++i)
        {
            ll pos=read();
            for(ll j=0;j<26;++j)
                ans[j]+=s[pos][j];
        }
        for(ll i=0;i<26;++i)printf("%lld ",ans[i]+s[n][i]);
        puts("");
    }
}
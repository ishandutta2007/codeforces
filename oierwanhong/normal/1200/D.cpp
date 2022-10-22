//Wan Hong 3.1
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
#define MAXN 2011
char a[MAXN];
ll f[MAXN][MAXN],c[MAXN];
ll maxcol[MAXN],mincol[MAXN],maxrow[MAXN],minrow[MAXN];
int main()
{
    ll n=read(),k=read(),ans=0,cnt=0;
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",a+1);
        for(ll j=1;j<=n;++j)
            if(a[j]=='B')
            {
                if(!mincol[j])mincol[j]=i;
                maxcol[j]=i;
                if(!minrow[i])minrow[i]=j;
                maxrow[i]=j;
            }
    }
    for(ll i=1;i<=n;++i)cnt+=(!maxrow[i])+(!maxcol[i]);
    ll l=1,r=1;
    while(l<=n)
    {
        while(r<l+k&&r<=n)
        {
        	if(maxrow[r] &&maxrow[r]-k+1<=minrow[r])++c[max(maxrow[r]-k+1,1)],--c[minrow[r]+1];
            ++r;
        }
        ll sum=0;
        for(ll j=1;j<=n;++j)
        {
            sum+=c[j];
            f[l][j]+=sum;
        }
        if(maxrow[l] &&maxrow[l]-k+1<=minrow[l])--c[max(maxrow[l]-k+1,1)],++c[minrow[l]+1];
        ++l;
    }
    l=1,r=1;
    while(l<=n)
    {
        while(r<l+k&&r<=n)
        {
            if(maxcol[r] &&maxcol[r]-k+1<=mincol[r])++c[max(maxcol[r]-k+1,1)],--c[mincol[r]+1];
            ++r;
        }
        ll sum=0;
        for(ll j=1;j<=n;++j)
        {
            sum+=c[j];
            f[j][l]+=sum;
        }
        if(maxcol[l] &&maxcol[l]-k+1<=mincol[l])--c[max(maxcol[l]-k+1,1)],++c[mincol[l]+1];
        ++l;
    }
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)umax(ans,f[i][j]);
    printf("%lld",ans+cnt);
    return 0;
}
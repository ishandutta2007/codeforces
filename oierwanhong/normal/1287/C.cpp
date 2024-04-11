//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
ll abs(ll x)
{
    return x>0?x:-x;
}

/**********/
#define MAXN 111
ll f[2][MAXN][MAXN];
int main()
{
    memset(f,0x3f, sizeof(f));
    ll n=read(),x=read();
    if (!x)f[0][1][0]=0,f[1][1][1]=0;
    else f[x&1][1][x&1]=0;
    for (int i = 2; i <= n; ++i)
    {
        x=read();
        if (!x)
        {
            for (int j = 0; j <=i ; ++j)
            {
                if (j)umin(f[1][i][j],min(f[0][i-1][j-1]+1,f[1][i-1][j-1]));
                umin(f[0][i][j],min(f[0][i-1][j],f[1][i-1][j]+1));
            }
        }
        else
        {
            for (int j = 0; j <=i ; ++j)
            {
                if (x&1)
                {
                    if (j)umin(f[1][i][j],min(f[0][i-1][j-1]+1,f[1][i-1][j-1]));
                }
                else umin(f[0][i][j],min(f[0][i-1][j],f[1][i-1][j]+1));
            }
        }
    }
    printf("%lld",min(f[0][n][(n+1)>>1],f[1][n][(n+1)>>1]));
    return 0;
}
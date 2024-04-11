//Wan Hong 3.1
//Online IDE
#include<iostream>
#include<cstdio>
#include<algorithm>
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
#define MAXN 5011
ll n,ans[MAXN];
char a[MAXN],t[MAXN];
ll work()
{
    ll cnt=0;
    for(ll i=1;i<n;++i)
    {
        if(t[i]=='B')
        {
            if(t[i+1]=='B')t[i]=t[i+1]='W';
            else t[i]='W',t[i+1]='B';
            ans[++cnt]=i;
        }
    }
    if(t[n]=='B')return INF;
    else return cnt;
}
int main()
{
    n=read();
    scanf("%s",a+1);
    for(ll i=1;i<=n;++i)t[i]=a[i];
    ll res1=work();
    for(ll i=1;i<=n;++i)t[i]=(a[i]=='B'?'W':'B');
    ll res2=work();
    if(res2<res1)
    {
        printf("%lld\n",res2);
        for(ll i=1;i<=res2;++i)printf("%lld ",ans[i]);
    }
    else
    {
        if(res1==INF)
        {
            puts("-1");
            return 0;
        }
        for(ll i=1;i<=n;++i)t[i]=a[i];
        res1=work();
        printf("%lld\n",res1);
        for(ll i=1;i<=res1;++i)printf("%lld ",ans[i]);
    }
    return 0;
}
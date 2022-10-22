#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<50;
#define MAXN 500011
char s[MAXN];
ll cn[MAXN],cb[MAXN],n,maxl;
ll f(ll nown,ll nowb)
{
    if(nown+nowb==0)return 1e18;
    ll res=0;
    for(int i=1;i<=n;++i)
    {
        if(nown>=cn[i])
        {
            if(nowb>=cb[i])umax(res,max(nown-cn[i],nowb-cb[i]));
            else umax(res,(nown-cn[i])+(cb[i]-nowb));
        }
        else
        {
            if(nowb>=cb[i])umax(res,(cn[i]-nown)+(nowb-cb[i]));
            else umax(res,max(cn[i]-nown,cb[i]-nowb));
        }
    }
    return res;
}
ll g(ll nown,bool flag=0)
{
    ll l=0,r=maxl;
    while(r-l>3)
    {
        ll mid1=(l+r-1)>>1,mid2=mid1+2;
        if(f(nown,mid1)<f(nown,mid2))r=mid2;
        else l=mid1;
    }
    ll res=f(nown,l);
    for(int i=l+1;i<=r;++i)umin(res,f(nown,i));
    if(flag)
    {
        for(int i=l;i<=r;++i)
            if(f(nown,i)==res)
            {
                for(int j=1;j<=i;++j)putchar('B');
                break;
            }
    }
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        scanf("%s",s+1);
        ll l=strlen(s+1);
        for(int j=1;j<=l;++j)
            if(s[j]=='N')++cn[i];
            else ++cb[i];
        umax(maxl,l);
    }
    ll l=0,r=maxl;
    while(r-l>3)
    {
        ll mid1=(l+r-1)>>1,mid2=mid1+2;
        //printf("G(%lld)=%lld,G(%lld)=%lld\n",mid1,g(mid1),mid2,g(mid2));
        if(g(mid1)<g(mid2))r=mid2;
        else l=mid1;
    }
    ll res=g(l);
    for(int i=l+1;i<=r;++i)umin(res,g(i));
    printf("%lld\n",res);
    for(int i=l;i<=r;++i)
        if(g(i)==res)
        {
            for(int j=1;j<=i;++j)putchar('N');
            g(i,1);
            return 0;
        }
    
    return 0;
}
//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<28;
/**********/
#define MAXN 500011
ll p[MAXN],n,m,x,a,y,b;
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read();for(ll i=1;i<=n;++i)p[i]=read()/100;
        std::sort(p+1,p+n+1),std::reverse(p+1,p+n+1);
        for(ll i=1;i<=n;++i)p[i]+=p[i-1];
        x=read(),a=read(),y=read(),b=read();
        if(x<y)std::swap(x,y),std::swap(a,b);
        m=read();
        ll ans=-1,c0=0,c1=0,c2=0;
        for(ll i=1;i<=n;++i)
        {
            if(i%a==0)
            {
                if(i%b==0)++c0;
                else ++c1;
            }
            else if(i%b==0)++c2;
            if(p[c0]*(x+y)+(p[c0+c1]-p[c0])*x+(p[c0+c1+c2]-p[c0+c1])*y>=m){ans=i;break;}
        }
        printf("%lld\n",ans);
    }
}
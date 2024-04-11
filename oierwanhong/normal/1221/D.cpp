//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 300011
ll f[MAXN][3],a[MAXN];
int main()
{
    ll task=read();
    a[0]=-INF;
    while(task--)
    {
        ll n=read();
        for(ll i=1;i<=n;++i)
        {
            a[i]=read();ll v=read();
            for(ll j=0;j<=2;++j)
            {
                f[i][j]=INF;
                for(ll k=0;k<=2;++k)
                    if(a[i-1]+k!=a[i]+j)umin(f[i][j],f[i-1][k]+j*v);
            }
        }
        printf("%lld\n",min(min(f[n][0],f[n][1]),f[n][2]));
    }
}
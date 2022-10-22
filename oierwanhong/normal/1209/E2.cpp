//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define MAXM 2011
ll a[13][MAXM];
pll b[MAXM];
ll f[MAXM][1<<12],g[1<<12];
int main()
{
    ll task=read();
    while(task--)
    {
        memset(f,0,sizeof f);
        memset(a,0,sizeof a);memset(b,0,sizeof b);
        ll n=read(),m=read();
        for(ll i=0;i<m;++i)b[i].second=i;
        for(ll i=0;i<n;++i)
            for(ll j=0;j<m;++j)a[i][j]=read(),umax(b[j].first,a[i][j]);
        std::sort(b,b+m);std::reverse(b,b+m);
        umin(m,n);
        ll all=(1<<n)-1;
        for(ll i=0;i<m;++i)
        {
            for(ll s=0;s<=all;++s)
            {
                g[s]=0;
                for(ll x=0;x<n;++x)
                {
                    ll t=0;
                    for(ll y=0;y<n;++y)
						if(s&(1<<y))t+=(a[(x+y)%n][b[i].second]);
                    umax(g[s],t);
                }
            }
            for(ll s=0;s<=all;++s)
                for(ll t=s;;t=(t-1)&s)
                {
                	if(i>0)umax(f[i][s],f[i-1][t]+g[s^t]);
                	else f[i][s]=g[s^t];
                    if(!t)break;
                }
        }
        printf("%lld\n",f[m-1][all]);
    }
}
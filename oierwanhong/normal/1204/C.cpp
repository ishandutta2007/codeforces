//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 211
#define MAXM 1000011
ll dis[MAXN][MAXN],p[MAXM],ans[MAXM];
void Floyd(ll n)
{
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
                umin(dis[i][j],dis[i][k]+dis[k][j]);
}
char a[MAXN];
int main()
{
    memset(dis,0x3f,sizeof dis);
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",a+1);
        for(ll j=1;j<=n;++j)
            if(a[j]=='1')dis[i][j]=1;
    }
    Floyd(n);
    for(ll i=1;i<=n;++i)dis[i][i]=dis[0][0];
    ll m=read(),cnt=0;
    for(ll i=1;i<=m;++i)p[i]=read();
    ll pre=1,cost=0;ans[++cnt]=p[1];
    for(ll i=2;i<=m;++i)
    	if(dis[p[pre]][p[i]]!=i-pre)
    	{
    		ans[++cnt]=p[i-1];
    		pre=i-1;
		}
    ans[++cnt]=p[m];
    printf("%lld\n",cnt);
    for(ll i=1;i<=cnt;++i)printf("%lld ",ans[i]);
    return 0;
}
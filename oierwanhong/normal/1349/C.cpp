//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
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
const ll INF=1ll<<58;
/**********/
#define MAXN 1011
bool a[MAXN][MAXN];
ll f[MAXN][MAXN];
char s[511];
const ll mx[]={0,1,0,-1},my[]={1,0,-1,0};
pll q[MAXN*MAXN];
int main()
{
    ll n=read(),m=read(),Q=read();
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",s+1);
        for(ll j=1;j<=m;++j)a[i][j]=(s[j]=='1');
    }
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
            for(ll op=0;op<4;++op)
            {
                ll vx=i+mx[op],vy=j+my[op];
                if(vx>0&&vx<=n&&vy>0&&vy<=m&&a[vx][vy]==a[i][j])f[vx][vy]=f[i][j]=1;
            }
    ll h=1,t=1;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
            if(f[i][j])q[t++]=pll(i,j);
    while(h<t)
    {
        ll x=q[h].first,y=q[h].second;++h;
        for(ll op=0;op<4;++op)
            {
                ll vx=x+mx[op],vy=y+my[op];
                if(vx>0&&vx<=n&&vy>0&&vy<=m&&!f[vx][vy])
				{
					f[vx][vy]=f[x][y]+1;q[t++]=pll(vx,vy);
				}
            }
    }
    while(Q--)
    {
        ll x=read(),y=read(),k=read();
        if(!f[x][y]||f[x][y]>k)puts(a[x][y]?"1":"0");
        else
        {
        	if((k-f[x][y]+1)&1)puts(a[x][y]?"0":"1");
        	else puts(a[x][y]?"1":"0");
		}
        
    }
}
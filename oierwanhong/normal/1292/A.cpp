//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 200011
bool a[3][MAXN];
const ll mx[]={-1,-1,-1,1,1,1},my[]={-1,0,1,-1,0,1};
int main()
{
    ll n=read(),m=read(),tot=0;
    while(m--)
    {
        ll x=read(),y=read();
        if(a[x][y])
        {
            for(ll i=0;i<6;++i)
            {
                ll vx=x+mx[i],vy=y+my[i];
                if(vx>0&&vx<=2&&vy>0&&vy<=n&&a[vx][vy])--tot;
            }
            a[x][y]^=1;
        }
        else
        {
            for(ll i=0;i<6;++i)
            {
                ll vx=x+mx[i],vy=y+my[i];
                if(vx>0&&vx<=2&&vy>0&&vy<=n&&a[vx][vy])++tot;
            }
            a[x][y]^=1;
        }
        puts(tot?"NO":"YES");
    }
    return 0;
}
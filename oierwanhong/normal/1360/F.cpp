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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 13
char a[MAXN][MAXN],b[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),m=read();
        for(ll i=1;i<=n;++i)scanf("%s",a[i]+1);
        bool success=0;
        for(ll x=1;x<=m;++x)
        {
            for(ll c=0;c<26;++c)
            {
                ll cnt=0,fail=0;
                for(ll i=2;i<=n;++i)
                {
                	cnt=0;
                    for(ll j=1;j<=m;++j)
                        if((j==x&&a[i][j]!=c+'a')||(j!=x&&a[i][j]!=a[1][j]))++cnt;
                    if(cnt>1)fail=1;
                }
                if(!fail)
                {
                    success=1;
                    for(ll j=1;j<=m;++j)putchar(j==x?c+'a':a[1][j]);
                    puts("");
                    x=m+1;c=26;
                }
            }
        }
        if(!success)puts("-1");
    }
    return 0;
}
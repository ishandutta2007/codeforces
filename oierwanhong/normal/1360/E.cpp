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
#define MAXN 51
char a[MAXN][MAXN];
bool f[MAXN][MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read();
        bool fail=0;
        for(ll i=1;i<=n;++i)scanf("%s",a[i]+1);
        for(ll i=1;i<=n;++i)f[i][n]=(a[i][n]=='1'),f[n][i]=(a[n][i]=='1');
        for(ll i=n-1;i;--i)
            for(ll j=n-1;j;--j)
            {
                f[i][j]=0;
                if(a[i][j]=='0')continue;
                f[i][j]=f[i+1][j]|f[i][j+1];
                if(!f[i][j])fail=1;
            }
        puts(fail?"NO":"YES");
    }
}
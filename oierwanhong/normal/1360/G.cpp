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
#define MAXN 55
ll f[MAXN][MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        memset(f,0,sizeof f);
        ll n=read(),m=read(),a=read(),b=read();
        if(n*a!=m*b){puts("NO");continue;}
        for(ll i=0;i<n;++i)
        	for(ll j=0;j<a;++j)
        		f[i][(i*a+j)%m]=1;
        puts("YES");
        for(ll i=0;i<n;++i)
        {
        	for(ll j=0;j<m;++j)putchar(f[i][j]+'0');
        	puts("");
		}
    }
    return 0;
}
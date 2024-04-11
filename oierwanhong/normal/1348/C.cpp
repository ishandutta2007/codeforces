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
#define MAXN 100011
char a[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),k=read();scanf("%s",a+1);
        std::sort(a+1,a+n+1);
        if(a[k]!=a[1])putchar(a[k]);
        else
        {
            if(a[k+1]!=a[n])
            {
                putchar(a[1]);
                for(ll i=k+1;i<=n;++i)putchar(a[i]);
            }
            else
            {
                putchar(a[1]);
                for(ll i=k+1;i<=n;i+=k)putchar(a[i]);
            }
        }
        puts("");
    }
}
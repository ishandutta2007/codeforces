//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
#define MAXN 500011
#define MAXM 711
ll c[MAXM][MAXM],a[MAXN];
int main()
{
    ll q=read();
    while(q--)
    {
        ll op=read(),x=read(),y=read();
        if(op==1)
        {
            a[x]+=y;
            for(ll i=1;i<MAXM;++i)c[i][x%i]+=y;
        }
        else
        {
            if(x<MAXM)printf("%lld\n",c[x][y]);
            else
            {
                ll s=0;
                for(ll i=y;i<MAXN;i+=x)s+=a[i];
                printf("%lld\n",s);
            }   
        }
    }
    return 0;
}
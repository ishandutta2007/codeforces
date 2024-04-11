//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
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
#define MAXN 20
ll f[1<<MAXN],g[MAXN][1<<MAXN],cnt[MAXN][MAXN];
char a[500011];
int main()
{
    ll n=read(),m=read();scanf("%s",a);
    for(ll i=0;i+1<n;++i)
        ++cnt[a[i]-'a'][a[i+1]-'a'],++cnt[a[i+1]-'a'][a[i]-'a'];
    for(ll i=0;i<m;++i)cnt[i][i]=0;
    memset(f,0x3f,sizeof f);
    ll all=(1<<m)-1;
    f[0]=0;
    for(ll s=1;s<=all;++s)
    {
        ll x=0;
        for(ll i=0;i<m;++i)
            if(s&(1<<i)){x=i;break;}
        for(ll i=0;i<m;++i)
        {
            g[i][s]=g[i][s^(1<<x)]+cnt[i][x];
        }
    }
    for(ll s=1;s<=all;++s)
    {
        ll pos=0;
        for(ll i=0;i<m;++i)
            if(s&(1<<i))++pos;
        for(ll i=0;i<m;++i)
            if(s&(1<<i))umin(f[s],f[s^(1<<i)]+pos*(g[i][s]-g[i][all^s]));
    }
    printf("%lld\n",f[all]);
}
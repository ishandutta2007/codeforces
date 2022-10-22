//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 100011
ll n;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
}t[26];
char a[MAXN];
int main()
{
    scanf("%s",a+1);
    n=strlen(a+1);
    for(ll i=1;i<=n;++i)t[a[i]-'a'].modify(i,1);
    ll q=read();
    while(q--)
    {
        ll op=read();
        if(op==1)
        {
            ll pos=read();char c;scanf("%c",&c);
            t[a[pos]-'a'].modify(pos,-1);
            t[c-'a'].modify(pos,1);
            a[pos]=c;
        }
        else
        {
            ll l=read(),r=read(),cnt=0;
            for(ll i=0;i<26;++i)cnt+=bool(t[i].Qsum(r)-t[i].Qsum(l-1));
            printf("%lld\n",cnt);
        }
        
    }
}
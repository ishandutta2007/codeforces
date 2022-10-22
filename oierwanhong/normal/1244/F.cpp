//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
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
#define MAXN 500011
ll t[MAXN];char a[MAXN];
std::queue<ll>q;
int main()
{
    memset(t,-1,sizeof t);
    ll n=read(),k=read();scanf("%s",a);
    for(ll i=0;i<n;++i)
        if(a[i]==a[(i-1+n)%n]||a[i]==a[(i+1)%n])
        {
            t[i]=0;q.push(i);
        }
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        ll v=(u-1+n)%n;
        if(t[v]==-1)t[v]=t[u]+1,q.push(v);
        v=(u+1)%n;
        if(t[v]==-1)t[v]=t[u]+1,q.push(v);
    }
    for(ll i=0;i<n;++i)
    {
        ll x=(t[i]==-1?k:min(t[i],k));
        if(x&1)putchar(a[i]=='W'?'B':'W');
        else putchar(a[i]=='W'?'W':'B');
    }
}
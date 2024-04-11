//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define MAXK 16
#define MAXN 10011
ll a[MAXK][MAXN],to[MAXK*MAXN],len[MAXK],vis[MAXK*MAXN];
std::map<ll,ll>p;
ll compress(ll x,ll y){return (x-1)*5000+y;}
bool g[1<<MAXK];
ll f[1<<MAXK];
ll begin[1<<MAXK],cur=0;
void dfs(ll u)
{
	++cur;
    ll v=u,s=0;
    do
    {
    	if(s&(1<<((v-1)/5000)))return;
    	vis[v]=cur,s|=(1<<((v-1)/5000)), v=to[v];
	}while(vis[v]!=cur&&v);
	u=v;
	s=0;
	do
	{
		s|=(1<<((v-1)/5000)), v=to[v];
	}while(u!=v&&v);
    if(!v)return;
	g[s]=1,begin[s]=u;
}
pll ans[MAXK];
int main()
{
    ll k=read(),sum=0,all=(1<<k)-1;
    for(ll i=1;i<=k;++i)
    {
        len[i]=read();
        for(ll j=1;j<=len[i];++j)
        {
            a[i][j]=read();
            p[a[i][j]]=compress(i,j);
            sum+=a[i][j];
        }
    }
    if(sum%k)return puts("NO")&0;
    for(ll i=1;i<=k;++i)
    {
        ll s=0;
        for(ll j=1;j<=len[i];++j)s+=a[i][j];
        if(sum/k==s){all^=1<<(i-1);continue;}
        for(ll j=1;j<=len[i];++j)
			to[compress(i,j)]=p[sum/k-(s-a[i][j])];
    }
    for(ll i=1;i<=k;++i)
        for(ll j=1;j<=len[i];++j)
            dfs(compress(i,j));
    f[0]=1;
    for(ll s=1;s<=all;++s)
        for(ll t=s;t;t=(t-1)&s)
            if(f[s^t]&&g[t])f[s]=t;
    ll s=all;
    if(!f[s])return puts("NO")&0;
    puts("YES");
    while(s)
    {
        ll t=f[s],u=begin[t],v=u;
        do
        {
            ll p=to[v];
            ans[(p-1)/5000+1]=pll((p-1)%5000+1,(v-1)/5000+1);
            v=p;
        }while(v!=u);
        s^=t;
    }
    for(ll i=1;i<=k;++i)
    	if(!ans[i].second)printf("%lld %lld\n",a[i][1],i);
		else printf("%lld %lld\n",a[i][ans[i].first],ans[i].second);
    return 0;
}
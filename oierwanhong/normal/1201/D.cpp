//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define MAXN 200011
ll s[MAXN],minv[MAXN],maxv[MAXN],f[MAXN][2];
ll mincol,maxcol,n,m,k,q;
ll dis(ll a,ll b)
{
    if(a<b)std::swap(a,b);
    ll res=INF;
    if(b<=maxcol)
    {
        ll p=*std::lower_bound(s+1,s+q+1,b);
        umin(res,abs(p-b)+abs(p-a));
    }
    if(a>=mincol)
    {
        ll p=*(std::upper_bound(s+1,s+q+1,a)-1);
        umin(res,abs(p-b)+abs(p-a));
    }
    return res;
}
int main()
{
    n=read(),m=read(),k=read(),q=read();
    for(ll i=1;i<=n;++i)minv[i]=m+1;
    for(ll i=1;i<=k;++i)
    {
        ll x=read(),y=read();
        umin(minv[x],y),umax(maxv[x],y);
    }
    for(ll i=1;i<=q;++i)s[i]=read();
    std::sort(s+1,s+q+1);
    mincol=s[1],maxcol=s[q];
    if(!maxv[1])maxv[1]=minv[1]=1;
    else f[1][0]=maxv[1]+maxv[1]-minv[1]-1,f[1][1]=maxv[1]-1;
    ll l=1,r=2;
    while(l<n)
    {
    	while(r<=n&&!maxv[r])++r;
    	if(r>n){printf("%lld",min(f[l][0],f[l][1]));return 0;}
    	f[r][0]=min(f[l][0]+dis(minv[l],maxv[r]),f[l][1]+dis(maxv[l],maxv[r]))+maxv[r]-minv[r]+r-l;
        f[r][1]=min(f[l][0]+dis(minv[l],minv[r]),f[l][1]+dis(maxv[l],minv[r]))+maxv[r]-minv[r]+r-l;
        l=r;++r;
	}
    printf("%lld",min(f[l][0],f[l][1]));
    return 0;
}
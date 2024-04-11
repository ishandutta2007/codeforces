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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 3000011
char a[MAXN],b[MAXN];
bool vis[MAXN];
ll n,m,s[MAXN],c[MAXN];
ll get(ll x,ll y)
{
	s[0]=c[0]=0;
	if(x<1||y<1||x>n||y>m)return 0;
	return (x-1)*m+y;
}
ll Qsum(ll x1,ll y1,ll x2,ll y2)
{
    //s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]
    return s[get(x2,y2)]-s[get(x1-1,y2)]-s[get(x2,y1-1)]+s[get(x1-1,y1-1)];
}
bool check(ll k)
{
	//printf("try %lld\n",k);
    for(ll i=1;i<=n*m;++i)vis[i]=0,c[i]=0;
    ll L=k<<1|1;
    for(ll i=L;i<=n;++i)
        for(ll j=L;j<=m;++j)
            if(Qsum(i-L+1,j-L+1,i,j)==L*L)
            {
                //++c[i-L+1][j-L+1],--c[i-L+1][j+1],--c[i+1][j-L+1],++c[i+1][j+1]
                ++c[get(i-L+1,j-L+1)],--c[get(i-L+1,j+1)],--c[get(i+1,j-L+1)],++c[get(i+1,j+1)];
                //printf("Cover (%lld,%lld) (%lld,%lld)\n",i-L+1,j-L+1,i,j);
            }
    bool flag=0;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
        {
            c[get(i,j)]+=c[get(i-1,j)]+c[get(i,j-1)]-c[get(i-1,j-1)];
            if(a[get(i,j)]=='X'&&!c[get(i,j)])return 0;
        }
    return 1;
}
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",b+1);
        for(ll j=1;j<=m;++j)
		{
			a[get(i,j)]=b[j];
			s[get(i,j)]+=s[get(i-1,j)]+s[get(i,j-1)]-s[get(i-1,j-1)]+(b[j]=='X');
			//printf("%lld ",s[get(i,j)]);
		}
    }
    un l=0,r=min(n,m);
    while(l<r)
    {
        un mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    printf("%u\n",r);
    check(r);
    ll L=r<<1|1;
    for(ll i=1;i<=n;++i)
    {
    	for(ll j=1;j<=m;++j)
    		if(i>r&&j>r&&i<=n-r&&j<=m-r &&Qsum(i-r,j-r,i+r,j+r)==L*L)putchar('X');
    		else putchar('.');
    	puts("");
	}
    	
    return 0;
}
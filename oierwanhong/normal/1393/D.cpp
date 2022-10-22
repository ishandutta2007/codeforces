#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
#define MAXN 2511
char a[MAXN][MAXN];
int up[MAXN][MAXN],down[MAXN][MAXN],l[MAXN][MAXN],r[MAXN][MAXN];
int main()
{
    int n=read(),m=read();ll ans=0;
    for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
            if(a[i-1][j]==a[i][j])up[i][j]=up[i-1][j]+1;
            else up[i][j]=1;
        for(int i=n;i;--i)
            if(a[i+1][j]==a[i][j])down[i][j]=down[i+1][j]+1;
            else down[i][j]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            if(a[i][j-1]==a[i][j])l[i][j]=min(l[i][j-1]+1,min(up[i][j],down[i][j]));
            else l[i][j]=1;
        for(int j=m;j;--j)
            if(a[i][j+1]==a[i][j])r[i][j]=min(r[i][j+1]+1,min(up[i][j],down[i][j])),ans+=min(l[i][j],r[i][j]);
            else r[i][j]=1,++ans;
    }
    printf("%lld",ans);
    return 0;
}
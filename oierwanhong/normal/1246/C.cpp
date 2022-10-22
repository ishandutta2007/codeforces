//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
#define MAXN 2011
ll n,m,rowsum[MAXN][MAXN],colsum[MAXN][MAXN];
ll sumD[MAXN][MAXN],sumR[MAXN][MAXN];
const ll mod=ll(1e9+7);
char a[MAXN][MAXN];
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        scanf("%s",a[i]+1);
        for(ll j=m;j;--j)rowsum[i][j]=rowsum[i][j+1]+(a[i][j]=='R');
    }
    for(ll i=n;i;--i)
        for(ll j=1;j<=m;++j)colsum[i][j]=colsum[i+1][j]+(a[i][j]=='R');
    sumD[1][1]=sumR[1][1]=1;
    if(n==1&&m==1)return puts("1")&0;
    ll ans=0;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
        {
            if(i==1&&j==1)continue;
            //D[i][j]= sum{R[i][k]|(rowsum[i][k]<=m-j)}
            un l=1,r=j;
            while(l<r)
            {
                un mid=(l+r)>>1;
                if(rowsum[i][mid+1]<=m-j)r=mid;
                else l=mid+1;
            }
            ll cur=sumD[i][j-1]-sumD[i][l-1];
            if(i==n&&j==m)ans=(ans+cur)%mod;
            sumR[i][j]=(sumR[i-1][j]+cur)%mod;
            l=1,r=i;
            while(l<r)
            {
                un mid=(l+r)>>1;
                if(colsum[mid+1][j]<=n-i)r=mid;
                else l=mid+1;
            }
            cur=sumR[i-1][j]-sumR[l-1][j];
            if(i==n&&j==m)ans=(ans+cur)%mod;
            sumD[i][j]=(sumD[i][j-1]+cur)%mod;
        }
    printf("%lld",(ans+mod)%mod);
}
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
#define MAXN 15
ll num[MAXN][MAXN],to[MAXN*MAXN];
pll pos[MAXN*MAXN];
double f[MAXN*MAXN];
int main()
{
    for(ll i=1;i<=10;++i)
        for(ll j=1;j<=10;++j)
        {
            ll h=read(),&cur=num[i][j];
            if(i&1)cur=(i-1)*10+j;
            else cur=i*10-j+1;
            pos[cur]=pll(i,j);
            to[cur]=num[i-h][j];
        }
    f[1]=0;
    for(ll i=2;i<=100;++i)
    {
        if(i<=6)
        {
            double s=1;
            for(ll j=1;j<i;++j)s+=f[i-j]/6;
            f[i]=6*s/(i-1);
        }
        else
        {
            double s=1;
            for(ll j=1;j<=6;++j)s+=std::min(f[i-j],f[to[i-j]])/6;
            f[i]=s;
        }
    }
    printf("%.6f",f[100]);
}
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
#define MAXN 200011
char a[2][MAXN];
ll n;
bool dfs(ll x,ll y,ll op)
{
    if(y>n)return x==1;
    if(a[x][y]>'2')
        if(!op)return dfs(!x,y,1);
        else return dfs(x,y+1,0);
    else
        if(!op)return dfs(x,y+1,0);
        else return 0;
}
int main()
{
    ll t=read();
    while(t--)
    {
        n=read();
        for(ll i=0;i<2;++i)scanf("%s",a[i]+1);
        puts(dfs(0,1,0)?"YES":"NO");
    }
}
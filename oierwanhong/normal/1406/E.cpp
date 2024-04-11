//send again By Luogu
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll t){if(t>a)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

#define MAXN 100011
ll pri[MAXN];
bool vis[MAXN];
int sieve(int n)
{
    int cnt=0;
    for(int i=2;i<=n;++i)
    {
        if(!vis[i])pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
    return cnt;
}
int main()
{
    ll n=read(),m=sieve(n),R=n;
    int pos=std::upper_bound(pri+1,pri+m+1,sqrt(n))-pri,pre=pos-1;
    ll res=1;
    for(ll i=pos;i<=m;++i)
    {
        R-=n/pri[i];
        std::cout<<"B "<<pri[i]<<std::endl;
        int y=read();
        if(i-pre==100||i==m)
        {
            std::cout<<"A 1"<<std::endl;
            int y=read();
            if(y!=R)
            {
                for(int j=pre+1;j<=i;++j)
                {
                    std::cout<<"A "<<pri[j]<<std::endl;
                    int y=read();
                    if(y){res*=pri[j];goto small;}
                }
                goto small;
            }
            pre=i;
        }
    }
    small:
    for(ll i=1;i<pos;++i)
    {
        ll x=pri[i];
        std::cout<<"B "<<x<<std::endl;
        int y=read();
        while(x<=n)
        {
            std::cout<<"A "<<x<<std::endl;
            if(read())x*=pri[i],res*=pri[i];
            else break;
        }
    }
    std::cout<<"C "<<res<<std::endl;
    return 0;
}
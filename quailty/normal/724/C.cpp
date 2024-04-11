#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
ll m[10],a[10];
bool solve(ll &m0,ll &a0,ll m,ll a)
{
    ll x,y,g=exgcd(m0,m,x,y);
    if((a-a0)%g)return 0;
    x*=(a-a0)/g;
    x%=m/g;
    a0=(x*m0+a0);
    m0*=m/g;
    a0%=m0;
    if(a0<0)a0+=m0;
    return 1;
}
bool MLES(ll &m0,ll &a0,int n)
{
    m0=1,a0=0;
    for(int i=0;i<n;i++)
        if(!solve(m0,a0,m[i],a[i]))
            return 0;
    return 1;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ll res=INF;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                ll m0,a0;
                ::m[0]=2*n;
                ::a[0]=(i ? x : 2*n-x);
                ::m[1]=2*m;
                ::a[1]=(j ? y : 2*m-y);
                if(MLES(m0,a0,2))
                    res=min(res,a0);
            }
        printf("%I64d\n",(res<INF ? res : -1));
    }
    return 0;
}
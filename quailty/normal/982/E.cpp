#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}

bool solve(ll &m0,ll &a0,ll m,ll a)
{
    ll x,y,g=exgcd(m0,m,x,y);
    if(abs(a-a0)%g)return 0;
    x*=(a-a0)/g;
    x%=m/g;
    a0+=x*m0;
    m0*=m/g;
    a0=(a0%m0+m0)%m0;
    return 1;
}

int main()
{
    ll n,m,x,y,vx,vy;
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&vx,&vy);
    if(vx==0)
    {
        if(x==0 || x==n)printf("%lld %lld\n",x,(vy>0)*m);
        else printf("-1\n");
        return 0;
    }
    if(vy==0)
    {
        if(y==0 || y==m)printf("%lld %lld\n",(vx>0)*n,y);
        else printf("-1\n");
        return 0;
    }
    ll mi=(1LL<<62)-1,ty=-1;
    for(int _=0;_<4;_++)
    {
        ll r0=2*n,a0=(vx*((_/2)*n-x)+2*n)%(2*n);
        ll r1=2*m,a1=(vy*((_%2)*m-y)+2*m)%(2*m);
        if(solve(r0,a0,r1,a1) && mi>a0)mi=a0,ty=_;
    }
    if(ty<0)printf("-1\n");
    else
    {
        x+=mi*vx,y+=mi*vy;
        x=(x%(2*n)+2*n)%(2*n);
        y=(y%(2*m)+2*m)%(2*m);
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
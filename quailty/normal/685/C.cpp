#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=100005;
const ll INF=6000000000000000000LL;
const ll cut[2][4]={{0,0,0,0},{3,1,1,1}};
ll x[MAXN],y[MAXN],z[MAXN],res[4];
ll div2(ll x,ll t)
{
    if(x>=0)return (x+t)/2;
    else return (x+t-1)/2;
}
ll med(ll x,ll y)
{
    return x/2+y/2+(x%2+y%2)/2;
}
bool check(int n,ll m)
{
    ll up[4]={INF,INF,INF,INF};
    ll dw[4]={-INF,-INF,-INF,-INF};
    for(int i=0;i<n;i++)
    {
        dw[0]=max(dw[0],+x[i]+y[i]+z[i]-m);
        dw[1]=max(dw[1],-x[i]+y[i]+z[i]-m);
        dw[2]=max(dw[2],+x[i]-y[i]+z[i]-m);
        dw[3]=max(dw[3],+x[i]+y[i]-z[i]-m);
        up[0]=min(up[0],+x[i]+y[i]+z[i]+m);
        up[1]=min(up[1],-x[i]+y[i]+z[i]+m);
        up[2]=min(up[2],+x[i]-y[i]+z[i]+m);
        up[3]=min(up[3],+x[i]+y[i]-z[i]+m);
    }
    ll tu[4],td[4],tmp[4];
    for(int _=0;_<2;_++)
    {
        for(int i=0;i<4;i++)
        {
            tu[i]=div2(up[i]-cut[_][i],0);
            td[i]=div2(dw[i]-cut[_][i],1);
        }
        bool isok=1;
        for(int i=0;i<4;i++)
            isok&=(td[i]<=tu[i]);
        tmp[0]=0;
        for(int i=1;i<4;i++)
            tmp[0]+=(tmp[i]=td[i]);
        isok&=(tmp[0]<=tu[0]);
        for(int i=1;i<4;i++)
            if(tmp[0]<td[0])
            {
                ll add=min(td[0]-tmp[0],tu[i]-td[i]);
                tmp[0]+=add;
                tmp[i]+=add;
            }
        isok&=(tmp[0]>=td[0]);
        if(isok)
        {
            for(int i=1;i<4;i++)
                (tmp[i]<<=1)|=_;
            for(int i=1;i<4;i++)
                res[i]=med(tmp[i%3+1],tmp[(i+1)%3+1]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
        ll l=0LL,r=3000000000000000000LL;
        while(l<r)
        {
            ll m=med(l,r);
            if(check(n,m))r=m;
            else l=m+1;
        }
        check(n,l);
        for(int i=1;i<4;i++)
            printf("%I64d ",res[i]);
        printf("\n");
    }
    return 0;
}
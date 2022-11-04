#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll c1,c2,x,y;
bool judge(ll k)
{
    ll t1=c1,t2=c2;
    if(t1>k-k/x)return 0;
    t1-=min(t1,k/y-k/(x*y));
    return t1+t2<=k-k/y;
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&c1,&c2,&x,&y);
    ll l=1,r=(1LL<<40);
    while(l<r)
    {
        ll m=(l+r)>>1;
        if(judge(m))r=m;
        else l=m+1;
    }
    printf("%I64d\n",l);
    return 0;
}
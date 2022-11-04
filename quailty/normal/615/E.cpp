#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int d[6][2]=
{
    {-1,2},{-2,0},{-1,-2},
    {1,-2},{2,0},{1,2}
};
int main()
{
    ll n;
    scanf("%I64d",&n);
    ll l=0,r=1000000000;
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        if(3*m*(m+1)<=n)l=m;
        else r=m-1;
    }
    ll x=2*l,y=0;
    n-=3*l*(l+1);
    x+=min(n,1LL)*d[5][0],y+=min(n,1LL)*d[5][1],n=max(n-1,0LL);
    for(int i=0;i<6;i++)
    {
        ll t=l+(i>0 && i<5);
        x+=min(n,t)*d[i][0],y+=min(n,t)*d[i][1],n=max(n-t,0LL);
    }
    printf("%I64d %I64d\n",x,y);
    return 0;
}
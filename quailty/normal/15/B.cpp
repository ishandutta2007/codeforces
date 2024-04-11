#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n,m,x[2],y[2];
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<2;i++)
            scanf("%lld%lld",&x[i],&y[i]);
        ll tx=abs(x[0]-x[1]),ty=abs(y[0]-y[1]);
        printf("%lld\n",n*m-2*(n-tx)*(m-ty)+max(0LL,n-2*tx)*max(0LL,m-2*ty));
    }
    return 0;
}
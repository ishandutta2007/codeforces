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
    ll x[2],y[2];
    for(int i=0;i<2;i++)
        scanf("%I64d%I64d",&x[i],&y[i]);
    ll res=0LL;
    if((y[1]-y[0])%2==0)
    {
        res+=(y[1]-y[0])/2*(x[1]-x[0])/2;
        res+=(y[1]-y[0]+2)/2*(x[1]-x[0]+2)/2;
    }
    else res=(y[1]-y[0]+1)/2*(x[1]-x[0]+1);
    printf("%I64d\n",res);
    return 0;
}
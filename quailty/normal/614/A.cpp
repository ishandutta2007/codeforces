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
    ll l,r,k;
    scanf("%I64d%I64d%I64d",&l,&r,&k);
    bool isok=0;
    ll now=1;
    while(1)
    {
        if(now>=l)
        {
            printf("%I64d ",now);
            isok=1;
        }
        if(now>r/k)break;
        now*=k;
    }
    if(!isok)printf("-1");
    return 0;
}
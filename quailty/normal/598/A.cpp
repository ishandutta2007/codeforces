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
        ll n;
        scanf("%I64d",&n);
        ll ans=n*(n+1)/2;
        ll now=1;
        while(now<=n)now<<=1;
        printf("%I64d\n",ans-2*(now-1));
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll res[100005];
int tot=0;
void build()
{
    for(int i=0;i<=60;i++)
    {
        ll t=(1LL<<i)-1;
        for(int j=0;j<i-1;j++)
            res[tot++]=t^(1LL<<j);
    }
    sort(res,res+tot);
}
int main()
{
    build();
    ll a,b;
    scanf("%I64d%I64d",&a,&b);
    printf("%d\n",upper_bound(res,res+tot,b)-lower_bound(res,res+tot,a));
    return 0;
}
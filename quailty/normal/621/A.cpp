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
    int mx=0x3f3f3f3f;
    int n;
    scanf("%d",&n);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        res+=t;
        if(t&1)mx=min(mx,t);
    }
    if(res&1)printf("%I64d",res-mx);
    else printf("%I64d",res);
    return 0;
}
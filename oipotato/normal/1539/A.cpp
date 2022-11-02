#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,x,t;
        scanf("%d%d%d",&n,&x,&t);
        if(t<x)puts("0");
        else
        {
            int num=t/x;
            if(n<num)printf("%lld\n",(LL)n*(n-1)/2);
            else printf("%lld\n",(LL)(n-num)*num+(LL)num*(num-1)/2);
        }
    }
    return 0;
}
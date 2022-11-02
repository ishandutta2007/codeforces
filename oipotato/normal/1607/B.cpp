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
        LL x0,n;scanf("%lld%lld",&x0,&n);
        LL tmp;
        if(!n)tmp=0;
        else
        {
            n--;
            tmp=1+n/4*4;
            if(n%4>=1)tmp-=n/4*4+2;
            if(n%4>=2)tmp-=n/4*4+3;
            if(n%4>=3)tmp+=n/4*4+4;
        }
        if(!(x0&1))tmp=-tmp;
        printf("%lld\n",x0+tmp);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];  
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL n;int a,b;scanf("%lld%d%d",&n,&a,&b);
        if(2*a<=b)printf("%lld\n",a*n);
        else printf("%lld\n",n/2*b+(n&1)*a);
    }
    return 0;
}
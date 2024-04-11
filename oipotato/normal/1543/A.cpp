#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int s[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL a,b;scanf("%lld%lld",&a,&b);
        if(a==b)puts("0 0");
        else printf("%lld %lld\n",abs(a-b),min(a%abs(a-b),abs(a-b)-a%abs(a-b)));
    }
    return 0;
}
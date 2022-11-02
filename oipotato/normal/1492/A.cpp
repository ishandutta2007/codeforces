#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void work(LL p,LL&a)
{
    a=p%a==0?0:a-p%a;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        LL p,a,b,c;
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        work(p,a);work(p,b);work(p,c);
        printf("%lld\n",min(min(a,b),c));
    }
    return 0;
}
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
        LL n;scanf("%lld",&n);
        n<<=1;
        LL len=1;
        for(;n%2==0;n/=2,len*=2);
        LL l=(n-len+1)/2,r=l+len-1;
        printf("%lld %lld\n",l,r);
    }
    return 0;
}
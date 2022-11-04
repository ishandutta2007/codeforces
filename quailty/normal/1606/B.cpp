#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll now=1,res=0;
        while(now<n && now<k)
            now*=2,res++;
        if(now<n)res+=(n-now+k-1)/k;
        printf("%lld\n",res);
    }
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 1000007
using namespace std;
int main()
{
    int n,k; scanf("%d%d",&n,&k);
    long long sum=0,smd=0,need;
    if(n&1) need=0;
    else need=n/2;
    for(int i=0;i<k;i++)
    {
        long long a,b; scanf("%lld%lld",&a,&b);
        sum+=b;
        smd=(smd+a*b)%n;
    }
    if(sum>n) printf("-1");
    if(sum<n) printf("1");
    if(sum==n && smd==need) printf("1");
    if(sum==n && smd!=need) printf("-1");
}
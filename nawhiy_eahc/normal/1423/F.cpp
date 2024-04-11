#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum, n, i, j, k, a, b, x;
main()
{
    for(scanf("%lld %lld", &n, &k);k--;)
    {
        scanf("%lld %lld", &a, &b);
        sum+=a*b;
        x+=b;
    }
    if(x>n)
    {
        puts("-1");
        return 0;
    }
    if(x<n)
    {
        puts("1");
        return 0;
    }
    sum%=n;
    a=(n*(n+1))/2;
    a%=n;
    if(sum!=a)
    {
        puts("-1");
        return 0;
    }
    puts("1");
}
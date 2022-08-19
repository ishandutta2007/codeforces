#include <bits/stdc++.h>
using namespace std;

int n;

long long x, y;

long long z, g;

int main()
{
    scanf("%d%lld", &n, &x);
    z=1;
    while(n--)
    {
        scanf("%lld", &y);
        g=__gcd(z, y);
        z=z*y/g;
        z=__gcd(z, x);
    }
    if (z==x)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;

long long a=1,b=1;

long long mod=1000000007;

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        a*=27;
        a%=mod;
        b*=7;
        b%=mod;
    }
    a-=b;
    a+=mod;
    a%=mod;
    printf("%lld\n", a);
    return 0;
}
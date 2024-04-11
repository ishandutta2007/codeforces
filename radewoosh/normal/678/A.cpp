#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long x;

int main()
{
    scanf("%lld%lld", &n, &k);
    x=(n/k)*k;
    while(x<=n)
    x+=k;
    while(x-k>n)
    x-=k;
    printf("%lld\n", x);
    return 0;
}
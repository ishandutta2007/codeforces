#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long wyn;

int main()
{
    scanf("%lld%lld", &n, &k);
    k=min(k, n/2);
    for (long long i=1; i<=k; i++)
    {
        wyn+=(n-2*i)*2+1;
    }
    printf("%lld\n", wyn);
    return 0;
}
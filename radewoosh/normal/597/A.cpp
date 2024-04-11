#include <bits/stdc++.h>
using namespace std;

long long a, b, k;

int main()
{
    scanf("%lld%lld%lld", &k, &a, &b);
    if (a>0)
    {
        printf("%lld\n", b/k-(a-1)/k);
        return 0;
    }
    if (b<0)
    {
        a*=-1;
        b*=-1;
        swap(a, b);
        printf("%lld\n", b/k-(a-1)/k);
        return 0;
    }
    a*=-1;
    printf("%lld\n", b/k+a/k+1);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long wyn;

int main()
{
    wyn=1000000000;
    wyn*=wyn;
    scanf("%lld%lld%lld", &a, &b, &c);
    if ((a&1)==(b&1))
    wyn=min(wyn, max(a, b));
    if ((a&1)==(c&1))
    wyn=min(wyn, max(a, c));
    if ((c&1)==(b&1))
    wyn=min(wyn, max(c, b));
    printf("%lld\n", wyn);
    return 0;
}
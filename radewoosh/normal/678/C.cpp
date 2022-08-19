#include <bits/stdc++.h>
using namespace std;

long long n;
long long a, b, c, d;

long long wyn;

int main()
{
    scanf("%lld", &n);
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    scanf("%lld", &d);
    if (d>c)
    {
        swap(d, c);
        swap(a, b);
    }
    wyn+=(n/a)*c;
    wyn+=(n/b)*d;
    wyn-=(n/(a*b/__gcd(a, b)))*d;
    printf("%lld\n", wyn);
    return 0;
}
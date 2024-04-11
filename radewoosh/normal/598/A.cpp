#include <bits/stdc++.h>
using namespace std;

int t;

long long n;

long long wyn;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        wyn=n*(n+1);
        wyn/=2;
        for (int i=1; i<=n; i*=2)
        {
            wyn-=2*i;
        }
        printf("%lld\n", wyn);
    }
    return 0;
}
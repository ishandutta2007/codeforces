#include <bits/stdc++.h>
using namespace std;

long long a, b;

int wyn;

long long jed=1;

long long tak;

int main()
{
    scanf("%lld%lld", &a, &b);
    for (long long i=0; (jed<<i)<=b; i++)
    {
        for (long long j=0; j<i; j++)
        {
            tak=2*(jed<<i)-1;
            tak-=(jed<<j);
            if (tak>=a && tak<=b)
            wyn++;
        }
    }
    printf("%d\n", wyn);
    return 0;
}
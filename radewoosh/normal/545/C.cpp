#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;

long long x[100007], h[100007];
long long last=-1000000007;
int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &x[i], &h[i]);
    }
    for (int i=1; i<n; i++)
    {
        if (x[i]-h[i]>last)
        {
            wyn++;
            last=x[i];
            continue;
        }
        if (x[i]+h[i]<x[i+1])
        {
            wyn++;
            last=x[i]+h[i];
            continue;
        }
        last=x[i];
    }
    wyn++;
    printf("%d", wyn);
    return 0;
}
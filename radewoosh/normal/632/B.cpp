#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long sum1[1000007];
long long sum2[1000007];

char wcz[1000007];

long long wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%lld", &tab[i]);
    scanf("%s", wcz+1);
    for (int i=1; i<=n; i++)
    {
        sum1[i]=sum1[i-1];
        sum2[i]=sum2[i-1];
        if (wcz[i]=='A')
        sum1[i]+=tab[i];
        else
        sum2[i]+=tab[i];
    }
    wyn=sum2[n];
    for (int i=1; i<=n; i++)
    wyn=max(wyn, sum2[n]-sum2[i]+sum1[i]);
    for (int i=1; i<=n; i++)
    wyn=max(wyn, sum1[n]-sum1[i-1]+sum2[i-1]);
    printf("%lld\n", wyn);
    return 0;
}
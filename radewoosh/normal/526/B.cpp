#include <iostream>
#include <cstdio>
using namespace std;

int n;
int m;
long long tab[1000007];
long long liczmax[1000007];
long long wyn;

void roz(int v)
{
    if (v>=(m/2))
    return;
    wyn+=max(liczmax[v*2], liczmax[v*2+1])-min(liczmax[v*2], liczmax[v*2+1]);
    roz(v*2);
    roz(v*2+1);
}

int main()
{
    scanf("%d", &n);
    m=(1<<(n+1));
    for (int i=2; i<m; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=m-1; i; i--)
    {
        liczmax[i]=max(liczmax[i*2], liczmax[i*2+1])+tab[i];
    }
    roz(1);
    printf("%lld", wyn);
    return 0;
}
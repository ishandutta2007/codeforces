#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int tab[200007];
int wyn[200007];
int z1[200007];
int z2[200007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        z1[i]=i;
        while(z1[i]>1 && tab[z1[i]-1]>=tab[i])
        {
            z1[i]=z1[z1[i]-1];
        }
    }
    reverse(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        z2[i]=i;
        while(z2[i]>1 && tab[z2[i]-1]>=tab[i])
        {
            z2[i]=z2[z2[i]-1];
        }
    }
    for (int i=1; i<=n; i++)
    {
        wyn[n+1-z2[i]-z1[n+1-i]+1]=max(wyn[n+1-z2[i]-z1[n+1-i]+1], tab[i]);
    }
    for (int i=n; i; i--)
    {
        wyn[i]=max(wyn[i], wyn[i+1]);
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}
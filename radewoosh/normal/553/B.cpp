#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

long long k;

long long dyn[57];

long long d;

int tab[57];

void rek(int v, long long l)
{
    //printf("%d %lld\n", v, l);
    if (v==n+1)
    return;
    for (int i=0; i<=n-v; i++)
    {
        //printf(" %d %lld\n", i, l);
        if (dyn[n-v-i]>l)
        {
            tab[v]=v+i;
            for (int j=v+i; j>v; j--)
            {
                tab[j]=v+(j-(v+i));
            }
            rek(v+i+1, l);
            return;
        }
        l-=dyn[n-v-i];
    }
    //printf("  %d %lld\n", v, l);
}

int main()
{
    d=1000000000;
    d*=d;
    dyn[0]=1;
    dyn[1]=1;
    scanf("%d%lld", &n, &k);
    for (int i=2; i<=n; i++)
    {
        dyn[i]=dyn[i-1]+dyn[i-2];
        //if (i>30)
        //dyn[i]=d;
        //printf("%d %lld\n", i, dyn[i]);
    }
    k--;
    rek(1, k);
    for (int i=1; i<=n; i++)
    printf("%d ", tab[i]);
    return 0;
}
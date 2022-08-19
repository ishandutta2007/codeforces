#include <bits/stdc++.h>
using namespace std;

int n;

long long a, b;
long long t;

char wcz[1000007];

int l, p;

int wyn;

int k;

int tab[1000007];

int czyok(int v, int u)
{
    long long ile=(tab[u]-tab[v-1])*b;
    ile+=min(u-n, n-v)*2*a+max(u-n, n-v)*a;
    ile+=u-v+1;
    //printf("%d %d    %lld\n", v, u, ile);
    return (ile<=t);
}

int main()
{
    scanf("%d%lld%lld%lld", &n, &a, &b, &t);
    scanf("%s", wcz+n);
    for (int i=1; i<n; i++)
    {
        wcz[n-i]=wcz[n+n-i];
    }
    l=1;
    p=n+n-1;
    for (int i=l; i<=p; i++)
    {
        tab[i]=tab[i-1]+(wcz[i]=='w');
    }
    for (int i=n; i<=p; i++)
    {
        k=max(k, i-n);
        while (k<n && czyok(i-k, i))
        {
            k++;
            wyn=max(wyn, k);
            //printf("TAK\n");
        }
        //printf("%d %d\n", i, k);
    }
    printf("%d\n", wyn);
    return 0;
}
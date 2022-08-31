#include <bits/stdc++.h>
using namespace std;

int n, k;

char wcz[1000007];

int tab[1000007];

int bsa, bsb, bss;

int odp(int v, int u)
{
    return tab[u]-tab[v-1];
}

int check(int v)
{
    for (int i=1; i<=n; i++)
    {
        if (wcz[i]=='0' && odp(max(1, i-v), min(n, i+v))>k)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", wcz+1);
    for (int i=1; i<=n; i++)
    {
        tab[i]=wcz[i]-'0';
        tab[i]^=1;
        tab[i]+=tab[i-1];
    }
    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        if (check(bss))
        {
            bsb=bss;
        }
        else
        {
            bsa=bss+1;
        }
    }
    printf("%d\n", bsa);
    return 0;
}
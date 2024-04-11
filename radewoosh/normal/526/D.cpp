#include <bits/stdc++.h>
using namespace std;

int n, k;

char tab[1000007];
int kmp[1000007];

bitset <1000007> ok;

int it;

int o;
int x, y;

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", tab);
    for (int i=n; i; i--)
    {
        tab[i]=tab[i-1];
    }
    tab[0]=0;
    for (long long i=1; i<=n; i++)
    {
        if ((i%k)<(i/k))
        {
            ok[i]=1;
        }
    }
    for (int i=2; i<=n; i++)
    {
        it=kmp[i-1];
        while(it && tab[i]!=tab[it+1])
        it=kmp[it];
        if (tab[i]==tab[it+1])
        kmp[i]=it+1;
    }
    for (int i=1; i<=n; i++)
    {
        o=i-kmp[i];
        x=i/o;
        y=x;
        if (!(i%o))
        {
            y--;
        }
        if (ok[x] || ok[y])
        printf("1");
        else
        printf("0");
    }
    return 0;
}
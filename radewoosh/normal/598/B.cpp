#include <bits/stdc++.h>
using namespace std;

int n, q;

char tab[100007];

char pom[100007];

int l, r, k;

int cel(int v)
{
    v-=k;
    while (v>r)
    v-=(r-l+1);
    while (v<l)
    v+=(r-l+1);
    return v;
}

int main()
{
    scanf("%s", tab+1);
    for (int i=1; 1; i++)
    {
        if (!tab[i])
        {
            n=i-1;
            break;
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d%d", &l, &r, &k);
        k%=(r-l+1);
        for (int i=l; i<=r; i++)
        {
            pom[i]=tab[cel(i)];
        }
        for (int i=l; i<=r; i++)
        {
            tab[i]=pom[i];
        }
    }
    for (int i=1; i<=n; i++)
    {
        printf("%c", tab[i]);
    }
    printf("\n");
    return 0;
}
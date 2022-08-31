#include <bits/stdc++.h>
using namespace std;

int n;
int tab[1000007];
int wyn[1000007];

int l;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i+=2)
    {
        l++;
        wyn[i]=tab[l];
    }
    for (int i=2; i<=n; i+=2)
    {
        l++;
        wyn[i]=tab[l];
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}
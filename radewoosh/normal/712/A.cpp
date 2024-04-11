#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &tab[i]);
    for (int i=1; i<=n; i++)
        printf("%d ", tab[i]+tab[i+1]);
    printf("\n");
    return 0;
}
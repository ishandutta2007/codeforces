#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n;

int tab[1000007];

int ost;

int ileo[1000007];
int ilez[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    if (tab[n]==1)
    {
        printf("NO");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        if (tab[i]==1)
        {
            ost=i;
        }
    }
    if (!ost)
    {
        if (n==1)
        {
            printf("YES\n0");
            return 0;
        }
        if (n==2)
        {
            printf("NO");
            return 0;
        }
    }
    if (n==2)
    {
        printf("YES\n1->0");
        return 0;
    }

    if (tab[n-1]!=1)
    {
        for (int j=n-2; j>=0; j--)
        {
            if (!j)
            {
                printf("NO");
                return 0;
            }
            if (!tab[j])
            {
                ileo[j]++;
                ilez[n-1]++;
                ileo[j+1]++;
                ilez[n-1]++;
                break;
            }
        }
    }

    printf("YES\n");
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=ileo[i]; j++)
        printf("(");
        printf("%d", tab[i]);
        for (int j=1; j<=ilez[i]; j++)
        printf(")");
        if (i<n)
        printf("->");
    }
    return 0;
}
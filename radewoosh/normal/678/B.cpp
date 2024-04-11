#include <bits/stdc++.h>
using namespace std;

int n;

int tab[2000009];

int czy(int v)
{
    if (!(v%400))
    return 1;
    if (!(v%4) && v%100)
    return 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    tab[1]=0;
    for (int i=2; i<=2000007; i++)
    {
        tab[i]=tab[i-1]+365;
        if (czy(i))
        tab[i]++;
        tab[i]%=7;
    }
    for (int i=n+1; 1; i++)
    {
        if (tab[i]==tab[n] && czy(i)==czy(n))
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
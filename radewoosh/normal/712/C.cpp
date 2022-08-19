#include <bits/stdc++.h>
using namespace std;

int x, y;

int tab[4];

int wyn;

int main()
{
    scanf("%d%d", &x, &y);
    tab[1]=y;
    tab[2]=y;
    tab[3]=y;
    while(tab[1]<x || tab[2]<x || tab[3]<x)
    {
        sort(tab+1, tab+4);
        tab[1]=min(x, tab[2]+tab[3]-1);
        wyn++;
    }
    printf("%d\n", wyn);
    return 0;
}
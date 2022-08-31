#include <bits/stdc++.h>
using namespace std;

int n;

int x;
int tab[1000007];

int l=0, p=20000;

long long wyn;

long long v;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        tab[x]++;
    }
    while(l+1<p)
    {
        v=min(tab[l], tab[p]);
        tab[l]-=v;
        tab[l+1]+=v;
        tab[p]-=v;
        tab[p-1]+=v;
        if (!tab[l])
        l++;
        else
        p--;
        wyn+=v;
    }
    printf("%lld\n", wyn);
    return 0;
}
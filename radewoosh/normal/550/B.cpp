#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n;
int l, r, x;

int tab[20];

bitset <50> bity;

int wyn;

int mini;
int maxi;
int sum;

int main()
{
    scanf("%d%d%d%d", &n, &l, &r, &x);
    for (int i=0; i<n; i++)
    scanf("%d", &tab[i]);
    for (int h=0; h<(1<<n); h++)
    {
        bity=h;
        mini=1000000007;
        maxi=-1;
        sum=0;
        for (int i=0; i<n; i++)
        {
            if (bity[i])
            {
                sum+=tab[i];
                mini=min(mini, tab[i]);
                maxi=max(maxi, tab[i]);
            }
        }
        if (maxi-mini>=x && sum>=l && sum<=r)
        {
            wyn++;
        }
    }
    printf("%d", wyn);
    return 0;
}
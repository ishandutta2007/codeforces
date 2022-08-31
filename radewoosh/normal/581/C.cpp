#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

int k;

int wyn;

vector <int> male;

int ladu;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        wyn+=tab[i]/10;
        male.push_back(10-((tab[i]-1+10)%10)-1);
        tab[i]=(tab[i]+9)/10*10;
        ladu+=10-(tab[i]/10);
    }
    sort(male.begin(), male.end());
    for (int i=0; i<male.size(); i++)
    {
        if (male[i] && male[i]<=k)
        {
            k-=male[i];
            wyn++;
        }
    }
    while(k>=10 && ladu)
    {
        k-=10;
        ladu--;
        wyn++;
    }
    printf("%d\n", wyn);
    return 0;
}
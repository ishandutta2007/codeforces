#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[4007];
long long tak[4007];
long long nie[4007];

int v;

vector <int> wek;

vector <int> wyn;

int czy;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld", &tak[i], &nie[i], &tab[i]);
        wek.push_back(i);
    }
    while(!wek.empty())
    {
        czy=0;
        for (int i=0; i<wek.size(); i++)
        {
            v=wek[i];
            if (tab[v]<0)
            {
                for (int j=i+1; j<wek.size(); j++)
                {
                    tab[wek[j]]-=nie[v];
                    swap(wek[j], wek[j-1]);
                }
                czy=1;
                wek.pop_back();
                break;
            }
        }
        if (czy)
        {
            continue;
        }
        for (int i=1; i<wek.size(); i++)
        {
            swap(wek[i], wek[i-1]);
        }
        v=wek.back();
        wek.pop_back();
        for (int i=0; i<wek.size(); i++)
        {
            tab[wek[i]]-=max((long long) 0, tak[v]-i);
        }
        wyn.push_back(v);
    }
    printf("%d\n", (int) wyn.size());
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}
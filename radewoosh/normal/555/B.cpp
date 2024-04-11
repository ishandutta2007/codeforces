#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int m;

pair <long long,long long> tab[1000007];
pair <long long,int> mos[1000007];

pair <pair <long long,long long> , int > zak[1000007];

priority_queue < pair <long long , int > > kol;

int l;

int ok;

int kt[1000007];

int k=1;

pair <long long,int> czyt;

int main()
{
    scanf("%d%d", &n, &m);
    if (m<n-1)
    {
        printf("No");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &tab[i].first, &tab[i].second);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%lld", &mos[i].first);
        mos[i].second=i;
    }
    sort(mos+1, mos+1+m);
    for (int i=1; i<n; i++)
    {
        zak[i].first.first=tab[i+1].first-tab[i].second;
        zak[i].first.second=tab[i+1].second-tab[i].first;
        zak[i].second=i;
    }
    sort(zak+1, zak+n);
    while(ok<n-1 && k<=m)
    {
        if (kol.empty())
        {
            l++;
            kol.push(make_pair(-zak[l].first.second, zak[l].second));
            continue;
        }
        czyt=kol.top();
        //printf("%lld %d   %lld %d\n", czyt.first, czyt.second, mos[k].first, mos[k].second);
        if (mos[k].first>-(czyt.first))
        {
            printf("No");
            return 0;
        }
        if (mos[k].first<(tab[czyt.second+1].first-tab[czyt.second].second))
        {
            k++;
            continue;
        }
        if (l<n-1 && mos[k].first>=(tab[zak[l+1].second+1].first-tab[zak[l+1].second].second))
        {
            l++;
            kol.push(make_pair(-zak[l].first.second, zak[l].second));
            continue;
        }
        kt[czyt.second]=mos[k].second;
        k++;
        kol.pop();
        ok++;
    }
    if (ok<n-1)
    {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for (int i=1; i<n; i++)
    printf("%d ", kt[i]);
    return 0;
}
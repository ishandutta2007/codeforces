#include <bits/stdc++.h>
using namespace std;

int n;
int k;

pair <long long,long long> tab1[1000007];
pair <long long,long long> tab2[1000007];

long long wyn;

vector <int> d, g, l, p;

int zab[1000007];

int licz;

long long jed, dwa;

bool mniej1(int a, int b)
{
    return tab1[a].first+tab2[a].first<tab1[b].first+tab2[b].first;
}

bool mniej2(int a, int b)
{
    return tab1[a].first+tab2[a].first>tab1[b].first+tab2[b].first;
}

bool mniej3(int a, int b)
{
    return tab1[a].second+tab2[a].second<tab1[b].second+tab2[b].second;
}

bool mniej4(int a, int b)
{
    return tab1[a].second+tab2[a].second>tab1[b].second+tab2[b].second;
}

int main()
{
    wyn=1000000000;
    wyn*=wyn;
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld%lld", &tab1[i].first, &tab1[i].second, &tab2[i].first, &tab2[i].second);
        d.push_back(i);
        g.push_back(i);
        l.push_back(i);
        p.push_back(i);
    }
    sort(d.begin(), d.end(), mniej1);
    sort(g.begin(), g.end(), mniej2);
    sort(l.begin(), l.end(), mniej3);
    sort(p.begin(), p.end(), mniej4);
    for (int i=0; i<=k; i++)
    {
        for (int j=0; j<=k; j++)
        {
            for (int o=0; o<=k; o++)
            {
                for (int u=0; u<=k; u++)
                {
                    licz=0;
                    for (int h=1; h<=i; h++)
                    {
                        if (!zab[d[h-1]])
                        {
                            licz++;
                            zab[d[h-1]]=1;
                        }
                    }
                    for (int h=1; h<=j; h++)
                    {
                        if (!zab[g[h-1]])
                        {
                            licz++;
                            zab[g[h-1]]=1;
                        }
                    }
                    for (int h=1; h<=o; h++)
                    {
                        if (!zab[l[h-1]])
                        {
                            licz++;
                            zab[l[h-1]]=1;
                        }
                    }
                    for (int h=1; h<=u; h++)
                    {
                        if (!zab[p[h-1]])
                        {
                            licz++;
                            zab[p[h-1]]=1;
                        }
                    }
                    if (licz>k)
                    {
                        for (int h=1; h<=i; h++)
                        {
                            zab[d[h-1]]=0;
                        }
                        for (int h=1; h<=j; h++)
                        {
                            zab[g[h-1]]=0;
                        }
                        for (int h=1; h<=o; h++)
                        {
                            zab[l[h-1]]=0;
                        }
                        for (int h=1; h<=u; h++)
                        {
                            zab[p[h-1]]=0;
                        }
                        continue;
                    }
                    jed=((tab1[g[j]].first+tab2[g[j]].first)-(tab1[d[i]].first+tab2[d[i]].first)+1)/2;
                    jed=max(jed, (long long) 1);

                    dwa=((tab1[p[u]].second+tab2[p[u]].second)-(tab1[l[o]].second+tab2[l[o]].second)+1)/2;
                    dwa=max(dwa, (long long) 1);
                    wyn=min(wyn, jed*dwa);
                    for (int h=1; h<=i; h++)
                    {
                        zab[d[h-1]]=0;
                    }
                    for (int h=1; h<=j; h++)
                    {
                        zab[g[h-1]]=0;
                    }
                    for (int h=1; h<=o; h++)
                    {
                        zab[l[h-1]]=0;
                    }
                    for (int h=1; h<=u; h++)
                    {
                        zab[p[h-1]]=0;
                    }
                }
            }
        }
    }
    printf("%lld\n", wyn);
    return 0;
}
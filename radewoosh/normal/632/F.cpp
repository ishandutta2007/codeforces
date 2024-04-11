#include <bits/stdc++.h>
using namespace std;

int n;

int tab[2507][2507];

bitset <2507> bity[2507];

bitset <2507> pus;

vector < pair <int,int> > wek;

int l;

int x, y;

bool mniej(pair <int,int> a, pair <int,int> b)
{
    return tab[a.first][a.second]<tab[b.first][b.second];
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &tab[i][j]);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (tab[i][j]!=tab[j][i])
            {
                printf("NOT MAGIC\n");
                return 0;
            }
        }
        if (tab[i][i])
        {
            printf("NOT MAGIC\n");
            return 0;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            wek.push_back(make_pair(i, j));
        }
    }
    sort(wek.begin(), wek.end(), mniej);
    for (int i=0; i<wek.size(); i++)
    {
        l=i;
        while(l<wek.size()-1 && tab[wek[i].first][wek[i].second]==tab[wek[l+1].first][wek[l+1].second])
        l++;
        for (int j=i; j<=l; j++)
        {
            x=wek[j].first;
            y=wek[j].second;
            if ((bity[x]&bity[y])!=pus)
            {
                printf("NOT MAGIC\n");
                return 0;
            }
        }
        for (int j=i; j<=l; j++)
        {
            x=wek[j].first;
            y=wek[j].second;
            bity[x][y]=1;
            bity[y][x]=1;
        }
        i=l;
    }
    printf("MAGIC\n");
    return 0;
}
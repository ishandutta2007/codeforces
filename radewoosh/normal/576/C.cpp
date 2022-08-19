#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> tab[1000007];

vector <int> co[1007][1007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &tab[i].first, &tab[i].second);
        co[tab[i].first/1000][tab[i].second/1000].push_back(i);
    }
    for (int i=0; i<=1000; i++)
    {
        if (i&1)
        {
            for (int j=0; j<=1000; j++)
            {
                for (int l=0; l<co[i][j].size(); l++)
                {
                    printf("%d ", co[i][j][l]);
                }
            }
        }
        else
        {
            for (int j=1000; j>=0; j--)
            {
                for (int l=0; l<co[i][j].size(); l++)
                {
                    printf("%d ", co[i][j][l]);
                }
            }
        }
    }
    return 0;
}
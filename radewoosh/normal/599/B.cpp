#include <bits/stdc++.h>
using namespace std;

int n, m;

vector <int> wek[100007];
vector <int> wyn;

int x;

int czy;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        wek[x].push_back(i);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &x);
        if (wek[x].empty())
        {
            printf("Impossible\n");
            return 0;
        }
        if (wek[x].size()>1)
        {
            czy=1;
        }
        wyn.push_back(wek[x][0]);
    }
    if (czy)
    {
        printf("Ambiguity\n");
        return 0;
    }
    printf("Possible\n");
    for (int i=0; i<m; i++)
    {
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}
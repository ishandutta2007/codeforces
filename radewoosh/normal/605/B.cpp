#include <bits/stdc++.h>
using namespace std;

int n, m;

int tab[1000007];
int decy[1000007];

vector <int> jed, dwa;

pair <int,int> kra[1000007];

int x;

int v;

bool mniej(int a, int b)
{
    return tab[a]<tab[b];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &tab[i], &decy[i]);
        if (decy[i])
        jed.push_back(i);
        else
        dwa.push_back(i);
    }
    if (jed.size()!=(n-1))
    {
        printf("-1\n");
        return 0;
    }
    sort(jed.begin(), jed.end(), mniej);
    sort(dwa.begin(), dwa.end(), mniej);
    for (int i=1; i<n; i++)
    {
        x=i+2;
        while(x<=n && !dwa.empty() && tab[dwa.back()]>=tab[jed.back()])
        {
            v=dwa.back();
            dwa.pop_back();
            kra[v]=make_pair(i, x);
            x++;
        }
        v=jed.back();
        jed.pop_back();
        kra[v]=make_pair(i, i+1);
    }
    if (!dwa.empty())
    {
        printf("-1\n");
        return 0;
    }
    for (int i=1; i<=m; i++)
    {
        printf("%d %d\n", kra[i].first, kra[i].second);
    }
    return 0;
}
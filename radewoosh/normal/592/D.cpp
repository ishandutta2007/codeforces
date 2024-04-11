#include <bits/stdc++.h>
using namespace std;

int n, m;

int tak[1000007];

int p1, p2;
vector <int> graf[1000007];

int l;

int s;

int modl;
int jed=1000000000;;

bool mniej(pair <int,int> a, pair <int,int> b)
{
    if (a.first==b.first)
    return a.second<b.second;
    return a.first>b.first;
}

pair <int,int> dfs(int v, int oj)
{
    vector < pair <int,int> > wek;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]==oj)
        continue;
        wek.push_back(dfs(graf[v][i], v));
        if (wek.back()==make_pair(0, 0))
        wek.pop_back();
    }
    sort(wek.begin(), wek.end(), mniej);
    if (wek.empty())
    {
        if (!tak[v])
        return make_pair(0, 0);
        l++;
        return make_pair(1, v);
    }
    l++;
    if (wek[0].first>modl)
    {
        modl=wek[0].first;
        jed=min(wek[0].second, v);
    }
    if (wek[0].first==modl)
    {
        jed=min(jed, min(wek[0].second, v));
    }
    if (wek.size()==1)
    return make_pair(wek[0].first+1, wek[0].second);
    if (wek[0].first+wek[1].first>modl)
    {
        modl=wek[0].first+wek[1].first;
        jed=min(wek[0].second, wek[1].second);
    }
    if (wek[0].first+wek[1].first==modl)
    {
        jed=min(jed, min(wek[0].second, wek[1].second));
    }
    return make_pair(wek[0].first+1, wek[0].second);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    if (m==1)
    {
        scanf("%d", &p1);
        printf("%d\n0\n", p1);
        return 0;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d", &p1);
        s=p1;
        tak[p1]=1;
    }
    dfs(s, 0);
    printf("%d\n%d\n", jed, 2*l-modl-2);
    return 0;
}
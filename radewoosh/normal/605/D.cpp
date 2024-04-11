#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> tz[1000007];
pair <int,int> td[1000007];

int l;
map <int,int> mapa;

int dos[1000007];

int u;

int n1;

vector <int> rzu[2100007];

int zko[1000007];
int odl[1000007];
queue <int> bfs;

int kan;

vector <int> wyn;

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

bool mniej(int a, int b)
{
    return tz[a].second>tz[b].second;
}

void pisz(int v, int num)
{
    v+=n1-1;
    while(v)
    {
        rzu[v].push_back(num);
        v>>=1;
    }
}

void czyt(int v, int a, int b, int graa, int grab, int lim)
{
    if (a>=graa && b<=grab)
    {
        while(!rzu[v].empty())
        {
            int p=rzu[v].back();
            if (odl[p])
            {
                rzu[v].pop_back();
                continue;
            }
            if (tz[p].second>lim)
            {
                break;
            }
            rzu[v].pop_back();
            odl[p]=kan;
            zko[p]=u;
            bfs.push(p);
        }
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    czyt((v<<1), a, (a+b)>>1, graa, grab, lim);
    czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab, lim);
}

int main()
{
    scanf("%d", &n);
    mapa[0]=1;
    tz[0].first=1;
    tz[0].second=1;
    td[0].first=1;
    td[0].second=1;
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &tz[i].first, &tz[i].second);
        scanf("%d%d", &td[i].first, &td[i].second);
        mapa[tz[i].first]=1;
        mapa[tz[i].second]=1;
        mapa[td[i].first]=1;
        mapa[td[i].second]=1;
        dos[i]=i;
    }
    for (map <int,int>::iterator it=mapa.begin(); it!=mapa.end(); it++)
    {
        l++;
        mapa[it->first]=l;
    }
    n1=potenga(l+3);
    for (int i=1; i<=n; i++)
    {
        tz[i].first=mapa[tz[i].first];
        tz[i].second=mapa[tz[i].second];
        td[i].first=mapa[td[i].first];
        td[i].second=mapa[td[i].second];
    }
    sort(dos+1, dos+1+n, mniej);
    for (int i=1; i<=n; i++)
    {
        u=dos[i];
        pisz(tz[u].first, u);
    }
    bfs.push(0);
    odl[0]=1;
    while(!bfs.empty())
    {
        u=bfs.front();
        bfs.pop();
        kan=odl[u]+1;
        czyt(1, 1, n1, 1, td[u].first, td[u].second);
    }
    if (!odl[n])
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", odl[n]-1);
    u=n;
    while(u)
    {
        wyn.push_back(u);
        u=zko[u];
    }
    while(!wyn.empty())
    {
        printf("%d ", wyn.back());
        wyn.pop_back();
    }
    printf("\n");
    return 0;
}
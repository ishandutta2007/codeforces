#include <bits/stdc++.h>
using namespace std;

long long inf=(long long)1000000000*1000000000;

struct edge//mozna dodawac atrybuty w celu identyfikacji krawedzi
{
    int id;

    int cel;
    long long lim;
    long long flow;
    edge* odw;
    edge()
    {
        cel=lim=flow=0;
    }
};

int n1, zr, uj;//liczba wierzcholkow, numer zrodla i numer ujscia, numerowane od 1

vector < edge* > graf[1000007];
int bylo[1000007];
int odl[1000007];

void add_edge(int v, int u, long long lim, int num)//dodaje krawedz skierowana z v do u o przepustowosci lim
{
    edge* wte= new edge;
    edge* wtamte= new edge;
    wte->odw=wtamte;
    wtamte->odw=wte;
    wte->lim=lim;
    wtamte->lim=lim;
    wte->cel=u;
    wtamte->cel=v;
    wte->id=num;
    wtamte->id=num;
    graf[v].push_back(wte);
    graf[u].push_back(wtamte);
}

void czys()
{
    for (int i=1; i<=n1; i++)
    {
        bylo[i]=0;
        odl[i]=0;
    }
}

void bfs()
{
    queue <int> kol;
    int u;
    kol.push(zr);
    odl[zr]=1;
    while(!kol.empty())
    {
        u=kol.front();
        kol.pop();
        for (int i=0; i<graf[u].size(); i++)
        {
            if (!odl[graf[u][i]->cel] && graf[u][i]->lim)
            {
                odl[graf[u][i]->cel]=odl[u]+1;
                kol.push(graf[u][i]->cel);
            }
        }
    }
}

long long dfs(int v, long long mini)
{
    bylo[v]=1;
    if (v==uj)
    return mini;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (!bylo[graf[v][i]->cel] && graf[v][i]->lim && odl[graf[v][i]->cel]==odl[v]+1)
        {
            long long ret=dfs(graf[v][i]->cel, min(mini, graf[v][i]->lim));
            if (!ret)
            continue;
            graf[v][i]->lim-=ret;
            graf[v][i]->odw->lim+=ret;
            graf[v][i]->flow+=ret;
            long long pom=min(graf[v][i]->flow, graf[v][i]->odw->flow);
            graf[v][i]->flow-=pom;
            graf[v][i]->odw->flow-=pom;
            return ret;
        }
    }
    return 0;
}

void szafl()
{
    for (int i=1; i<=n1; i++)
    {
        random_shuffle(graf[i].begin(), graf[i].end());
    }
}

long long flow()
{
    long long ret=0;
    while(1 && ret<=3*inf)
    {
        czys();
        bfs();
        szafl();
        long long bier=dfs(zr, 5*inf);
        if (!bier)
        break;
        ret+=bier;
    }
    return ret;
}

int n, m;

int li;
int pre[1000007];
int low[1000007];

void dfsb(int v, int oj)
{
    li++;
    pre[v]=li;
    low[v]=li;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]->id==oj)
        continue;
        if (!pre[graf[v][i]->cel])
        {
            dfsb(graf[v][i]->cel, graf[v][i]->id);
            low[v]=min(low[v], low[graf[v][i]->cel]);
        }
        else
        {
            low[v]=min(low[v], pre[graf[v][i]->cel]);
        }
    }
}

int bylob[1000007];

int tak;

int gopcja=-1;

void dfsb2(int v, int opcja)
{
    if (v==uj)
    {
        tak=1;
        gopcja=opcja;
    }
    bylob[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylob[graf[v][i]->cel])
        continue;
        dfsb2(graf[v][i]->cel, max(opcja, (pre[graf[v][i]->cel]==low[graf[v][i]->cel])-1));
        if (pre[graf[v][i]->cel]==low[graf[v][i]->cel])
        {
            graf[v][i]->lim+=inf;
            graf[v][i]->odw->lim+=inf;
        }
    }
}

int bylo2[1000007];

void dfs2(int v)
{
    bylo2[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylo2[graf[v][i]->cel] || !(graf[v][i]->lim))
        continue;
        dfs2(graf[v][i]->cel);
    }
}

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &m);
    scanf("%d%d", &zr, &uj);
    n1=n;
    for (int i=1; i<=m; i++)
    {
        int p1, p2;
        long long p3;
        scanf("%d%d%lld", &p1, &p2, &p3);
        add_edge(p1, p2, p3+inf, i);
    }
    dfsb(zr, -1);
    dfsb2(zr, -1);

    if (!tak)
    {
        printf("0\n0\n\n");
        return 0;
    }

    long long wyn=flow();
    if (wyn>=3*inf)
    {
        printf("-1\n");
        return 0;
    }
    /*if (pawel<(wyn%inf))
    {
        printf("%lld\n1\n%d\n", pawel, gopcja);
        return 0;
    }*/
    printf("%lld\n", wyn%inf);
    int lili=0;
    dfs2(zr);
    for (int i=1; i<=n1; i++)
    {
        for (int j=0; j<graf[i].size(); j++)
        {
            if (bylo2[i] && !bylo2[graf[i][j]->cel])
            {
                lili++;
            }

        }
    }
    printf("%d\n", lili);
    for (int i=1; i<=n1; i++)
    {
        for (int j=0; j<graf[i].size(); j++)
        {
            if (bylo2[i] && !bylo2[graf[i][j]->cel])
            {
                printf("%d ", graf[i][j]->id);
            }

        }
    }
    printf("\n");
    return 0;
}
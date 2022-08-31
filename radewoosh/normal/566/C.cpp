#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;

long long tab[1000007];
vector <pair <int,long double> > graf[1000007];
int p1, p2;
long long l;

int odw[1000007];
long double wyn[1000007];

int wie[1000007];
int ojc[1000007];

long double teraz[1000007];
long double liczaj;
long double og;

int m;
int zacz;
int c;

int r;

vector <int> wek;
int u;

int czy;

int g;

void dfs(int v, int oj)
{
    m++;
    wie[v]=1;
    ojc[v]=oj;
    wek.push_back(v);
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i].first==oj || odw[graf[v][i].first])
        continue;
        dfs(graf[v][i].first, v);
        wie[v]+=wie[graf[v][i].first];
    }
}

void dfs2(int v, int oj, long double odl)
{
    long double pie=sqrt(odl);
    liczaj+=tab[v]*pie*pie*pie;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i].first==oj)
        continue;
        dfs2(graf[v][i].first, v, odl+graf[v][i].second);
    }
}

int main()
{
    scanf("%d", &n);
    if (n==1)
    {
        printf("1 0.000000000");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<n; i++)
    {
        scanf("%d%d%lld", &p1, &p2, &l);
        graf[p1].push_back(make_pair(p2, (long double)l));
        graf[p2].push_back(make_pair(p1, (long double)l));
    }
    zacz=1;
    while(1)
    {
        //printf("zacz to %d\n", zacz);
        if (zacz<0 || odw[zacz])
        break;
        wek.clear();
        m=0;
        dfs(zacz, 0);
        c=0;
        for (int i=0; i<wek.size(); i++)
        {
            u=wek[i];
            if (m==1)
            {
                c=u;
                break;
            }
            if ((m-wie[u])*2>m)
            continue;
            czy=1;
            for (int j=0; j<graf[u].size(); j++)
            {
                if (graf[u][j].first==ojc[u] || odw[graf[u][j].first])
                continue;
                if (wie[graf[u][j].first]*2>m)
                {
                    czy=0;
                    break;
                }
            }
            if (!czy)
            continue;
            c=u;
            break;
        }
        //printf("c to %d\n", c);
        odw[c]=1;
        og=0;
        for (int i=0; i<graf[c].size(); i++)
        {
            liczaj=0;
            dfs2(graf[c][i].first, c, graf[c][i].second);
            og+=liczaj;
            teraz[graf[c][i].first]=liczaj;
        }
        wyn[c]=og;
        zacz=graf[c][0].first;
        for (int i=0; i<graf[c].size(); i++)
        {
            if (teraz[graf[c][i].first]>teraz[zacz])
            {
                zacz=graf[c][i].first;
            }
        }
        liczaj=0;
        dfs2(zacz, 0, 0.0);
        if (liczaj>=og)
        {
            r=zacz;
            zacz=-1;
            for (int i=0; i<graf[c].size(); i++)
            {
                if (graf[c][i].first!=r && (zacz==-1 || teraz[graf[c][i].first]>teraz[zacz]))
                {
                    zacz=graf[c][i].first;
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (odw[i] && (!g || wyn[i]<wyn[g]))
        {
            g=i;
        }
    }
    printf("%d %.9lf", g, (double) wyn[g]);
    return 0;
}
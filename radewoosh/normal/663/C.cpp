#include <bits/stdc++.h>
using namespace std;

int n, m;

int pawel;

int p1, p2;
char p3[5];
vector < pair <int,int> > graf[1000007];

int wyn=1000000000;

int bylo[1000007];

int ok;

vector <int> aktu;
vector <int> opty;

vector <int> roz;

int odl[1000007];

int ok1, ok2;
vector <int> wyp1;
vector <int> wyp2;

int oj[1000007];

int fin(int v)
{
    if (v!=oj[v])
    oj[v]=fin(oj[v]);
    return oj[v];
}

void uni(int v, int u)
{
    v=fin(v);
    u=fin(u);
    if (v!=u)
    oj[u]=v;
}

void czys()
{
    ok=1;
    for (int i=1; i<=n; i++)
    {
        bylo[i]=0;
        odl[i]=0;
        //stan[i]=0;
    }
}

void dfs(int v)
{
    bylo[v]=1;
    roz.push_back(v);
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylo[graf[v][i].first])
        {
            if ((odl[v]^graf[v][i].second)!=odl[graf[v][i].first])
            {
                ok=0;
            }
        }
        else
        {
            odl[graf[v][i].first]=(odl[v]^graf[v][i].second);
            dfs(graf[v][i].first);
        }
    }
}

void zbi(int v)
{
    bylo[v]=0;
    odl[v]=0;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylo[graf[v][i].first])
        {
            zbi(graf[v][i].first);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        oj[i]=i;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%s", &p1, &p2, p3);
        graf[p1].push_back(make_pair(p2, (p3[0]=='R')));
        graf[p2].push_back(make_pair(p1, (p3[0]=='R')));
        uni(p1, p2);
        if ((p3[0]=='R'))
        pawel++;
    }
    if (!pawel || pawel==m)
    {
        printf("0\n\n");
        return 0;
    }
    ok1=ok2=1;
    czys();
    for (int i=1; i<=n; i++)
    {
        if (fin(i)!=i)
        continue;
        roz.clear();
        opty.clear();
        ok=1;
        dfs(i);
        for (int j=1; j<=roz.size()+1; j++)
        {
            opty.push_back(0);
        }
        if (ok)
        {
            aktu.clear();
            for (int j=0; j<roz.size(); j++)
            {
                if (odl[roz[j]])
                aktu.push_back(roz[j]);
            }
            if (aktu.size()<opty.size())
            {
                opty=aktu;
            }
        }
        zbi(i);
        roz.clear();
        ok=1;
        odl[i]=1;
        dfs(i);
        if (ok)
        {
            aktu.clear();
            for (int j=0; j<roz.size(); j++)
            {
                if (odl[roz[j]])
                aktu.push_back(roz[j]);
            }
            if (aktu.size()<opty.size())
            {
                opty=aktu;
            }
        }
        if (opty.size()>roz.size())
        {
            ok1=0;
        }
        else
        {
            for (int j=0; j<opty.size(); j++)
            {
                wyp1.push_back(opty[j]);
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<graf[i].size(); j++)
        {
            graf[i][j].second^=1;
        }
    }
    czys();
    for (int i=1; i<=n; i++)
    {
        if (fin(i)!=i)
        continue;
        roz.clear();
        opty.clear();
        ok=1;
        dfs(i);
        for (int j=1; j<=roz.size()+1; j++)
        {
            opty.push_back(0);
        }
        if (ok)
        {
            aktu.clear();
            for (int j=0; j<roz.size(); j++)
            {
                if (odl[roz[j]])
                aktu.push_back(roz[j]);
            }
            if (aktu.size()<opty.size())
            {
                opty=aktu;
            }
        }
        zbi(i);
        roz.clear();
        ok=1;
        odl[i]=1;
        dfs(i);
        if (ok)
        {
            aktu.clear();
            for (int j=0; j<roz.size(); j++)
            {
                if (odl[roz[j]])
                aktu.push_back(roz[j]);
            }
            if (aktu.size()<opty.size())
            {
                opty=aktu;
            }
        }
        if (opty.size()>roz.size())
        {
            ok2=0;
        }
        else
        {
            for (int j=0; j<opty.size(); j++)
            {
                wyp2.push_back(opty[j]);
            }
        }
    }
    if (ok2 && (!ok1 || wyp2.size()<wyp1.size()))
    {
        swap(ok1, ok2);
        swap(wyp1, wyp2);
    }
    if (!ok1)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", (int)wyp1.size());
    sort(wyp1.begin(), wyp1.end());
    for (int i=0; i<wyp1.size(); i++)
    printf("%d ", wyp1[i]);
    printf("\n");
    return 0;
}
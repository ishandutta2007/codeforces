#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
vector <int> graf[1000007];

int odl[3007][3007];

queue <int> bfs;
int v;

int wyn;
int k1, k2, k3, k4;

int o;

vector < pair <int,int> > naj[1000007];
vector < pair <int,int> > najw[1000007];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
    }
    for (int h=1; h<=n; h++)
    {
        odl[h][h]=1;
        bfs.push(h);
        while(!bfs.empty())
        {
            v=bfs.front();
            bfs.pop();
            for (int i=0; i<graf[v].size(); i++)
            {
                if (!odl[h][graf[v][i]])
                {
                    odl[h][graf[v][i]]=odl[h][v]+1;
                    bfs.push(graf[v][i]);
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (odl[i][j]>1)
            {
                naj[i].push_back(make_pair(odl[i][j], j));
            }
            if (odl[j][i]>1)
            {
                najw[i].push_back(make_pair(odl[j][i], j));
            }
        }
        sort(naj[i].begin(), naj[i].end());
        reverse(naj[i].begin(), naj[i].end());
        sort(najw[i].begin(), najw[i].end());
        reverse(najw[i].begin(), najw[i].end());
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (odl[i][j]<=1)
            continue;
            for (int l=0; l<4 && l<naj[j].size(); l++)
            {
                for (int k=0; k<4 && k<najw[i].size(); k++)
                {
                    if (naj[j][l].second!=i && najw[i][k].second!=j && naj[j][l].second!=najw[i][k].second)
                    {
                        o=odl[najw[i][k].second][i]+odl[i][j]+odl[j][naj[j][l].second];
                        if (o>wyn)
                        {
                            wyn=o;
                            k1=najw[i][k].second;
                            k2=i;
                            k3=j;
                            k4=naj[j][l].second;
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n", k1, k2, k3, k4);
    return 0;
}
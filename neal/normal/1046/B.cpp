#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M, Q;
vector <int> edge[MAXN];
int par[MAXN];

void flood (int cloc, int last)
{
    par[cloc] = last;
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        if (par[neigh] != -1)
        {
            if (par[par[cloc]] == neigh)
            {
                par[cloc] = par[last] = N;
                par[N] = neigh;
                N++;
            }
            else
            {
                par[cloc] = par[par[cloc]];
            }
            break;
        }
    }
    for (int neigh : edge[cloc])
    {
        if (neigh == last) continue;
        if (par[neigh] == -1)
        {
            flood (neigh, cloc);
        }
    }
}

vector <pair <int, int> > vedge[MAXN];
int cdep[MAXN];
int anc[MAXN][20];
int dlen[MAXN];

void vflood (int cloc, int last)
{
    anc[cloc][0] = last;
    for (int i = 1; i < 20; i++)
        anc[cloc][i] = anc[anc[cloc][i-1]][i-1];

    for (pair <int, int> pp : vedge[cloc])
    {
        int neigh = pp.first, cd = pp.second;
        if (neigh == last) continue;
        cdep[neigh] = cdep[cloc] + 1;
        dlen[neigh] = dlen[cloc] + cd;
        vflood (neigh, cloc);
    }
}

int lca (int a, int b)
{
    if (cdep[a] < cdep[b])
        swap (a, b);
    for (int i = 0; i < 20; i++)
    {
        if ((cdep[a] - cdep[b]) & (1 << i))
            a = anc[a][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}

int gdist (int a, int b)
{
    int l = lca (a, b);
    return dlen[a] + dlen[b] - 2 * dlen[l];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> Q;
    int nold = N;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    for (int i = 0; i < N; i++)
        par[i] = -1;
    flood (0, 0);

    for (int i = 1; i < N; i++)
    {
        if (i >= nold || par[i] >= nold)
        {
            vedge[i].push_back(make_pair(par[i], 1));
            vedge[par[i]].push_back(make_pair(i, 1));
        }
        else
        {
            vedge[i].push_back(make_pair(par[i], 2));
            vedge[par[i]].push_back(make_pair(i, 2));            
        }
    }

    vflood (0, 0);

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << gdist (a, b) / 2 << "\n";
    }
}
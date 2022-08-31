#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector < pair <int,int> > graf[300007];
int x;

pair <int,int> kra[300007];
long long wag[300007];

long long odl[300007];
priority_queue < pair <pair <long long,long long>,pair <long long,long long> > > dij;

int v;

vector <int> wyn;
long long liczw;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%lld", &kra[i].first, &kra[i].second, &wag[i]);
        graf[kra[i].first].push_back(make_pair(kra[i].second, i));
        graf[kra[i].second].push_back(make_pair(kra[i].first, i));
    }
    scanf("%d", &x);
    for (int i=1; i<=n; i++)
    {
        odl[i]=-1;
    }
    dij.push(make_pair(make_pair(0,0),make_pair(x, 0)));
    while(!dij.empty())
    {
        v=dij.top().second.first;
        if (odl[v]>=0)
        {
            dij.pop();
            continue;
        }
        odl[v]=-dij.top().first.first;
        if (v!=x)
        {
            wyn.push_back(dij.top().second.second);
            liczw-=dij.top().first.second;
        }
        dij.pop();
        for (int i=0; i<graf[v].size(); i++)
        {
            if (odl[graf[v][i].first]<0)
            {
                dij.push(make_pair(make_pair(-odl[v]-wag[graf[v][i].second],-wag[graf[v][i].second]),graf[v][i]));
            }
        }
    }
    printf("%lld\n", liczw);
    for (int i=0; i<wyn.size(); i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}
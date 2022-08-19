#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int k;
long long x, y;
long long nx, ny;
map < pair <long long, long long>, int > mapa;
vector < pair <long long,long long> > oto;

pair <long long,long long> tab[1000007];

long long ilo(pair <long long,long long> s, pair <long long,long long> a, pair <long long,long long> b)
{
    return (a.first-s.first)*(b.second-s.second)-(b.first-s.first)*(a.second-s.second);
}

bool mniej(pair <long long,long long> a, pair <long long,long long> b)
{
    return ilo(make_pair(-1, -1), a, b)>0;
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%lld%lld", &x, &y);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &x, &y);
        tab[i]=make_pair(x, y);
        nx=max(nx, x);
        ny=max(ny, y);
        mapa[tab[i]]=1;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%lld%lld", &x, &y);
        tab[n+i]=make_pair(x, y);
        nx=max(nx, x);
        ny=max(ny, y);
        if (!mapa[tab[n+i]])
        mapa[tab[n+i]]=2;
    }
    k=n+m;
    tab[k+1]=make_pair(nx, -1);
    mapa[tab[k+1]]=2;
    tab[k+2]=make_pair(-1, ny);
    mapa[tab[k+2]]=2;
    k+=2;
    sort(tab+1, tab+1+k, mniej);
    for (int i=1; i<=k; i++)
    {
        //printf("%lld %lld\n", tab[i].first, tab[i].second);
        if (tab[i]==tab[i-1])
        continue;
        while(oto.size()>1 && ilo(oto[oto.size()-2], oto[oto.size()-1], tab[i])<0)
        {
            oto.pop_back();
        }
        oto.push_back(tab[i]);
    }
    if (oto[0].second!=-1 || oto.back().first!=-1)
    while(1);
    for (int i=0; i<oto.size(); i++)
    {
        if (mapa[oto[i]]==1)
        {
            /*if (k>=200000)
            {
                printf("pop %lld %lld  %d\n", oto[i-1].first, oto[i-1].second, mapa[oto[i-1]]);
                printf("teraz %lld %lld  %d\n", oto[i].first, oto[i].second, mapa[oto[i]]);
                printf("pot %lld %lld  %d\n", oto[i+1].first, oto[i+1].second, mapa[oto[i+1]]);
            }*/
            printf("Max");
            return 0;
        }
    }
    printf("Min");
    return 0;
}
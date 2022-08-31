#include <cstdio>
#include <queue>
using namespace std;

int n;
long long tab[200007];
pair <int,int> roz[200007];
int wyn[100007];

priority_queue < pair <long long,int> > kol;

int l;

int a, b;

void dfs(int v, int odl)
{
    //printf(" %d %d\n", v, odl);
    if (v<=n)
    {
        wyn[v]=odl;
        return;
    }
    dfs(roz[v].first, odl);
    dfs(roz[v].second, odl^1);
}

int main()
{
    scanf("%d", &n);
    l=n;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        kol.push(make_pair(tab[i],i));
    }
    while(kol.size()>1)
    {
        a=kol.top().second;
        kol.pop();
        b=kol.top().second;
        kol.pop();
        //printf("%d %lld    %d %lld\n", a, tab[a], b, tab[b]);
        l++;
        roz[l].first=a;
        roz[l].second=b;
        tab[l]=tab[a]-tab[b];
        kol.push(make_pair(tab[l], l));
        //printf("%lld\n", tab[l]);
    }
    dfs(l, 0);
    for (int i=1; i<=n; i++)
    {
        if (!wyn[i])
        printf("+");
        else
        printf("-");
    }
    return 0;
}
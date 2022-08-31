#include <cstdio>
#include <algorithm>
using namespace std;

int n;

pair <int,int> tab[1000007];

int pre[1000007];

int wyn=1000000007;

int n1=1048576;

int drzewo[2100000];
int ile[2100000];

int x;

void pisz(int v)
{
    int war=v;
    v+=n1-1;
    while(v)
    {
        ile[v]++;
        drzewo[v]+=war;
        v>>=1;
    }
}

int czyt(int v, int a, int b, int u)
{
    //printf("%d %d\n", v, u);
    if (!u)
    {
        return 0;
    }
    if (a==b)
    {
        return min(u, ile[v])*a;
    }
    if (u==ile[v])
    {
        return drzewo[v];
    }
    int ret=czyt((v<<1), a, (a+b)>>1, min(ile[v<<1], u));
    if (ile[v<<1]<u)
    {
        ret+=czyt((v<<1)+1, (a+b+2)>>1, b, u-ile[v<<1]);
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i].first);
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i].second);
    }
    sort(tab+1 ,tab+1+n);
    for (int i=1; i<=n; i++)
    {
        pre[i]=pre[i-1]+tab[i].second;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n+1; j++)
        {
            if (tab[j].first!=tab[i].first)
            {
                x=j-1;
                break;
            }
        }
        //printf("%d %d\n", i-1-(x-i), czyt(1, 1, n1, max(0, i-1-(x-i))));
        wyn=min(wyn, pre[n]-pre[x]+czyt(1, 1, n1, max(0, i-1-(x-i))));
        for (int j=i; j<=x; j++)
        {
            pisz(tab[j].second);
        }
        i=x;
    }
    printf("%d", wyn);
    return 0;
}
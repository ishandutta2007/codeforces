#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

long long tab[200007];

int n1;

pair <long long,long long> drzewo[2000007];
int ile[2000007];

vector <long long> wyn;

int x;

long long ilema;

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

void pisz(int v, int a, int b, int graa, int grab, long long war)
{
    if (a>=graa && b<=grab)
    {
        drzewo[v].second+=war;
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    pisz((v<<1), a, (a+b)>>1, graa, grab, war);
    pisz((v<<1)+1, (a+b+2)>>1, b, graa, grab, war);
    drzewo[v].first=max(drzewo[(v<<1)+1].first+drzewo[(v<<1)+1].second, drzewo[(v<<1)].first+drzewo[(v<<1)].second-ile[(v<<1)+1]);
}

void piszi(int v, int war)
{
    v+=n1-1;
    while(v)
    {
        ile[v]+=war;
        v>>=1;
        if (v)
        drzewo[v].first=max(drzewo[(v<<1)+1].first+drzewo[(v<<1)+1].second, drzewo[(v<<1)].first+drzewo[(v<<1)].second-ile[(v<<1)+1]);
    }
}

int szukajmax(int v, int a, int b)
{
    ilema+=drzewo[v].second;
    if (a==b)
    {
        return a;
    }
    if (drzewo[(v<<1)+1].first+drzewo[(v<<1)+1].second > drzewo[(v<<1)].first+drzewo[(v<<1)].second-ile[(v<<1)+1])
    {
        return szukajmax((v<<1)+1, (a+b+2)>>1, b);
    }
    else
    {
        return szukajmax((v<<1), a, (a+b)>>1);
    }
}

int czyti(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        return ile[v];
    }
    if (a>grab || b<graa)
    {
        return 0;
    }
    return czyti((v<<1), a, (a+b)>>1, graa, grab)+czyti((v<<1)+1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
    scanf("%d", &n);
    n1=potenga(n+1);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        pisz(1, 1, n1, i, i, tab[i]);
        piszi(i, 1);
    }
    for (int i=n+1; i<=n1; i++)
    {
        pisz(1, 1, n1, i, i, -2000000000);
        piszi(i, 0);
    }
    for (int i=1; i<=n; i++)
    {
        ilema=0;
        x=szukajmax(1, 1, n1);
        wyn.push_back(ilema-czyti(1, 1, n1, x+1, n1));
        pisz(1, 1, n1, x, x, -2000000000);
        pisz(1, 1, n1, x+1, n1, 1);
        piszi(x, -1);
    }
    for (int i=n-1; i; i--)
    {
        if (wyn[i]>wyn[i-1])
        {
            printf(":(");
            return 0;
        }
    }
    for (int i=n-1; i>=0; i--)
    {
        printf("%lld ", wyn[i]);
    }
    return 0;
}
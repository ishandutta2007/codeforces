#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];
int prze[1000007];

int wyn[1000007];

vector <int> ska;

int n1;
int drzewo[1100007];

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

void start(int v, int a, int b)
{
    if (a==b)
    {
        return;
    }
    start((v<<1), a, (a+b)>>1);
    start((v<<1)+1, (a+b+2)>>1, b);
    drzewo[v]=min(drzewo[(v<<1)], drzewo[(v<<1)^1]);
}

int czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        return drzewo[v];
    }
    if (a>grab || b<graa)
    {
        return 2*n;
    }
    return min( czyt((v<<1), a, (a+b)>>1, graa, grab), czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab) );
}

void rek(int a, int b, int p)
{
    if (a>b)
    return;
    int s=czyt(1, 1, n1, a, b);
    wyn[s]=p;
    rek(a, prze[s]-1, tab[s]);
    rek(prze[s]+1, b, tab[s]);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        ska.push_back(tab[i]);
    }
    n1=potenga(n+2);
    for (int i=1; i<=2*n1; i++)
    drzewo[i]=2*n;
    sort(ska.begin(), ska.end());
    for (int i=1; i<=n; i++)
    {
        prze[i]=lower_bound(ska.begin(), ska.end(), tab[i])-ska.begin()+1;
        drzewo[prze[i]+n1-1]=i;
    }
    start(1, 1, n1);
    rek(1, n, 0);
    for (int i=2; i<=n; i++)
    {
        printf("%d ", wyn[i]);
    }
    printf("\n");
    return 0;
}
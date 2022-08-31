#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long a, b;

vector <long long> ska;

long long drzewo[1000007];


long long wyn;

int m;

double pi=3.14159265359;

int n1;

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    if (i>=v)
    return i;
}

void pisz(int v, long long w)
{
    v+=n1-1;
    while(v)
    {
        drzewo[v]=max(drzewo[v], w);
        v>>=1;
    }
}

long long czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    return drzewo[v];
    if (a>grab || b<graa)
    return 0;
    return max ( czyt((v<<1), a, (a+b)>>1, graa, grab), czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab) );
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%lld", &a, &b);
        tab[i]=a*a*b;
        ska.push_back(tab[i]);
    }
    n1=potenga(n+5);
    ska.push_back(0);
    sort(ska.begin(), ska.end());
    for (int i=1; i<=n; i++)
    {
        m=lower_bound(ska.begin(), ska.end(), tab[i])-ska.begin();
        m+=3;
        a=czyt(1, 1, n1, 1, m);
        a+=tab[i];
        wyn=max(wyn, a);
        pisz(m+1, a);
    }
    printf("%.9lf\n", wyn*pi);
    return 0;
}
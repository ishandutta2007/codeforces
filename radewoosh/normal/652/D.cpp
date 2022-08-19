#include <bits/stdc++.h>
using namespace std;

int n;

int lew[1000007];
int pra[1000007];

int wyn[1000007];

int drzewo[1000007];

int poz[1000007];

int u;

vector < pair <int,int> > wek1;
vector < pair <int,int> > wek2;

void pisz(int v, int w)
{
    for (int i=v; i<=n; i+=(-i&i))
    drzewo[i]+=w;
}

int czyt(int v, int u)
{
    int ret=0;
    for (int i=v-1; i; i-=(-i&i))
    ret-=drzewo[i];
    for (int i=u; i; i-=(-i&i))
    ret+=drzewo[i];
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &lew[i], &pra[i]);
        wek1.push_back(make_pair(lew[i], i));
        wek2.push_back(make_pair(pra[i], i));
    }
    sort(wek1.begin(), wek1.end());
    sort(wek2.begin(), wek2.end());
    for (int i=0; i<n; i++)
    poz[wek1[i].second]=i+1;
    for (int i=1; i<=n; i++)
    {
        u=wek2[i-1].second;
        wyn[u]=czyt(poz[u], n);
        pisz(poz[u], 1);
    }
    for (int i=1; i<=n; i++)
    printf("%d\n", wyn[i]);
    return 0;
}
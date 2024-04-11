#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int x[1000007];
int y[1000007];
int kosz[1000007];

int l, p;

int dos[1000007];

int oj[1000007];
int parz[1000007];

int wyn;

inline int fin(int v)
{
    if (v!=oj[v])
    {
        int p=oj[v];
        oj[v]=fin(oj[v]);
        parz[v]^=parz[p];
    }
    return oj[v];
}

inline void uni(int v, int u)
{
    int p=1;

    fin(v);
    p^=parz[v];
    v=fin(v);

    fin(u);
    p^=parz[u];
    u=fin(u);

    parz[v]=p;
    oj[v]=u;
}

bool mniej(int a, int b)
{
    return kosz[a]>kosz[b];
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &kosz[i]);
        dos[i]=i;
    }
    sort(dos+1, dos+1+m, mniej);
    while(q--)
    {
        scanf("%d%d", &l, &p);
        for (int i=1; i<=n; i++)
        {
            parz[i]=0;
            oj[i]=i;
        }
        wyn=-1;
        int c;
        for (int i=1; i<=m; i++)
        {
            c=dos[i];
            if (c>p || c<l)
            continue;
            if (fin(x[c])!=fin(y[c]))
            {
                uni(x[c], y[c]);
            }
            else
            {
                if (parz[x[c]]==parz[y[c]])
                {
                    wyn=kosz[c];
                    break;
                }
            }
        }
        printf("%d\n", wyn);
    }
    return 0;
}
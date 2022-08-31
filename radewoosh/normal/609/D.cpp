#include <bits/stdc++.h>
using namespace std;

int n;

int m, k;

long long s;

int p1;
long long p2;
pair <long long,long long> tab[1000007];

int kied[1000007][3];
long long koszt[1000007][3];

int bsa, bsb, bss;

int dos[1000007];

long long A;
long long B;

long long wyd[3];

bool mniej(int a, int b)
{
    return ((tab[a].first*A+tab[a].second*B)<(tab[b].first*A+tab[b].second*B));
}

int check(int v)
{
    A=koszt[v][1];
    B=koszt[v][2];
    sort(dos+1, dos+1+m, mniej);
    wyd[1]=wyd[2]=0;
    for (int i=1; i<=k; i++)
    {
        wyd[1]+=tab[dos[i]].first;
        wyd[2]+=tab[dos[i]].second;
    }
    if (A*wyd[1]+B*wyd[2]<=s)
    return 1;
    return 0;
}

int main()
{
    scanf("%d", &n);
    scanf("%d%d", &m, &k);
    scanf("%lld", &s);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &koszt[i][1]);
        kied[i][1]=i;
        if (i>=2 && koszt[i-1][1]<koszt[i][1])
        {
            koszt[i][1]=koszt[i-1][1];
            kied[i][1]=kied[i-1][1];
        }
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &koszt[i][2]);
        kied[i][2]=i;
        if (i>=2 && koszt[i-1][2]<koszt[i][2])
        {
            koszt[i][2]=koszt[i-1][2];
            kied[i][2]=kied[i-1][2];
        }
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%lld", &p1, &p2);
        if (p1==1)
        tab[i].first=p2;
        else
        tab[i].second=p2;
        dos[i]=i;
    }
    if (!check(n))
    {
        printf("-1\n");
        return 0;
    }
    bsa=1;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        if (check(bss))
        bsb=bss;
        else
        bsa=bss+1;
    }
    while(bsa<n && !check(bsa))
    bsa++;
    printf("%d\n", bsa);
    sort(dos+1, dos+1+k);
    for (int i=1; i<=k; i++)
    {
        printf("%d", dos[i]);
        if (tab[dos[i]].first)
        printf(" %d\n", kied[bsa][1]);
        else
        printf(" %d\n", kied[bsa][2]);
    }
    return 0;
}
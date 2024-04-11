#include <bits/stdc++.h>
using namespace std;

int n, k;

int q;

long long war[100007];
int waga[100007];
pair <int,int> zak[100007];

int n1;
vector <int> kt[100007];

int czypyt[100007];

int typ;
int x;

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

void pisz(int v, int a, int b, int graa, int grab, int corz)
{
    if (a>=graa && b<=grab)
    {
        kt[v].push_back(corz);
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    pisz((v<<1), a, (a+b)>>1, graa, grab, corz);
    pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, corz);
}

long long P=10000019;
long long Q=1000000007;

long long dp[20][1007];

void prze(int v, int a, int b, int poz)
{
    for (int i=0; i<kt[v].size(); i++)
    {
        x=kt[v][i];
        for (int j=k-waga[x]; j>=0; j--)
        {
            dp[poz][j+waga[x]]=max(dp[poz][j+waga[x]], dp[poz][j]+war[x]);
        }
    }
    if (a!=b)
    {
        for (int i=0; i<=k; i++)
        dp[poz+1][i]=dp[poz][i];
        prze((v<<1), a, (a+b)>>1, poz+1);
        for (int i=0; i<=k; i++)
        dp[poz+1][i]=dp[poz][i];
        prze((v<<1)^1, (a+b+2)>>1, b, poz+1);
    }
    else
    {
        if (!czypyt[a])
        return;
        long long odp=0;
        for (int i=k; i; i--)
        {
            odp*=P;
            odp+=dp[poz][i];
            odp%=Q;
        }
        printf("%lld\n", odp);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld%d", &war[i], &waga[i]);
        zak[i].first=1;
        zak[i].second=1000000;
    }
    scanf("%d", &q);
    for (int i=1; i<=q; i++)
    {
        scanf("%d", &typ);
        if (typ==1)
        {
            n++;
            scanf("%lld%d", &war[n], &waga[n]);
            zak[n].first=i;
            zak[n].second=1000000;
        }
        if (typ==2)
        {
            scanf("%d", &x);
            zak[x].second=i;
        }
        if (typ==3)
        {
            czypyt[i]=1;
        }
    }
    n1=potenga(q+3);
    for (int i=1; i<=n; i++)
    {
        pisz(1, 1, n1, zak[i].first, zak[i].second, i);
    }
    prze(1, 1, n1, 1);
    return 0;
}
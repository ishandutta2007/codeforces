#include <bits/stdc++.h>
using namespace std;

int n, k;

int odw[10007][7];
int pol[10007];
int omi[10007];

int ukl[307][7];

int l;
int ter[7];

int prze[307][10][307];

long long mod=1000000007;

long long dp[10007][307];

long long dpp[307];

vector < pair <int,int> > pary;

int fin(int v)
{
    if (v!=ter[v])
    ter[v]=fin(ter[v]);
    return ter[v];
}

void uni(int v, int u)
{
    v=fin(v);
    u=fin(u);
    if (v>u)
    swap(v, u);
    if (v!=u)
    ter[u]=v;
}

void rek(int v)
{
    if (v==(k+2))
    {
        l++;
        for (int i=1; i<=k+1; i++)
        {
            ukl[l][i]=ter[i];
        }
        return;
    }
    for (int i=1; i<v; i++)
    {
        if (ter[i]!=i)
        continue;
        ter[v]=i;
        rek(v+1);
    }
    ter[v]=v;
    rek(v+1);
}

int znaj()
{
    for (int i=1; i<=k+1; i++)
    {
        fin(i);
    }
    for (int i=1; i<=l; i++)
    {
        int czy=1;
        for (int j=1; j<=k+1; j++)
        {
            if (ukl[i][j]!=ter[j])
            {
                czy=0;
            }
        }
        if (czy)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n ,&k);
    for (int i=k+1; i<=n; i++)
    {
        for (int j=1; j<=k; j++)
        {
            scanf("%d", &odw[i][j]);
        }
        sort(odw[i]+1, odw[i]+1+k);
        pol[i]=odw[i][k];
        for (int j=1; j<=k; j++)
        {
            int czy=0;
            for (int o=1; o<k; o++)
            {
                if (odw[pol[i]][j]==odw[i][o])
                {
                    czy=1;
                }
            }
            if (!czy)
            {
                omi[i]=j;
            }
        }
    }
    if (k==1)
    {
        printf("1\n");
        return 0;
    }
    rek(1);
    for (int i=1; i<=l; i++)
    {
        for (int j=1; j<=k; j++)
        {
            for (int o=1; o<=l; o++)
            {
                if (ukl[o][k+1]==(k+1))
                {
                    prze[i][j][o]=-1;
                    continue;
                }
                int czy=0;
                for (int p=1; p<=k+1; p++)
                {
                    ter[p]=ukl[i][p];
                }
                for (int p=1; p<=k; p++)
                {
                    if (ukl[o][p]!=p)
                    {
                        if (fin(ukl[o][p]+(ukl[o][p]>=j))==fin(p+(p>=j)))
                        czy=1;
                        uni(ukl[o][p]+(ukl[o][p]>=j), p+(p>=j));
                    }
                }
                if (czy)
                {
                    prze[i][j][o]=-1;
                    continue;
                }
                prze[i][j][o]=znaj();
            }
        }
    }
    for (int i=1; i<=k+1; i++)
    {
        for (int j=i+1; j<=k+1; j++)
        {
            if (i==k || j==k)
            continue;
            pary.push_back(make_pair(i, j));
        }
    }
    for (int i=0; i<(1<<pary.size()); i++)
    {
        for (int j=1; j<=k+1; j++)
        {
            ter[j]=j;
        }
        int czy=1;
        for (int j=0; j<pary.size(); j++)
        {
            if (i&(1<<j))
            {
                if (fin(pary[j].first)==fin(pary[j].second))
                czy=0;
                uni(pary[j].first, pary[j].second);
            }
        }
        if (!czy)
        continue;
        dp[k][znaj()]++;
    }
    for (int h=k+1; h<=n; h++)
    {
        for (int i=0; i<(1<<k); i++)
        {
            for (int j=1; j<=k+1; j++)
            {
                ter[j]=j;
            }
            for (int j=0; j<k; j++)
            {
                if (i&(1<<j))
                {
                    uni(j+1, k+1);
                }
            }
            dp[h][znaj()]=1;
        }
    }
    for (int i=n; i>k; i--)
    {
        for (int o=1; o<=l; o++)
        {
            dpp[o]=0;
        }
        for (int j=1; j<=l; j++)
        {
            for (int o=1; o<=l; o++)
            {
                if (prze[j][omi[i]][o]==-1 || !dp[i][o] || !dp[pol[i]][j])
                continue;
                dpp[prze[j][omi[i]][o]]+=dp[i][o]*dp[pol[i]][j];
                dpp[prze[j][omi[i]][o]]%=mod;
            }
        }
        for (int o=1; o<=l; o++)
        {
            dp[pol[i]][o]=dpp[o];
        }
    }
    for (int i=1; i<=l; i++)
    {
        int czy=1;
        for (int j=1; j<k; j++)
        {
            if (ukl[i][j]!=1)
            czy=0;
        }
        if (ukl[i][k+1]!=1)
        czy=0;
        if (ukl[i][k]!=k)
        czy=0;
        if (!czy)
        continue;
        printf("%lld\n", dp[k][i]);
    }
    return 0;
}
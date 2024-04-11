#include <bits/stdc++.h>
using namespace std;

int n, m;

bitset <157> wek;
bitset <157> wekp;

bitset <157> mac[157];
bitset <157> mac2[157];
bitset <157> macp[157];

bitset <157> macs[157];

bitset <157> pus;

pair <int,int> kra[157];
long long czas[157];
int dos[157];

long long licz;

long long mamy;

bool mniej(int a, int b)
{
    return czas[a]<czas[b];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%lld", &kra[i].first, &kra[i].second, &czas[i]);
        dos[i]=i;
    }
    sort(dos+1, dos+1+m, mniej);
    if (czas[dos[1]])
    {
        printf("Impossible\n");
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        mac[i][i]=1;
    }
    czas[0]=2000000000;
    for (int h=1; h<=m; h++)
    {
        for (int i=1; i<=n; i++)
        {
            mac2[i]=macs[i];
        }
        licz=czas[dos[h]]-mamy;
        while(licz)
        {
            if (licz&1)
            {
                for (int i=1; i<=n; i++)
                {
                    macp[i]=mac[i];
                    mac[i]=pus;
                }
                for (int i=1; i<=n; i++)
                {
                    for (int j=1; j<=n; j++)
                    {
                        if (macp[i][j])
                        {
                            mac[i]|=mac2[j];
                        }
                    }
                }
            }
            for (int i=1; i<=n; i++)
            {
                macp[i]=mac2[i];
                mac2[i]=pus;
            }
            for (int i=1; i<=n; i++)
            {
                for (int j=1; j<=n; j++)
                {
                    if (macp[i][j])
                    {
                        mac2[i]|=macp[j];
                    }
                }
            }
            licz>>=1;
        }
        mamy=czas[dos[h]];
        macs[kra[dos[h]].first][kra[dos[h]].second]=1;
        if (mac[1][n])
        {
            printf("%lld\n", mamy);
            return 0;
        }
        wek=mac[1];
        for (long long i=mamy+1; i<=min(czas[dos[h]]+n+5, czas[dos[h+1]]); i++)
        {
            wekp=wek;
            wek=pus;
            for (int j=1; j<=n; j++)
            {
                if (wekp[j])
                {
                    wek|=macs[j];
                }
            }
            if (wek[n])
            {
                printf("%lld\n", i);
                return 0;
            }
        }
    }
    printf("Impossible\n");
    return 0;
}
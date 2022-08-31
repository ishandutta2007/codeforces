#include <bits/stdc++.h>
using namespace std;

int n;
long long l;

long long tab[1000007];

char wcz[207][207];

long long inf=(long long)1000000000*1000000000;

int dlu[207];
int sum[207];

int n1;
long long wek[207];
long long wekp[207];

long long mac[207][207];
long long pom[207][207];

long long iledod[207];

long long wyn=0;

int main()
{
    scanf("%d%lld", &n, &l);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        scanf("%s", wcz[i]+1);
        sum[i]=sum[i-1];
        for (int j=1; wcz[i][j]; j++)
        sum[i]++;
        dlu[i]=sum[i]-sum[i-1];
    }
    n1=sum[n];
    for (int i=0; i<=n1; i++)
    {
        for (int j=0; j<=n1; j++)
        {
            mac[i][j]=-inf;
        }
        wek[i]=-inf;
    }
    wek[0]=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int ii=1; ii<=dlu[i]; ii++)
            {
                for (int jj=1; jj<=dlu[j]; jj++)
                {
                    if (jj>ii+1)
                    continue;
                    int czy=1;
                    for (int k=1; k<jj; k++)
                    {
                        if (wcz[i][ii+1-(jj-k)]!=wcz[j][k])
                        {
                            czy=0;
                        }
                    }
                    if (czy)
                    mac[sum[i-1]+ii][sum[j-1]+jj]=0;
                }
            }
        }
        mac[0][sum[i-1]+1]=0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int ii=1; ii<=dlu[i]; ii++)
        {
            for (int j=1; j<=n; j++)
            {
                if (dlu[j]>ii)
                continue;
                int czy=1;
                for (int jj=1; jj<=dlu[j]; jj++)
                {
                    if (wcz[i][ii-(dlu[j]-jj)]!=wcz[j][jj])
                    {
                        czy=0;
                    }
                }
                if (czy)
                iledod[sum[i-1]+ii]+=tab[j];
            }
        }
    }
    for (int i=0; i<=n1; i++)
    {
        for (int j=0; j<=n1; j++)
        {
            if (!mac[i][j])
            {
                mac[i][j]+=iledod[j];
            }
        }
    }
    while(l)
    {
        if (l&1)
        {
            for (int i=0; i<=n1; i++)
            {
                wekp[i]=wek[i];
                wek[i]=-inf;
            }
            for (int i=0; i<=n1; i++)
            {
                for (int j=0; j<=n1; j++)
                {
                    wek[j]=max(wek[j], wekp[i]+mac[i][j]);
                }
            }
        }
        for (int i=0; i<=n1; i++)
        {
            for (int j=0; j<=n1; j++)
            {
                pom[i][j]=mac[i][j];
                mac[i][j]=-inf;
            }
        }
        for (int i=0; i<=n1; i++)
        {
            for (int j=0; j<=n1; j++)
            {
                for (int l=0; l<=n1; l++)
                {
                    mac[i][j]=max(mac[i][j], pom[i][l]+pom[l][j]);
                }
            }
        }
        l>>=1;
    }
    for (int i=0; i<=n1; i++)
    wyn=max(wyn, wek[i]);
    printf("%lld\n", wyn);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n;

int czy=0;
long long tab[1000007];

long long mod=1000000007;

long long pod[5][5];

long long mac[5][5];
long long pom[5][5];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        if (tab[i]>1)
        czy=1;
    }
    if (!czy)
    {
        printf("0/1\n");
        return 0;
    }

    pod[1][2]++;
    pod[1][1]++;
    pod[2][1]++;
    pod[2][1]++;

    pod[4][4]=2;

    for (int h=1; h<=n; h++)
    {
        for (int i=1; i<=2; i++)
        {
            for (int j=1; j<=2; j++)
            {
                mac[i][j]=pod[i][j];
                pod[i][j]=0;
            }
            pod[i][i]=1;
        }
        mac[4][4]=pod[4][4];
        pod[4][4]=1;
        while(tab[h])
        {
            if (tab[h]&1)
            {
                for (int i=1; i<=2; i++)
                {
                    for (int j=1; j<=2; j++)
                    {
                        pom[i][j]=pod[i][j];
                        pod[i][j]=0;
                    }
                }
                for (int i=1; i<=2; i++)
                {
                    for (int j=1; j<=2; j++)
                    {
                        for (int l=1; l<=2; l++)
                        {
                            pod[i][j]+=pom[i][l]*mac[l][j];
                        }
                        pod[i][j]%=mod;
                    }
                }
                pod[4][4]*=mac[4][4];
                pod[4][4]%=mod;
            }
            for (int i=1; i<=2; i++)
            {
                for (int j=1; j<=2; j++)
                {
                    pom[i][j]=mac[i][j];
                    mac[i][j]=0;
                }
            }
            for (int i=1; i<=2; i++)
            {
                for (int j=1; j<=2; j++)
                {
                    for (int l=1; l<=2; l++)
                    {
                        mac[i][j]+=pom[i][l]*pom[l][j];
                    }
                    mac[i][j]%=mod;
                }
            }
            mac[4][4]*=mac[4][4];
            mac[4][4]%=mod;
            tab[h]>>=1;
        }
    }
    printf("%lld/%lld\n", (pod[2][2]*500000004)%mod, (pod[4][4]*500000004)%mod);

    return 0;
}
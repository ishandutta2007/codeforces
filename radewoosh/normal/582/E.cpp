#include <bits/stdc++.h>
using namespace std;

int ter;
char wcz[507];

long long mod=1000000007;

int n;
long long dp[207][70000];

long long lew[70000];
long long pra[70000];
long long pom[70000];

int obr=(1<<16)-1;

int korz;

long long wyn;

int rek()
{
    n++;
    int v=n;
    ter++;
    if (wcz[ter]=='(')
    {
        int p1;
        char zna;
        int p2;

        p1=rek();
        ter++;
        ter++;
        zna=wcz[ter];
        ter++;
        p2=rek();
        ter++;

        if (zna=='|' || zna=='?')
        {
            for (int i=0; i<(1<<16); i++)
            {
                lew[i]=dp[p1][i];
                pra[i]=dp[p2][i];
                pom[i]=0;
            }
            for (int i=0; i<16; i++)
            {
                for (int j=0; j<(1<<16); j++)
                {
                    if (!(j&(1<<i)))
                    {
                        lew[j^(1<<i)]+=lew[j];
                        pra[j^(1<<i)]+=pra[j];
                    }
                }
            }
            for (int i=0; i<(1<<16); i++)
            {
                lew[i]%=mod;
                pra[i]%=mod;
                pom[i]=(lew[i]*pra[i])%mod;
            }
            for (int i=0; i<16; i++)
            {
                for (int j=0; j<(1<<16); j++)
                {
                    if (!(j&(1<<i)))
                    {
                        pom[j^(1<<i)]-=pom[j];
                    }
                }
            }
            for (int i=0; i<(1<<16); i++)
            {
                pom[i]%=mod;
                pom[i]+=mod;
                pom[i]%=mod;
                dp[v][i]+=pom[i];
                dp[v][i]%=mod;
            }
        }
        if (zna=='&' || zna=='?')
        {
            for (int i=0; i<(1<<16); i++)
            {
                lew[i]=dp[p1][i^obr];
                pra[i]=dp[p2][i^obr];
                pom[i]=0;
            }
            for (int i=0; i<16; i++)
            {
                for (int j=0; j<(1<<16); j++)
                {
                    if (!(j&(1<<i)))
                    {
                        lew[j^(1<<i)]+=lew[j];
                        pra[j^(1<<i)]+=pra[j];
                    }
                }
            }
            for (int i=0; i<(1<<16); i++)
            {
                lew[i]%=mod;
                pra[i]%=mod;
                pom[i]=(lew[i]*pra[i])%mod;
            }
            for (int i=0; i<16; i++)
            {
                for (int j=0; j<(1<<16); j++)
                {
                    if (!(j&(1<<i)))
                    {
                        pom[j^(1<<i)]-=pom[j];
                    }
                }
            }
            for (int i=0; i<(1<<16); i++)
            {
                pom[i]%=mod;
                pom[i]+=mod;
                pom[i]%=mod;
                dp[v][i^obr]+=pom[i];
                dp[v][i^obr]%=mod;
            }
        }
    }
    else
    {
        if (wcz[ter]=='?')
        {
            for (int num=0; num<4; num++)
            {
                int mas=0;
                for (int i=0; i<16; i++)
                {
                    if (i&(1<<num))
                    {
                        mas|=(1<<i);
                    }
                }
                dp[v][mas]=1;
                dp[v][mas^obr]=1;
            }
        }
        else
        {
            if (wcz[ter]>='A' && wcz[ter]<='D')
            {
                int num=wcz[ter]-'A';
                int mas=0;
                for (int i=0; i<16; i++)
                {
                    if (i&(1<<num))
                    {
                        mas|=(1<<i);
                    }
                }
                dp[v][mas]=1;
            }
            else
            {
                int num=wcz[ter]-'a';
                int mas=0;
                for (int i=0; i<16; i++)
                {
                    if (!(i&(1<<num)))
                    {
                        mas|=(1<<i);
                    }
                }
                dp[v][mas]=1;
            }
        }
    }
    return v;
}

int main()
{
    scanf("%s", wcz+1);
    rek();
    scanf("%d", &n);
    while(n--)
    {
        int p1=0, p2=0;
        for (int i=0; i<4; i++)
        {
            scanf("%d", &p1);
            p2^=(p1<<i);
        }
        scanf("%d", &p1);
        for (int i=0; i<(1<<16); i++)
        {
            if (((i&(1<<p2))>>p2)!=p1)
            dp[1][i]=0;
        }
    }
    for (int i=0; i<(1<<16); i++)
    {
        wyn+=dp[1][i];
    }
    printf("%lld\n", wyn%mod);
    return 0;
}
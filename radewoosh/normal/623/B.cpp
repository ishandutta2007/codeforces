#include <bits/stdc++.h>
using namespace std;

int t;

int n;

long long a, b;

int tab[1000007];

long long dp[1000007][4];

long long wyn;

long long inf;

vector <int> kan;

int u;

void wrzu(int v)
{
    for (int i=2; i*i<=v; i++)
    {
        if (!(v%i))
        {
            kan.push_back(i);
            v/=i;
            i--;
        }
    }
    if (v>1)
    kan.push_back(v);
}

int main()
{
    inf=100000000;
    inf*=inf;
    wyn=inf;
    scanf("%d%lld%lld", &n, &a, &b);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    wrzu(tab[1]-1);
    wrzu(tab[1]);
    wrzu(tab[1]+1);
    wrzu(tab[n]-1);
    wrzu(tab[n]);
    wrzu(tab[n]+1);
    sort(kan.begin(), kan.end());
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=inf;
    for (int h=0; h<kan.size(); h++)
    {
        if (!h || kan[h]!=kan[h-1])
        {
            u=kan[h];
            for (int i=1; i<=n; i++)
            {
                dp[i][1]=inf;
                dp[i][2]=inf;
                dp[i][3]=inf;

                if (!((tab[i])%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]);
                if (!((tab[i]+1)%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]+b);
                if (!((tab[i]-1)%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]+b);

                dp[i][2]=min(dp[i][2], dp[i-1][1]+a);
                dp[i][2]=min(dp[i][2], dp[i-1][2]+a);

                if (!((tab[i])%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]);
                if (!((tab[i]+1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]+b);
                if (!((tab[i]-1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]+b);

                if (!((tab[i])%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]);
                if (!((tab[i]+1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]+b);
                if (!((tab[i]-1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]+b);
            }
            wyn=min(wyn, dp[n][1]);
            wyn=min(wyn, dp[n][3]);
            reverse(tab+1, tab+1+n);
            for (int i=1; i<=n; i++)
            {
                dp[i][1]=inf;
                dp[i][2]=inf;
                dp[i][3]=inf;

                if (!((tab[i])%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]);
                if (!((tab[i]+1)%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]+b);
                if (!((tab[i]-1)%u))
                dp[i][1]=min(dp[i][1], dp[i-1][1]+b);

                dp[i][2]=min(dp[i][2], dp[i-1][1]+a);
                dp[i][2]=min(dp[i][2], dp[i-1][2]+a);

                if (!((tab[i])%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]);
                if (!((tab[i]+1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]+b);
                if (!((tab[i]-1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][2]+b);

                if (!((tab[i])%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]);
                if (!((tab[i]+1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]+b);
                if (!((tab[i]-1)%u))
                dp[i][3]=min(dp[i][3], dp[i-1][3]+b);
            }
            wyn=min(wyn, dp[n][1]);
            wyn=min(wyn, dp[n][3]);
            reverse(tab+1, tab+1+n);
        }
    }
    printf("%lld\n", wyn);
    return 0;
}
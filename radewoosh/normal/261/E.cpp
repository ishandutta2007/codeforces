#include <bits/stdc++.h>
using namespace std;

int l, r, k;

int sito[107];

vector <long long> pie;

int n;
int tab[3000007];

int ok[3000007];

int dp[3000007];

int it;

int juz[3000007];

int wyn;

void rek(int v, long long w)
{
    if (v==pie.size() || w*pie[v]>r)
    {
        n++;
        tab[n]=w;
        return;
    }
    while(w<=r)
    {
        rek(v+1, w);
        w*=pie[v];
    }
}

int main()
{
    scanf("%d%d%d", &l, &r, &k);
    for (int i=2; i<=100; i++)
    {
        if (!sito[i])
        {
            pie.push_back(i);
            for (int j=i*i; j<=100; j+=i)
            {
                sito[j]=1;
            }
        }
    }
    rek(0, 1);
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        dp[i]=200;
        if (tab[i]>=l && tab[i]<=r)
        ok[i]=1;
    }
    dp[1]=0;
    for (int h=1; h<=k; h++)
    {
        it=1;
        for (int i=1; i<=n; i++)
        {
            while(it<=n && tab[i]*h>tab[it])
            it++;
            dp[it]=min(dp[it], dp[i]+1);
            if (!juz[i] && ok[i] && dp[i]+h<=k)
            {
                juz[i]=1;
                wyn++;
            }
        }
    }
    printf("%d\n", wyn);
    return 0;
}
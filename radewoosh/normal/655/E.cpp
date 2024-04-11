#include <bits/stdc++.h>
using namespace std;

int n, k;

char wcz[1000007];

long long dp[107];
long long mod=1000000007;

long long s;

int juz[1007];

vector <int> wek;

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", wcz+1);
    dp[0]=1;
    for (int i=1; 1; i++)
    {
        if (!wcz[i])
        {
            for (int j=i-1; j; j--)
            {
                if (juz[wcz[j]-'a'+1])
                continue;
                juz[wcz[j]-'a'+1]=1;
                wek.push_back(wcz[j]-'a'+1);
            }
            break;
        }
        s=0;
        for (int j=0; j<=26; j++)
        s+=dp[j];
        s%=mod;
        dp[wcz[i]-'a'+1]=s;
    }
    for (int i=1; i<=k; i++)
    {
        if (!juz[i])
        {
            wek.push_back(i);
        }
    }
    reverse(wek.begin(), wek.end());
    for (int i=0; i<n; i++)
    {
        s=0;
        for (int j=0; j<=26; j++)
        s+=dp[j];
        s%=mod;
        dp[wek[i%k]]=s;
    }
    s=0;
    for (int j=0; j<=26; j++)
    s+=dp[j];
    s%=mod;
    printf("%lld\n", s);
    return 0;
}
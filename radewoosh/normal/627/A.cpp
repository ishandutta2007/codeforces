#include <bits/stdc++.h>
using namespace std;

long long a, b;

vector <int> jed, dwa;

int n;

long long dp[107][2];

int tak;

int main()
{
    scanf("%lld%lld", &a, &b);
    tak=(a==b);
    while(a)
    {
        jed.push_back(a&1);
        a>>=1;
    }
    while(b)
    {
        dwa.push_back(b&1);
        b>>=1;
    }
    while(jed.size()<dwa.size())
    jed.push_back(0);
    while(jed.size()>dwa.size())
    dwa.push_back(0);
    n=dwa.size();
    dp[0][0]=1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<2; j++)
        {
            for (int o=0; o<2; o++)
            {
                for (int u=0; u<2; u++)
                {
                    if ((o^u)==dwa[i] && (o^u^j)==jed[i])
                    {
                        dp[i+1][(j+o+u)/2]+=dp[i][j];
                    }
                }
            }
        }
    }
    dp[n][0]-=2*tak;
    printf("%lld\n", dp[n][0]);
    return 0;
}
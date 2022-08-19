#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
vector <int> graf[1000007];

long long dp[1000007];

long long mno[1000007];

long long wyn;

int main()
{
    scanf("%d%d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &p1, &p2);
        if (p1>p2)
        swap(p1, p2);
        graf[p2].push_back(p1);
        mno[p1]++;
        mno[p2]++;
    }
    for (int i=1; i<=n; i++)
    {
        dp[i]=1;
        for (int j=0; j<graf[i].size(); j++)
        {
            dp[i]=max(dp[i], dp[graf[i][j]]+1);
        }
        wyn=max(wyn, (dp[i]*mno[i]));
    }
    printf("%lld\n", wyn);
    return 0;
}
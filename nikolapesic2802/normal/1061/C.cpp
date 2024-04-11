#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N=1e5+5,mod=1e9+7;
ll dp[N];
void add(int j)
{
    if(j<N-1)
        dp[j]=((ll)dp[j]+dp[j+1]+1)%mod;
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz(n);
    for(int i=0;i<n;i++)
        scanf("%i",&niz[i]);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j*j<=niz[i];j++)
        {
            if(niz[i]%j)
                continue;
            add(j);
            if(j*j!=niz[i])
                add(niz[i]/j);
        }
    }
    printf("%lld\n",dp[1]);
    return 0;
}
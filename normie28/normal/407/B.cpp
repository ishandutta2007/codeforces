#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
ll dp[1001][1001];
int p[1001] = {0};
 
ll m = 1e9+7;
ll solve(int i, int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = (1 + solve(i, j-1) + solve(p[j-1], j-1))%m;
    return dp[i][j];
}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> p[i], p[i]--;
    for(int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
            dp[i][j] = -1;
    cout << (solve(0,n)*2)%m;
    return 0;
}
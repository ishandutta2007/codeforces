#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N=502;
const int k=10;

long long int dp[N][N*k];
vector<int> c(100001,0);
vector<int> f(100001,0);
int joy[11];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n*k;i++)
    {
        int x;
        cin>>x;
        c[x]++;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        f[x]++;
    }
    joy[0]=0;
    for(int i=1;i<=k;i++)
        cin>>joy[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<N*10;j++)
        dp[i][j]=0;
    for(int x=0;x<=n;x++)
        for(int y=0;y<=k*n;y++)
    {
        for(int i=0;i<=k;i++)
        {
            dp[x+1][y+i]=max(dp[x+1][y+i],dp[x][y]+joy[i]);
        }
    }
    long long odp=0;
    for(int i=0;i<=100000;i++)
    {
        odp+=dp[f[i]][c[i]];
    }
    cout<<odp;
    return 0;
}
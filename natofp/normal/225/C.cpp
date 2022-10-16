#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1111;
bool plansza[N][N];
int ile0[N];
int ile1[N];
int dp[N][2];
vector<int> pref0;
vector<int> pref1;

int ile1na(int l,int r)
{
    if(l==0) return pref1[r];
    return pref1[r]-pref1[l-1];
}

int ile0na(int l,int r)
{
    if(l==0) return pref0[r];
    return pref0[r]-pref0[l-1];
}

int main()
{
    memset(ile0,0,sizeof ile0);
    memset(ile1,0,sizeof ile1);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2;j++)
        {
            dp[i][j]=1e9;
        }
    }
    int n,m,x,y; cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            if(x=='#') plansza[i][j]=1;
            else plansza[i][j]=0;
            if(plansza[i][j]==1)
            {
                ile1[j]++;
            }
            else ile0[j]++;
        }
    }
    pref0.push_back(0);
    pref1.push_back(0);
    for(int i=1;i<=m;i++)
    {
        int t=pref0[i-1];
        pref0.push_back(t+ile0[i]);
        t=pref1[i-1];
        pref1.push_back(t+ile1[i]);
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=m;i++)
    {
        if(i<x) continue;
        for(int j=x;j<=y;j++)
        {
            if(j>i) break;
            dp[i][0]=min(dp[i][0],j*n-ile0na(i-j+1,i)+dp[i-j][1]);
            dp[i][1]=min(dp[i][1],j*n-ile1na(i-j+1,i)+dp[i-j][0]);
        }

    }
    cout<<min(dp[m][0],dp[m][1]);
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
const int nax=555;
int dp[nax][nax];
int mod=998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    a.resize(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<nax;i++)
    {
        for(int j=0;j<nax;j++)
        {
            dp[i][j]=1;
        }
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+len-1;
            if(j>n) break;
            int akt=1e9;
            int idx=-1;
            for(int z=i;z<=j;z++)
            {
                if(a[z]<akt)
                {
                    akt=a[z]; idx=z;
                }
            }
            long long int lewo=0;
            long long int prawo=0;
            for(int z=i;z<=idx;z++)
            {
                lewo+=(long long int)dp[i][z-1]*dp[z][idx-1];
                lewo%=mod;
            }
            for(int z=idx;z<=j;z++)
            {
                prawo+=(long long int)dp[idx+1][z]*dp[z+1][j];
                prawo%=mod;
            }
            //if(i==1 && j==2) cout<<prawo<<" "<<lewo<<" "<<idx<<endl;
            long long int xd=prawo*lewo;
            xd%=mod;
            dp[i][j]=xd;
        }
    }
    cout<<dp[1][n];
    return 0;
}
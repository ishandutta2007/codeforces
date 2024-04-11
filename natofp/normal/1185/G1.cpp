#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=16;
int n,t;
int mod=1e9+7;

long long int dp[3][nax][nax][nax];
long long int s[55];

long long int memo(int first,int a,int b,int c)
{
    if(a<0 || b<0 || c<0) return 0;
    if(first==0 && a==0) return 0;
    if(first==1 && b==0) return 0;
    if(first==2 && c==0) return 0;
    if(dp[first][a][b][c]!=-1) return dp[first][a][b][c];
    dp[first][a][b][c]=0;
    if(first==0)
    {
        dp[first][a][b][c]+=memo(1,a-1,b,c);
        dp[first][a][b][c]+=memo(2,a-1,b,c);
    }
    if(first==1)
    {
        dp[first][a][b][c]+=memo(0,a,b-1,c);
        dp[first][a][b][c]+=memo(2,a,b-1,c);
    }
    if(first==2)
    {
        dp[first][a][b][c]+=memo(0,a,b,c-1);
        dp[first][a][b][c]+=memo(1,a,b,c-1);
    }
    dp[first][a][b][c]%=mod;
    return dp[first][a][b][c];
}

int main()
{
    int n,t; cin>>n>>t;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<nax;j++)
        {
            for(int k=0;k<nax;k++)
            {
                for(int z=0;z<nax;z++)
                {
                    dp[i][j][k][z]=-1;
                }
            }
        }
    }
    dp[0][1][0][0]=dp[1][0][1][0]=dp[2][0][0][1]=1;
    s[0]=1;
    for(int i=1;i<33;i++)
    {
        s[i]=(long long int)s[i-1]*i;
        s[i]%=mod;
    }
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    long long int res=0;
    for(int i=0;i<(1<<n);i++)
    {
        vector<pair<int,int> > akt;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                akt.push_back(a[j]);
            }
        }
        int sum=0;
        for(int j=0;j<akt.size();j++)
        {
            sum+=akt[j].first;
        }
        if(sum!=t) continue;
        int x1,x2,x3;
        x1=x2=x3=0;
        for(int j=0;j<akt.size();j++)
        {
            if(akt[j].second==1) x1++;
            else if(akt[j].second==2) x2++;
            else x3++;
        }
        long long int ans=memo(1,x1,x2,x3)+memo(0,x1,x2,x3)+memo(2,x1,x2,x3);
        ans%=mod;
        ans*=s[x1];
        ans%=mod;
        ans*=s[x2];
        ans%=mod;
        ans*=s[x3];
        ans%=mod;
        res+=ans;
        res%=mod;
    }
    cout<<res;
    return 0;
}
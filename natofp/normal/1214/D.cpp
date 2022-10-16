#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


struct pole
{
    int val;
    int r;
    int c;
};

const int nax=1e6+5;
int ilew[nax];
int ilek[nax];

int aktw[nax];
int aktk[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<char> a[n+1];
    vector<bool> dp[n+1];
    vector<bool> dp2[n+1];
    for(int i=1;i<=n;i++)
    {
        a[i].push_back('0');
        dp[i].push_back(0);
        dp2[i].push_back(0);
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            a[i].push_back(x);
            dp[i].push_back(0);
            dp2[i].push_back(0);
        }
    }
    dp[1][1]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 && j==1) continue;
            if(a[i][j]=='#') dp[i][j]=false;
            else
            {
                if(i-1>0 && dp[i-1][j]==true) dp[i][j]=true;
                if(j-1>0 && dp[i][j-1]==true) dp[i][j]=true;

            }
        }
    }
    dp2[n][m]=true;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(i==n && j==m) continue;
            if(a[i][j]=='#') dp2[i][j]=false;
            else
            {
                if(i+1<=n && dp2[i+1][j]==true) dp2[i][j]=true;
                if(j+1<=m && dp2[i][j+1]==true) dp2[i][j]=true;

            }
        }
    }
    if(dp[n][m]==false)
    {
        cout<<0; return 0;
    }
    vector<pair<int,int> > s1,s2;
    int i=1,j=1;
    s1.push_back({i,j});
    s2.push_back({i,j});
    while(i!=n || j!=m)
    {
        if(i<n && dp2[i+1][j]==true) i++;
        else j++;
        s1.push_back({i,j});
    }
    i=1; j=1;
    while(i!=n || j!=m)
    {
        if(j<m && dp2[i][j+1]==true) j++;
        else i++;
        s2.push_back({i,j});
    }
    for(int i=1;i<s1.size()-1;i++)
    {
        if(s1[i]==s2[i])
        {
            cout<<1; return 0;
        }
    }
    cout<<2;
    return 0;
}
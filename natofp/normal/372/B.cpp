#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int s[44][44];
int dp[44][44][44][44];
char t[44][44];

bool czy(int a,int b,int c,int d)
{
    int ans=0;
    ans+=s[c][d];
    ans-=s[a-1][d];
    ans-=s[c][b-1];
    ans+=s[a-1][b-1];
    if(ans==0) return true;
    return false;
}

int ile(int n)
{
    if(n) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+t[i][j]-'0';
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            for(int k=i;k<=n;k++)
            {
                for(int l=j;l<=m;l++)
                {
                    int &r=dp[i][j][k][l];
                    r=czy(i,j,k,l);
                    for(int mask=1;mask<16;mask++)
                    {
                        int x=__builtin_popcount(mask);
                        if(x%2==1)
                        {
                            r+=dp[i+ile(mask&1)][j+ile(mask&2)][k-ile(mask&4)][l-ile(mask&8)];
                        }
                        else
                        {
                            r-=dp[i+ile(mask&1)][j+ile(mask&2)][k-ile(mask&4)][l-ile(mask&8)];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c,d; cin>>a>>b>>c>>d;
        cout<<dp[a][b][c][d]<<endl;
    }
    return 0;
}
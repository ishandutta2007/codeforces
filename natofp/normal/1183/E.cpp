#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=105;

long long int dp[nax][nax];
int last[26];

int main()
{
    memset(dp,0,sizeof dp);
    memset(last,0,sizeof last);
    int n; cin>>n;
    long long int k; cin>>k;
    string t; cin>>t;
    string s;
    s="0"+t;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j>i)
            {
                dp[i][j]=0;
                continue;
            }
            if(j==0)
            {
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(dp[i][j]>=1e18) continue;
            dp[i][j]+=dp[i-1][j-1];
            if(last[s[i]-'a']!=0)
            {
                dp[i][j]-=dp[last[s[i]-'a']-1][j-1];
            }

        }
        last[s[i]-'a']=i;
    }
    long long int res=0;
    for(int i=n;i>=0;i--)
    {
        long long int moge=dp[n][i];
        long long int trzeba=k;
        long long int biore=min(k,moge);
        k-=biore;
        res+=biore*(n-i);
    }
    if(k==0) cout<<res;
    else cout<<-1<<endl;
    return 0;
}
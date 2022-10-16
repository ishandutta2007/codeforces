#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5;
long long int dp[nax+5][10];
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<nax;i++)
    {
        for(int j=0;j<10;j++)
        {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    vector<long long int> a;
    vector<long long int> b;
    vector<long long int> c;
    for(int i=1;i<=n;i++)
    {
        a.clear(); b.clear(); c.clear();
        int k; cin>>k;
        for(int j=0;j<k;j++)
        {
            int x,y; cin>>x>>y;
            if(x==1) a.push_back(y);
            else if(x==2) b.push_back(y);
            else c.push_back(y);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        reverse(c.begin(),c.end());
        for(int j=0;j<10;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(a.size()>=3)
            {
                int pos=(j+10-3)%10;
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*a[0]+a[1]+a[2]);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+a[0]+a[1]+a[2]);
                    }
                }
            }
            if(a.size()>=1)
            {
                int pos=(j+10-1)%10;
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*a[0]);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+a[0]);
                    }
                }
            }
            if(b.size()>=1)
            {
                int pos=(j+10-1)%10;
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*b[0]);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+b[0]);
                    }
                }
            }
            if(c.size()>=1)
            {
                int pos=(j+10-1)%10;
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*c[0]);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+c[0]);
                    }
                }
            }
            if(a.size()>=2)
            {
                int pos=(j+10-2)%10;
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*a[0]+a[1]);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+a[0]+a[1]);
                    }
                }
            }
            if(a.size()>=1 && b.size()>=1)
            {
                int pos=(j+10-2)%10;
                long long int t1=max(a[0],b[0]);
                long long int t2=min(a[0],b[0]);
                if(dp[i-1][pos]!=-1)
                {
                    if(pos>j)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+2*t1+t2);
                    }
                    else
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][pos]+t1+t2);
                    }
                }
            }
        }
    }
    long long int res=0;
    for(int i=0;i<10;i++) res=max(res,dp[n][i]);
    cout<<res;
    return 0;
}
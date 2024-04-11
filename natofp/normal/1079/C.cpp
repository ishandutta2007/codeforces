#include <iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    int n; cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<bool> dp[5];
    for(int i=0;i<5;i++) dp[i].push_back(1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            dp[j].push_back(0);
            if(a[i]>a[i-1])
            {
                for(int k=0;k<5;k++)
                {
                    if(dp[k][i-1]==1 && k<j) dp[j][i]=true;
                }
            }
            else if(a[i]<a[i-1])
            {
                for(int k=0;k<5;k++)
                {
                    if(dp[k][i-1]==1 && k>j) dp[j][i]=true;
                }
            }
            else
            {
                for(int k=0;k<5;k++)
                {
                    if(dp[k][i-1]==1 && k!=j) dp[j][i]=true;
                }
            }
        }
    }
    bool xd=false;
    for(int i=0;i<5;i++)
    {
        if(dp[i][n-1]==true) xd=true;
    }
    if(xd==false) {cout<<-1; return 0;}
    vector<int> ans(n);
    for(int i=0;i<5;i++)
    {
        if(dp[i][n-1]==1) ans[n-1]=i;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            for(int j=0;j<5;j++)
            {
                if(dp[j][i]==1 && j>ans[i+1]) ans[i]=j;
            }
        }
        else if(a[i]<a[i+1])
        {
            for(int j=0;j<5;j++)
            {
                if(dp[j][i]==1 && j<ans[i+1]) ans[i]=j;
            }
        }
        else
        {
            for(int j=0;j<5;j++)
            {
                if(dp[j][i]==1 && j!=ans[i+1]) ans[i]=j;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]+1<<" ";
    return 0;
}
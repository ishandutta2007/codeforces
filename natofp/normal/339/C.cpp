#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool dp[1111][11][11];
int pop[1111][11][11];
int main()
{
    string s; cin>>s;
    int m; cin>>m;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=10;j++)
        {
           for(int k=0;k<=10;k++)
           {
               dp[i][j][k]=false;
               pop[i][j][k]=0;
           }
        }
    }
    for(int i=0;i<10;i++)
    {
        if(s[i]=='1') dp[1][i+1][i+1]=true;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=10;j++)
        {
            for(int k=1;k<=10;k++)
            {
                if(s[k-1]=='1')
                {
                    if(k>j)
                    {
                        int starawaga=k-j;
                        for(int c=1;c<=10;c++)
                        {
                            if(dp[i-1][starawaga][c]==true && c!=k)
                            {
                                dp[i][j][k]=true;
                                pop[i][j][k]=c;
                            }
                        }
                    }
                }
            }
        }
    }
    bool ok=false;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(dp[m][i][j]==true) ok=true;
        }

    }
    if(ok==false) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    vector<int> ans;
    int idx=-1;
    int waga;
    for(int i=1;i<=10;i++)
    {
        for(int k=1;k<=10;k++)
        {
            if(dp[m][i][k]==true) {idx=i; waga=k;}
        }
    }
    for(int i=m;i>=1;i--)
    {
        ans.push_back(waga);
        int nowaroznica=waga-idx;
        int nowawaga=pop[i][idx][waga];
        idx=nowaroznica;
        waga=nowawaga;

    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=5005;
int a[nax];
int lefft[nax];
int riight[nax];
int dp[nax];
bool czy[nax];
int pre[nax];


int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<nax;i++)
    {
        riight[i]=-1;
        lefft[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        riight[a[i]]=i;
        if(lefft[a[i]]==-1) lefft[a[i]]=i;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<nax;j++) czy[j]=false;
        if(riight[a[i]]!=i)
        {
            dp[i]=0;
            pre[i]=pre[i-1];
            continue;
        }
        int res=a[i];
        czy[a[i]]=true;
        bool ok = true;
        int dokad=lefft[a[i]];
        for(int j=i;j>=1;j--)
        {
        if(ok==false) break;
            if(riight[a[j]]>i)
            {
                pre[i]=max(pre[i-1],dp[i]);
                ok = false;
                break;
            }
            dokad=min(dokad,lefft[a[j]]);
            if(czy[a[j]]==false)
            {
                res^=a[j];
                czy[a[j]]=true;
            }
            if(j==dokad)
            {
                dp[i]=max(dp[i],res+pre[j-1]);
            }

        }



        pre[i]=max(pre[i-1],dp[i]);
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    cout<<res;
    return 0;
}
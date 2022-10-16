#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,q;
const int nax=3e5+5;
int a[nax];
const int k=20;

int dp[nax][k];
int last[k];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<k;i++) last[i]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j]=n+1;
        }
        for(int j=0;j<k;j++)
        {
            if(a[i]&(1<<j))
            {
                int akt=last[j];
                if(akt>n) continue;
                for(int x=0;x<k;x++)
                {
                    dp[i][x]=min(dp[i][x],dp[akt][x]);
                }
            }
        }
        for(int j=0;j<k;j++)
        {
            if(a[i]&(1<<j))
            {
                dp[i][j]=i;
            }
        }
        for(int j=0;j<k;j++)
        {
            if(a[i]&(1<<j))
            {
                last[j]=i;
            }
        }
    }
    while(q--)
    {
        int x,y; cin>>x>>y;
        bool ok=false;
        for(int j=0;j<k;j++)
        {
            if(a[y]&(1<<j))
            {
                if(dp[x][j]<=y) ok = true;
            }
        }
        if(ok) cout<<"Shi"<<endl;
        else cout<<"Fou"<<endl;
    }
    return 0;
}
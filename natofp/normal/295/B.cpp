#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int d[505][505];

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>d[i][j];
        }
    }
    vector<int> a;
    vector<long long int>ans(n,0);
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; x--;
        a.push_back(x);
    }
    reverse(a.begin(),a.end());
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]=min(d[i][j],d[i][a[k]]+d[a[k]][j]);
            }
        }
        for(int x=0;x<k+1;x++)
        {
            for(int y=0;y<k+1;y++)
            {
                ans[k]+=d[a[x]][a[y]];
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
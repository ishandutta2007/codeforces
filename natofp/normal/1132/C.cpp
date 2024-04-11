#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=5005;
int tab[N];
vector<pair<int,int> > rob;
vector<int> dowo(N,0);
int xxx[N][N];
vector<int> a[N];
int main()
{
    memset(tab,0,sizeof tab);
    memset(xxx,0,sizeof xxx);
    int n,q; cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        int l,r; cin>>l>>r;
        rob.push_back({l,r});
        for(int j=l;j<=r;j++) tab[j]++;
    }
    for(int i=0;i<q;i++)
    {
        int l=rob[i].first;
        int r=rob[i].second;
        for(int j=l;j<=r;j++)
        {
            if(tab[j]<=2)
            {
                if(tab[j]==1) dowo[i]++;
                else if(tab[j]==2)
                {
                    a[j].push_back(i);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].size()!=0)
        {
            int x,y;
            x=a[i][0];
            y=a[i][1];
            xxx[x][y]++;
            xxx[y][x]++;
        }
    }
    int ans=1e9;
    int ile=0;
    for(int i=1;i<=n;i++)
    {
        if(tab[i]!=0) ile++;
    }
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<q;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                ans=min(ans,dowo[i]+dowo[j]+xxx[i][j]);
            }
        }
    }
    cout<<ile-ans;
    return 0;
}
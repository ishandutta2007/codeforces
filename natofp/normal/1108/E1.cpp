#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> res;
vector<int> xd;

int main()
{
    int n,m; cin>>n>>m;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<int,int> > s;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        x--; y--;
        s.push_back({x,y});
    }
    int ans=0;
    int * b=new int[n];

    for(int i=0;i<n;i++)
    {
        res.clear();
        for(int j=0;j<n;j++)
        {
            b[j]=a[j];
        }
        for(int j=0;j<m;j++)
        {
            int x,y;
            x=s[j].first;
            y=s[j].second;
            if(i>=x && i<=y)
            {
                res.push_back(j+1);
                for(int k=x;k<=y;k++) b[k]--;
            }
        }
        int minn=1e9;
        int maxx=-1e9;
        for(int j=0;j<n;j++)
        {
            minn=min(minn,b[j]);
            maxx=max(maxx,b[j]);
        }
        if(maxx-minn>ans)
        {
            ans=maxx-minn;
            xd=res;
        }
    }
    cout<<ans<<endl;
    cout<<xd.size()<<endl;
    for(int i=0;i<xd.size();i++) cout<<xd[i]<<" ";
    return 0;
}
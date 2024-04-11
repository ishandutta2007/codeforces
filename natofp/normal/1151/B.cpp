#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=555;
int a[nax][nax];
vector<bool> czy(nax,false);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int val=a[i][1];
        for(int j=2;j<=m;j++)
        {
            if(a[i][j]!=val) czy[i]=true;
        }
    }
    int idx=-1;
    for(int i=1;i<=n;i++)
    {
        if(czy[i]==true) idx=i;
    }
    if(idx==-1)
    {
        vector<int> ans;
        int odp=0;
        for(int i=1;i<=n;i++)
        {
            odp^=a[i][1];
            ans.push_back(1);
        }
        if(odp==0) {cout<<"NIE"; return 0;}
        cout<<"TAK"<<endl;
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        return 0;
    }
    else if(idx!=-1)
    {
        int odp=0;
        for(int i=1;i<=n;i++)
        {
            if(i==idx) continue;
            odp^=a[i][1];
        }
        vector<int> ans;
        cout<<"TAK"<<endl;
        for(int i=1;i<idx;i++) ans.push_back(1);
        for(int j=1;j<=m;j++)
        {
            if(a[idx][j]!=odp)
            {
                ans.push_back(j); break;
            }
        }
        for(int i=idx+1;i<=n;i++) ans.push_back(1);
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}
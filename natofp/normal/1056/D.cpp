#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> G[100005];
vector<int> ile(100005,123123123);

int DFS(int v,int d)
{
    int ans=0;
    if(d!=-1)
    {
        if(G[v].size()==1)
        {
            ile[v]=1;
            return 1;
        }
    }
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]!=d)
        {
            ans+=DFS(G[v][i],v);
        }
    }
    ile[v]=ans;
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    if(n==1)
    {
        cout<<1<<endl; return 0;
    }
    for(int i=2;i<=n;i++)
    {
        int x; cin>>x;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    DFS(1,-1);
    sort(ile.begin(),ile.end());
    for(int i=0;i<n;i++)
    {
        cout<<ile[i]<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int> higher[100001];
int deg[100001];
int n,m,i,j,k,t,t1,u,v,a,b;
long long res;
int main()
{
    cin>>n;
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        higher[min(u,v)].push_back(max(u,v));
    }
    for (i=1;i<=n;i++) res+=(long long)higher[i].size()*(deg[i]-higher[i].size());
    cin>>t;
            cout<<res<<endl;
    for (t1=0;t1<t;t1++)
    {
        cin>>v;
        for (auto g : higher[v])
        {
            res-=(long long)higher[g].size()*(deg[g]-higher[g].size());
            higher[g].push_back(v);
            res+=(long long)higher[g].size()*(deg[g]-higher[g].size());
        }
            res-=(long long)higher[v].size()*(deg[v]-higher[v].size());
            higher[v].clear();
            cout<<res<<endl;
    }
}
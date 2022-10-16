#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int nax=1005;
vector<int> adj[nax];
int deg[nax];
bool used[nax];

int zap(int u,int v)
{
    cout<<"?"<<" "<<u<<" "<<v<<endl;
    fflush(stdout);
    int x; cin>>x;
    return x;
}

bool por(int a,int b)
{
    if(deg[a]==deg[b]) return a<b;
    return deg[a]<deg[b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    while(1)
    {
        vector<int> xd;
        for(int i=1;i<=n;i++)
        {
            if(used[i]==false) xd.push_back(i);
        }
        sort(xd.begin(),xd.end(),por);
        if(xd.size()==1)
        {
            cout<<"! "<<xd[0]<<endl;
            fflush(stdout);
            return 0;
        }
        int kappa=zap(xd[0],xd[1]);
        if(kappa==xd[0])
        {
            cout<<"! "<<xd[0]<<endl;
            fflush(stdout);
            return 0;
        }
        if(kappa==xd[1])
        {
            cout<<"! "<<xd[1]<<endl;
            fflush(stdout);
            return 0;
        }
        int a,b;
        a=xd[0];
        b=xd[1];
        used[a]=true;
        used[b]=true;
        for(int i=0;i<adj[a].size();i++) deg[adj[a][i]]--;
        for(int i=0;i<adj[b].size();i++) deg[adj[b][i]]--;
    }


    return 0;
}
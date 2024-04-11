#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;
vector<int> adj[N];
vector<int> a(N,0);
int dzielniki[N][7];
int res[N][6];
vector<bool> visited(N,false);
void rozloz(int v)
{
    int n=a[v];
    vector<int> ans;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans.push_back(n);
    for(int i=0;i<ans.size();i++)
    {
        dzielniki[v][i]=ans[i];
    }
}

void dfs(int v,int p=-1)
{
    visited[v]=true;
    if(adj[v].size()==1)
    {
        int i=0;
        while(dzielniki[v][i]!=-1)
        {
            res[v][i]=1; i++;
        }
    }
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs(adj[v][i],v);
    }
    int i=0;
    while(dzielniki[v][i]!=-1)
    {
        res[v][i]=1;
        for(int j=0;j<adj[v].size();j++)
        {
            int akt=adj[v][j];
            if(akt==p) continue;
            int k=0;
            while(dzielniki[akt][k]!=-1)
            {
                if(dzielniki[akt][k]==dzielniki[v][i]) res[v][i]=max(res[v][i],res[akt][k]+1);

                k++;
            }
        }
        i++;
    }

}

int ans=0;

void dfs2(int v,int p=-1)
{
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false) dfs2(adj[v][i],v);
    }
    int i=0;
    while(dzielniki[v][i]!=-1)
    {
        int x=0,y=0;
        for(int j=0;j<adj[v].size();j++)
        {
            int t=adj[v][j];
            if(t==p) continue;
            int k=0;
            while(dzielniki[t][k]!=-1)
            {
                if(dzielniki[t][k]==dzielniki[v][i])
                {
                    x=max(x,res[t][k]);
                    if(x>y) swap(x,y);
                }
                k++;
            }
            ans=max(ans,x+y+1);
        }
        ans=max(ans,1);
        i++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        if(a[1]>1) cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(res,0,sizeof res);
    memset(dzielniki,-1,sizeof dzielniki);
    for(int i=1;i<=n;i++) rozloz(i);
    dfs(1);
    for(int i=0;i<N;i++) visited[i]=false;
    dfs2(1);
    cout<<ans;
    return 0;
}
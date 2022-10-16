#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
vector<int> adj[nax];
int t=1;
vector<int> preorder(nax,0);
vector<int> postorder(nax,0);
vector<bool> blocked(nax,false);
vector<int> poziom(nax,0);
vector<int> poddrzewo(nax,0);
vector<int> ojciec(nax,-1);
int poziom_x;
int n;
int akt=1;
int roz;


void dfs(int v,int p)
{
    preorder[v]=t++;
    ojciec[v]=p;
    if(v==1) poziom[v]=0;
    else poziom[v]=poziom[p]+1;
    for(int i=0;i<adj[v].size();i++)
    {
        if(adj[v][i]==p) continue;
        dfs(adj[v][i],v);
    }
    postorder[v]=t++;
}

bool czy_ancestor(int u,int v)
{
    if(preorder[u]<preorder[v] && postorder[u]>postorder[v]) return true;
    return false;
}

int przelicz(int v,int p)
{
    poddrzewo[v]=1;
    for(int i=0;i<adj[v].size();i++)
    {
        if(blocked[adj[v][i]]==true || adj[v][i]==p) continue;
        poddrzewo[v]+=przelicz(adj[v][i],v);
    }
    return poddrzewo[v];
}

int znajdz_centroid(int v)
{
    przelicz(v,v);
    int p=-1;
    while(1)
    {
        bool ok = true;
        for(int i=0;i<adj[v].size();i++)
        {
            if(blocked[adj[v][i]]==true || adj[v][i]==p) continue;
            int syn=adj[v][i];
            if(poddrzewo[syn]*2>roz)
            {
                p=v;
                v=syn;
                ok = false;
                break;
            }
        }
        if(ok)
        {
            return v;
        }
    }
}

int d(int x)
{
    cout<<'d'<<" "<<x<<endl;
    fflush(stdout);
    int xd;
    cin>>xd;
    return xd;
}

int s(int x)
{
    cout<<'s'<<" "<<x<<endl;
    fflush(stdout);
    int xd;
    cin>>xd;
    return xd;
}

void wypisz(int x)
{
    cout<<"!"<<" "<<x<<endl;
    fflush(stdout);
    exit(0);
}

int ilema(int v,int p)
{
    int res=1;
    for(int i=0;i<adj[v].size();i++)
    {
        if(blocked[adj[v][i]]==true || adj[v][i]==p) continue;
        res+=ilema(adj[v][i],v);
    }
    return res;
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    roz=n;
    poziom_x=d(1);
    while(roz>2)
    {
        int v=znajdz_centroid(akt);
        // v to CENTROID
        int odl=d(v);
        if(odl==0) wypisz(v);
        blocked[v]=true;
        if(poziom_x!=odl+poziom[v])
        {
            // jest w innym poddrzewie CALEGO DRZEWA
            akt=ojciec[v];
            roz=ilema(akt,akt);
        }
        else
        {
            akt=s(v);
            roz=ilema(akt,akt);
        }
    }
    if(roz==1) wypisz(akt);
    else
    {
        int dist=d(akt);
        if(dist==0) wypisz(akt);
        for(int i=0;i<adj[akt].size();i++)
        {
            if(blocked[adj[akt][i]]==false) wypisz(adj[akt][i]);
        }
    }

    return 0;
}
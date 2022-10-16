#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
vector<int> adj[nax];
int numer=1;
int numer2=1;
vector<int> preorder(nax,0);
vector<int> postorder(nax,0);
vector<int> jakie(nax,0);
void dfs(int v,int p)
{
    preorder[v]=numer++;
    for(int i=0;i<adj[v].size();i++)
    {
        int to=adj[v][i];
        if(to==p) continue;
        dfs(to,v);
    }
    postorder[v]=numer2++;
}

bool czy(int u,int v)
{
    if(preorder[u]<=preorder[v] && postorder[u]>=postorder[v]) return true;
    return false;
}

int main()
{
   int n,q; cin>>n>>q;
   for(int i=2;i<=n;i++)
   {
       int a; cin>>a;
       adj[a].push_back(i);
       adj[i].push_back(a);
   }
   dfs(1,1);
   for(int i=1;i<=n;i++)
   {
       jakie[preorder[i]]=i;
   }
   while(q--)
   {
       int v,k; cin>>v>>k;
       int ile=preorder[v];
       ile+=k-1;
       if(ile>n) {cout<<-1<<endl; continue;}
       int jaki=jakie[ile];
       if(czy(v,jaki)) cout<<jaki<<endl;
       else cout<<-1<<endl;
   }
    return 0;
}
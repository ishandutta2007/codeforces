#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int long long n,x,y;
bool visited[300001];
vector <int> graf[300001];
long long int subarray[300001];
bool czy[300001];

long long int dfs(int v,int p=-1)
{
    subarray[v]=1;
    if(v==x) czy[v]=true;
    else czy[v]=false;
    for(int i=0;i<graf[v].size();i++)
    {
        if(graf[v][i]==p) continue;
        subarray[v]+=dfs(graf[v][i],v);
        czy[v]|=czy[graf[v][i]];
    }
    return subarray[v];

}

int main()
{
    cin>>n>>x>>y;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int licznik;
    dfs(y);
    for(int i=0;i<graf[y].size();i++)
    {
        int u=graf[y][i];
        if(czy[u]==true) {licznik=subarray[u]; break;}
    }
    cout<<(n*(n-1)-subarray[x]*(subarray[y]-licznik));
    return 0;
}
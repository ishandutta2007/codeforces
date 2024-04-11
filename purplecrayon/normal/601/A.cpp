#include<bits/stdc++.h>
using namespace std;
int ddt;       //ddt false->trainpath
int n,m;
int path[401][401];
queue<int>q;
queue<int>dist;
int ll=1e9;
bool visited[401];

void bfs()
{
    while(!q.empty())
    {
        int x=q.front();
        int l=dist.front();
        q.pop();dist.pop();
        if(x==n){ll=min(ll,l);return;}
        for(int i=1;i<=n;i++)
        {
            if(path[x][i]==ddt&&visited[i]==false) {q.push(i);dist.push(l+1); visited[i] = true; }
        }
    }
}


int main()
{
    for(int i=0;i<401;i++) visited[i]=false;
    for(int i=1;i<401;i++) for(int j=1;j<401;j++) path[i][j]=0;
    cin>>n>>m;
    ddt=1;
    while(m--)
    {
        int a,b;cin>>a>>b;
        path[a][b]=path[b][a]=1;
        if((a==1&&b==n)||(a==n&&b==1)) ddt=0;
    }
    q.push(1); visited[1] = true;
    dist.push(0);
    bfs();
    if(ll!=1e9) cout<<ll;
    else cout<<-1;
    
}
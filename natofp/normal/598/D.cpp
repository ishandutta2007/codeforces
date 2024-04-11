#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> tab[1000];
vector<bool> visited[1000];
vector<int> SC[1000];
vector<bool> policzone[1000];
int ile=1;
int n,m;
void bfs(int x,int y,int p)
{
    if(x<0 || y<0 || x>=n || y>=m) return ;
    if(visited[x][y]==true) return;
    if(tab[x][y]==0)
    {
        visited[x][y]=true;
        return;
    }
    visited[x][y]=true;
    SC[x][y]=ile;
    bfs(x+1,y,1);
    bfs(x-1,y,1);
    bfs(x,y-1,1);
    bfs(x,y+1,1);
    if(p==0) ile++;
}
int wynik;
vector<pair<int,int> > xd;
void check(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m) return ;
    if(tab[x][y]==0 )
    {
        wynik++;


        return;
    }
    return ;
}
void getans(int x,int y)
{

    if(x<0 || y<0 || x>=n || y>=m) return;
    if(tab[x][y]==0) return ;
    if(visited[x][y]==true) return;
    visited[x][y]=true;
    check(x+1,y);
    check(x-1,y);
    check(x,y+1);
    check(x,y-1);
    getans(x+1,y);
    getans(x-1,y);
    getans(x,y+1);
    getans(x,y-1);
    return ;

}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char x; cin>>x;
            if(x=='.') tab[i].push_back(1);
            else tab[i].push_back(0);
            visited[i].push_back(false);
            SC[i].push_back(-1);
            policzone[i].push_back(false);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==false)
            {
                bfs(i,j,0);
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        visited[i][j]=false;
    }
    vector<int> ans(ile,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(SC[i][j]!=-1 && ans[SC[i][j]]==0)
            {
                wynik=0;
                getans(i,j);
                ans[SC[i][j]]=wynik;

            }
        }
    }
    for(int i=0;i<k;i++)
    {
        int a,b; cin>>a>>b;
        a--; b--;
        cout<<ans[SC[a][b]]<<endl;
    }
    return 0;
}
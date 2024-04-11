#include<stdio.h>  
#include<string.h>  
#include<vector>  
using namespace std;  
int color[200500];  
int p[100500][2];  
int vis[200500];  
vector<int >mp[200500];  
void Dfs(int u,int col)  
{  
    color[u]=col;  
    vis[u]=1;  
    for(int i=0;i<mp[u].size();i++)  
    {  
        int v=mp[u][i];  
        if(vis[v]==0)  
        {  
            Dfs(v,3-col);  
        }  
    }  
}  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        for(int i=1;i<=n;i++)  
        {  
            int x,y;  
            scanf("%d%d",&x,&y);  
            p[i][0]=x;  
            p[i][1]=y;  
            mp[x].push_back(y);  
            mp[y].push_back(x);  
            mp[2*i].push_back(2*i-1);  
            mp[2*i-1].push_back(2*i);  
        }  
        memset(vis,0,sizeof(vis));  
        for(int i=1;i<=2*n;i++)  
        {  
            if(vis[i]==0)  
            {  
                vis[i]=1;  
                Dfs(i,1);  
            }  
        }  
        for(int i=1;i<=n;i++)  
        {  
            printf("%d %d\n",color[p[i][0]],color[p[i][1]]);  
        }  
    }  
}
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<vector>  
#include<set>  
using namespace std;  

const int MAXN=200+100;  

set<int> g[MAXN];  

int deg[MAXN];  

vector<pair<int,int> >res;  
int n,m;  

void init()  
{  
    memset(deg,0,sizeof(deg));  
    for(int i=0;i<MAXN;i++) g[i].clear();  
    res.clear();  
}  

void dfs(int u)  
{  
    while(g[u].size())  
    {  
        int v=*g[u].begin();  
        g[u].erase(v),g[v].erase(u);  
        if(u!=n+1&&v!=n+1)  
         printf("%d %d\n",u,v);  
        dfs(v);  
    }  
}  
int main()  
{  
    int cas;  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        init();  
        scanf("%d%d",&n,&m);  
        while(m--)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            g[u].insert(v),g[v].insert(u);  
            deg[u]++,deg[v]++;  
        }  
        int ans=0;  
        for(int i=1;i<=n;i++)  
		    if(deg[i]&1) 
				ans++,g[i].insert(n+1),g[n+1].insert(i);  
        printf("%d\n",n-ans);  
        for(int i=1;i<=n;i++) 
			dfs(i);  
          
    }  
    return 0;  
}
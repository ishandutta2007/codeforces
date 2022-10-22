#include <iostream>  
#include <algorithm>  
#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
#include <string>  
#include <ctime>  
using namespace std;  
#define INF 0x3f3f3f3f  
#define ULL unsigned long long  
#define LL long long  
#define fi first  
#define se second  
#define P pair<int,bool>  
  
const int MAXV=100000+3;  
int V, E;  
vector<pair<int, int> > G[MAXV]; 
vector<int> circle; 
int dist[MAXV]; 
bool vis[MAXV];  
  
void add(int x)
{  
    for(int i=0;i<circle.size();++i)  
        x=min(x, x^circle[i]);  
    if(x)  
        circle.push_back(x);  
}  
  
void dfs(int u)
{  
    vis[u]=true;  
    for(int i=0;i<G[u].size();++i)  
    {  
        int v=G[u][i].fi;  
        if(!vis[v])  
        {  
            dist[v]=dist[u]^G[u][i].se;  
            dfs(v);  
        }  
        else add(dist[v]^G[u][i].se^dist[u]);  
    }  
}  
  
int main()  
{  
    scanf("%d%d", &V, &E);  
    for(int i=0;i<E;++i)  
    {  
        int u, v, c;  
        scanf("%d%d%d", &u, &v, &c);  
        G[u].push_back(make_pair(v, c));  
        G[v].push_back(make_pair(u, c));  
    }  
    dfs(1);  
    for(int i=0;i<circle.size();++i)
        dist[V]=min(dist[V], dist[V]^circle[i]);  
    printf("%d\n", dist[V]);  
      
    return 0;  
}
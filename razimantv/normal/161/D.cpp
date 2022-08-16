# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <queue>
# include <string>

using namespace std;

vector<int> adjlist[50000];
long long tot=0;
int countdown[50000][501];
char seen[50000];
int N,K;

void dfs(int u)
{
    seen[u]=1;
    countdown[u][0]=1;
    for(int i=0;i<adjlist[u].size();i++)
    {
        int v=adjlist[u][i];
        if(seen[v])continue;
        dfs(v);
        for(int j=0;j<=K;j++)
        {
            if(j<K)tot+=countdown[v][K-j-1]*(long long)countdown[u][j];
            if(j)countdown[u][j]+=countdown[v][j-1];
        }
    }
}

int main()
{
    scanf("%d%d",&N,&K);
    
    for(int i=1;i<N;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adjlist[--a].push_back(--b);
        adjlist[b].push_back(a);
    }
    
    dfs(0);
    cout<<tot<<endl;
    return 0;
}
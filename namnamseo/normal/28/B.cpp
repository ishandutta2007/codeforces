#include <cstdio>

int n;
int data[101];
int dist[101];

void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

bool edge[101][101];

bool vis[101];

void dfs(int x){
    int i;
    vis[x]=1;
    for(i=1;i<=n;++i) {
        if(!vis[i] && edge[x][i]){
            dfs(i);
        }
    }
}

int main()
{
    read(n);
    int i;
    for(i=1;i<=n;++i) read(data[i]);
    for(i=1;i<=n;++i) {
        read(dist[i]);
        int a;
        a=i-dist[i];
        if(a>=1) edge[a][i]=true, edge[i][a]=true;
        a=i+dist[i];
        if(a<=n) edge[a][i]=true, edge[i][a]=true;
    }
    for(i=1;i<=n;++i){
        int a=data[i];
        for(int j=1;j<=n;++j) vis[j]=0;
        dfs(a);
        if(!vis[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
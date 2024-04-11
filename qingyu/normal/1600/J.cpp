#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1};
const int dy[4]={-1,0,1,0};
int n,m,cnt,a[1100][1100],tot[1100000]; bool vis[1100][1100];
void dfs(int x,int y){
    if (vis[x][y]) return;
    vis[x][y]=true; tot[cnt]++;
    for (int d=0;d<4;d++)
        if (!((a[x][y]>>d)&1)) dfs(x+dx[d],y+dy[d]);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (!vis[i][j]){
                cnt++;
                dfs(i,j);
            }
    sort(tot+1,tot+cnt+1,greater<int>());
    for (int i=1;i<=cnt;i++) printf("%d ",tot[i]);
    return 0;
}
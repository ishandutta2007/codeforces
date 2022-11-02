#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
vector<int> a[200010];
int n,vis[200010],b[100010][2];
void dfs(int x,int y){
    vis[x]=y;
    for (int i=0;i<a[x].size();i++)
    if (!vis[a[x][i]]) dfs(a[x][i],3^y);
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int o,p;
        scanf("%d%d",&b[i][0],&b[i][1]);
        a[b[i][0]].push_back(b[i][1]);
        a[b[i][1]].push_back(b[i][0]);
    }
    for (int i=0;i<n;i++){
        a[i*2+1].push_back(i*2+2);
        a[i*2+2].push_back(i*2+1);
    }
    for (int i=1;i<=2*n;i++) if (!vis[i]) dfs(i,1);
    for (int i=0;i<n;i++) printf("%d %d\n",vis[b[i][0]],vis[b[i][1]]);
    return 0;
}
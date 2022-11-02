#include<bits/stdc++.h>
using namespace std;
int t,n,a[1010],b[1010],vis[1010];
vector<int> edge[1010];
queue<int> q;
int bfs(int s){
    memset(vis,0,sizeof(vis));
    while (!q.empty()) q.pop();
    vis[s]=1;
    q.push(s);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        if (a[now]) return now;
        for (int i=0;i<edge[now].size();i++)
        if (!vis[edge[now][i]]){
            vis[edge[now][i]]=1;
            q.push(edge[now][i]);
        }
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        int o,p;
        for (int i=1;i<n;i++){
            scanf("%d%d",&o,&p);
            edge[o].push_back(p);
            edge[p].push_back(o);
        }
        scanf("%d",&o);
        for (int i=0;i<o;i++){
            scanf("%d",&p);
            a[p]=1;
        }
        scanf("%d",&o);
        for (int i=0;i<o;i++){
            scanf("%d",&p);
            b[p]=1;
        }
        printf("B %d\n",p);
        fflush(stdout);
        scanf("%d",&o);
        o=bfs(o);
        printf("A %d\n",o);
        fflush(stdout);
        int t;
        scanf("%d",&t);
        if (b[t]) printf("C %d\n",o);
        else printf("C -1\n");
        fflush(stdout);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) edge[i].clear();
    }
}
#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n,k;
int p[maxn];
vector<int> a[maxn];
int nd[maxn];
int pc[maxn];
bool forb[maxn];
bool vis[maxn];
int ord[maxn];
void dfs_prec(int u) {
    nd[u]=1;
    pc[u]=0;
    for(auto v:a[u]) {
        dfs_prec(v);
        if(nd[v]+1>nd[u]) {
            nd[u]=nd[v]+1;
            pc[u]=v;
        }
    }
}
void dfs(int u,int r,int c) {
    vis[u]=true;
    if(r==0 && c==0) return;
    if(r==0) {
        if(ord[nd[1]-c]==u) {
            printf("%d ",pc[u]);
            dfs(pc[u],r,c-1);
        }
        else {
            printf("%d ",p[u]);
            dfs(p[u],r,c);
        }
        return;
    }
    else {
        if(forb[u]) {
            for(auto v:a[u]) {
                if(vis[v] || pc[u]==v) continue;
                printf("%d ",v);
                dfs(v,r-1,c);
                return;
            }
            printf("%d ",pc[u]);
            dfs(pc[u],r,c-1);
        }
        else {
            for(auto v:a[u]) {
                if(vis[v]) continue;
                printf("%d ",v);
                dfs(v,r-1,c);
                return;
            }
            printf("%d ",p[u]);
            dfs(p[u],r,c);
        }
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) {
            a[i].clear();
            forb[i]=false;
            vis[i]=false;
        }
        for(int i=2;i<=n;i++) {
            scanf("%d",&p[i]);
            a[p[i]].push_back(i);
        }
        dfs_prec(1);
        if(k<=nd[1]) {
            int u=1;
            printf("%d\n",k-1);
            for(int i=1;i<=k;i++) {
                printf("%d ",u);
                u=pc[u];
            }
            printf("\n");
        }
        else {
            int c=nd[1];
            int r=k-c;
            int u=1;
            for(int i=1;i<=nd[1];i++) {
                forb[u]=true;
                ord[i]=u;
                u=pc[u];
            }
            printf("%d\n",2*r+c-1);
            printf("1 ");
            dfs(1,r,c-1);
            printf("\n");
        }
    }
    return 0;
}
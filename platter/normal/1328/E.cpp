#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
int p[200000];
int parent[200000][19];
bool visited[200000];
int depth[200000];

void maketree(int v) {
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++) {
        int next=adj[v][i];
        if (!visited[next]) {
            p[next]=v;
            parent[next][0]=v;
            depth[next]=depth[v]+1;
            maketree(next);
        }
    }
}

int getp(int v,int k) {
    for(int i=0;k;i++) {
        if (k&1) {
            v=parent[v][i];
        }
        k/=2;
    }
    return v;
}

int main(void) {
    memset(p,-1,sizeof(p));
    memset(parent,-1,sizeof(parent));
    int n,m;
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d\n",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maketree(0);
    for(int j=1;j<19;j++) {
        for(int i=0;i<n;i++) {
            if (parent[i][j-1]!=-1) {
                parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
    }
    for(int i=0;i<m;i++) {
        int k;
        scanf("%d ",&k);
        vector<int> v;
        int mxd=-1;
        int that=0;
        for(int j=0;j<k;j++) {
            int x;
            scanf("%d ",&x);
            x--;
            if (x!=0) {
                x=p[x];
            }
            v.push_back(x);
            if (depth[x]>mxd) {
                mxd=depth[x];
                that=x;
            }
        }
        bool flag=true;
        for(int j=0;j<k;j++) {
            if (getp(that,mxd-depth[v[j]])!=v[j]) {
                flag=false;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
}
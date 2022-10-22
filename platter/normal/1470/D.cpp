#include <bits/stdc++.h>
using namespace std;

bool visited[300000];
int arr[300000];
int n,m;
vector<int> adj[300000];

void dfs(int v,int c) {
    visited[v]=true;
    arr[v]=c;
    if (c==1) {
        for(int i=0;i<adj[v].size();i++) {
            int nt=adj[v][i];
            visited[nt]=true;
            arr[nt]=0;
        }
        for(int i=0;i<adj[v].size();i++) {
            dfs(adj[v][i],0);
        }
        return;
    }
    for(int i=0;i<adj[v].size();i++) {
        int nt=adj[v][i];
        if (!visited[nt])
            dfs(nt,1-c);
    }
}

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,1);
        bool flag=true;
        for(int i=0;i<n;i++) {
            if (!visited[i]) {
                flag=false;
                break;
            }
        }
        if (!flag) {
            printf("NO\n");
        }
        else {
            vector<int> ret;
            printf("YES\n");
            for(int i=0;i<n;i++) {
                if (arr[i]==1) {
                    ret.push_back(i);
                }
            }
            printf("%d\n",ret.size());
            for(int i=0;i<ret.size();i++) {
                printf("%d ",ret[i]+1);
            }
            printf("\n");
        }
        for(int i=0;i<n;i++) {
            adj[i].clear();
            visited[i]=false;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int dist[100000];
bool visited[100000];
int n,a,b,da,db;

int distanced(int x) {
    for(int i=0;i<n;i++) {
        visited[i]=false;
    }
    queue<int> q;
    q.push(x);
    visited[x]=true;
    dist[x]=0;
    int ret;
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        ret=now;
        for(int i=0;i<adj[now].size();i++) {
            int nt=adj[now][i];
            if (!visited[nt]) {
                q.push(nt);
                visited[nt]=true;
                dist[nt]=dist[now]+1;
            }
        }
    }
    return ret;
}

int getdia() {
    int now=distanced(0);
    return dist[distanced(now)];
}

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
        for(int i=0;i<n;i++) {
            adj[i].clear();
        }
        a--;
        b--;
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (db<=2*da) {
            printf("Alice\n");
            continue;
        }
        distanced(a);
        if (dist[b]<=da) {
            printf("Alice\n");
            continue;
        }
        if (getdia()>2*da) {
            printf("Bob\n");
        }
        else {
            printf("Alice\n");
        }
    }
}
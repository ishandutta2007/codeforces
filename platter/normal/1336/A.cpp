#include <bits/stdc++.h>
using namespace std;

int sz[200000];
int n,k;
int p[200000];
vector<int> adj[200000];
int depth[200000];
typedef pair<int,int> P;
priority_queue<P> pq;
bool used[200000];

void maketree(int v) {
    bool flag=false;
    sz[v]=1;
    for(int i=0;i<adj[v].size();i++) {
        int next=adj[v][i];
        if (depth[next]==-1) {
            flag=true;
            p[next]=v;
            depth[next]=depth[v]+1;
            maketree(next);
            sz[v]+=sz[next];
        }
    }
    if (!flag) {
        pq.push(P(depth[v],v));
    }
}

int main(void) {
    memset(p,-1,sizeof(p));
    memset(depth,-1,sizeof(depth));
    scanf("%d %d\n",&n,&k);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d\n",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0]=0;
    maketree(0);
    long long ret=0;
    for(int i=0;i<k;i++) {
        ret+=pq.top().first;
        int now=pq.top().second;
        if (p[now]!=-1&&(!used[p[now]])) {
            pq.push(P(depth[p[now]]-sz[p[now]]+1,p[now]));
            used[p[now]]=true;
        }
        pq.pop();
    }
    printf("%lld",ret);
}
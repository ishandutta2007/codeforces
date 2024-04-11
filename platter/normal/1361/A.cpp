#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
vector<P> edge;
P val[500001];
vector<int> adj[500001];
bool chk[500001];

int main(void) {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        edge.push_back(P(u,v));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        val[i].second=i;
        scanf("%d",&val[i].first);
    }
    for(int i=0;i<m;i++) {
        if (val[edge[i].first].first==val[edge[i].second].first) {
            printf("-1");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) {
        if (adj[i].size()<val[i].first-1) {
            printf("-1");
            return 0;
        }
        for(int j=0;j<adj[i].size();j++) {
            chk[val[adj[i][j]].first]=true;
        }
        for(int j=1;j<val[i].first;j++) {
            if (!chk[j]) {
                printf("-1");
                return 0;
            }
        }
        for(int j=0;j<adj[i].size();j++) {
            chk[val[adj[i][j]].first]=false;
        }
    }
    sort(val+1,val+n+1);
    for(int i=1;i<=n;i++) {
        printf("%d ",val[i].second);
    }
}
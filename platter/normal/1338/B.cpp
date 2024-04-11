#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100000];
vector<int> son[100000];
int root;
bool visited[100000];

void maketree(int v) {
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++) {
        int next=adj[v][i];
        if (!visited[next]) {
            son[v].push_back(next);
            maketree(next);
        }
    }
}

bool oe[100000];
bool save=true;

void check(int v) {
    if (son[v].empty()) {
        oe[v]=true;
        return;
    }
    for(int i=0;i<son[v].size();i++) {
        check(son[v][i]);
    }
    bool f=oe[son[v][0]];
    for(int i=0;i<son[v].size();i++) {
        int next=son[v][i];
        if (oe[next]!=f) {
            save=false;
            break;
        }
    }
    oe[v]=!f;
}

int main(void) {
    scanf("%d\n",&n);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d\n",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++) {
        if (adj[i].size()!=1) {
            root=i;
            break;
        }
    }
    maketree(root);
    int ret=n-1;
    for(int i=0;i<n;i++) {
        int cnt=0;
        for(int j=0;j<son[i].size();j++) {
            if (son[son[i][j]].size()==0) {
                cnt++;
            }
        }
        if (cnt>1) {
            ret-=cnt-1;
        }
    }
    check(root);
    printf("%d %d",save?1:3,ret);
}
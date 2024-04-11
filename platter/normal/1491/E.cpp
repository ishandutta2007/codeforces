#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
vector<P> adj[200000];
int n;
int fib[27];
int sz[200000];
vector<int> vtx;
int par[200000];

void dfs(int v,int prev) {
    int now=0;
    sz[v]=1;
    vtx.push_back(v);
    par[v]=prev;
    while (now<adj[v].size()) {
        int nt=adj[v][now].first;
        if (nt!=prev&&now!=0) {
            dfs(nt,v);
            sz[v]+=sz[nt];
        }
        now=adj[v][now].second;
    }
}

bool solve(int v,int ind) {
    if (ind<=3) {
        return true;
    }
    vtx.clear();
    vector<int> save(fib[ind]);
    vector<int> p(fib[ind]);
    dfs(v,-1);
    vector<int> vec=vtx;
    for(int i=0;i<fib[ind];i++) {
        save[i]=sz[vec[i]];
        p[i]=par[vec[i]];
    }
    bool flag=false;
    for(int i=1;i<vec.size();i++) {
        if (save[i]==fib[ind-1]||save[i]==fib[ind-2]) {
            int now=0;
            int pr=-1;
            while (adj[vec[i]][now].first!=p[i]) {
                pr=now;
                now=adj[vec[i]][now].second;
            }
            adj[vec[i]][pr].second=adj[vec[i]][now].second;
            int pr1=-1;
            int now1=0;
            while (adj[p[i]][now1].first!=vec[i]) {
                pr1=now1;
                now1=adj[p[i]][now1].second;
            }
            adj[p[i]][pr1].second=adj[p[i]][now1].second;
            int temp=p[i];
            if (solve(vec[i],ind-1-(save[i]==fib[ind-2]))&&solve(temp,ind-2+(save[i]==fib[ind-2]))) {
                flag=true;
            }
            adj[vec[i]][pr].second=now;
            adj[p[i]][pr1].second=now1;
            break;
        }
    }
    return flag;
}

int main(void) {
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=26;i++) {
        fib[i]=fib[i-1]+fib[i-2];
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        adj[i].push_back(P(i,1));
    }
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        v--;
        adj[u].push_back(P(v,adj[u].size()+1));
        adj[v].push_back(P(u,adj[v].size()+1));
    }
    int now=-1;
    for(int i=1;i<=26;i++) {
        if (fib[i]==n) {
            now=i;
            break;
        }
    }
    if (now==-1) {
        printf("NO");
        return 0;
    }
    printf("%s",solve(0,now)?"YES":"NO");
}
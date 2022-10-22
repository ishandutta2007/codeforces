#include <bits/stdc++.h>
using namespace std;

int n,m;
typedef pair<int,int> P;
vector<P> edge;
vector<int> tree[100000];

int p[100000];

int find(int a) {
    return p[a]<0?a:p[a]=find(p[a]);
}

void merge(int a,int b) {
    a=find(a);
    b=find(b);
    if (a==b) {
        return;
    }
    p[b]=a;
}

int f=0;
int ind[100000];
int sz[100000];
int par[100000][17];
int dep[100000];
int rev[100000];

void dfs(int v,int pr) {
    ind[v]=f++;
    rev[ind[v]]=v;
    sz[v]=1;
    par[v][0]=pr;
    for(int i=0;i<tree[v].size();i++) {
        int nt=tree[v][i];
        if (nt!=pr) {
            dep[nt]=dep[v]+1;
            dfs(nt,v);
            sz[v]+=sz[nt];
        }
    }
}

int pl[100001];
int ret[100000];

int getp(int v,int k) {
    for(int i=0;k;i++) {
        if (k&1) {
            v=par[v][i];
        }
        k/=2;
    }
    return v;
}

int main() {
    scanf("%d %d",&n,&m);
    memset(p,-1,sizeof(p));
    for(int i=0;i<m;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        v--;
        if (find(u)!=find(v)) {
            tree[u].push_back(v);
            tree[v].push_back(u);
            merge(u,v);
        }
        else {
            edge.push_back(P(u,v));
        }
    }
    dfs(0,-1);
    for(int j=1;j<17;j++) {
        for(int i=0;i<n;i++) {
            if (par[i][j-1]!=-1) {
                par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    }
    for(int i=0;i<edge.size();i++) {
        int one=edge[i].first;
        int two=edge[i].second;
        if (dep[one]>dep[two]) {
            swap(one,two);
        }
        if (getp(two,dep[two]-dep[one])==one) {
            int one0=getp(two,dep[two]-dep[one]-1);
            pl[ind[one0]]++;
            pl[ind[two]]--;
            pl[ind[two]+sz[two]]++;
            pl[ind[one0]+sz[one0]]--;
        }
        else {
            pl[0]++;
            pl[ind[one]]--;
            pl[ind[one]+sz[one]]++;
            pl[ind[two]]--;
            pl[ind[two]+sz[two]]++;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=pl[i];
        ret[rev[i]]=(sum==0?1:0);
    }
    for(int i=0;i<n;i++) {
        printf("%d",ret[i]);
    }
    return 0;
}
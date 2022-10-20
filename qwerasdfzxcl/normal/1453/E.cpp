#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool visited[200005];
int depth[200005];
int k;
vector<int> adj[200005];

int dfs(int s, int root){
    visited[s]=1;
    vector<int> ret;
    if (adj[s].size()==1 && s!=root) return s;
    for (auto &v:adj[s]){
        if (visited[v]) continue;
        depth[v]=depth[s]+1;
        int tmp=dfs(v, root);
        ret.push_back(tmp);
    }
    //printf("s, root: %d %d\n", s, root);
    //printf("ret: ");
    int re=987654321, re2, re3;
    for (int i=0;i<(int)ret.size();i++){
        if(re>depth[ret[i]]){
            re=depth[ret[i]];
            re2=ret[i];
            re3=i;
        }
        //printf("%d ", ret[i]);
    }
    //printf("\n");
    if (s!=root){
        ret[re3]=-1;
        for (int i=0;i<(int)ret.size();i++){
            if(ret[i]==-1) continue;
            k=max(k, depth[ret[i]]-depth[s]+1);
            //printf("%d: %d", ret[i], depth[ret[i]]-depth[s]+1);
        }
    }
    else{
        vector<int> rans;
        for (auto &v:ret) rans.push_back(depth[v]);
        sort(rans.begin(), rans.end());
        //for (auto &v: rans) printf("%d ", v);
        //printf("\n");
        if (rans.size()>1) k=max(k, rans[rans.size()-2]+1);
        k=max(k, rans[rans.size()-1]);
    }
    //printf("new k: %d\n", k);
    //printf("re2: %d\n", re2);
    return re2;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        k=1;
        int n;
        scanf("%d", &n);
        for (int i=0;i<=n;i++){
            visited[i]=0;
            depth[i]=0;
            adj[i].clear();
        }
        for (int i=0;i<n-1;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);
        printf("%d\n", k);
    }
    return 0;
}
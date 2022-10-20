#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fenwick{
    int n;
    ll tree[200002];

    void init(int _n){
        n = _n;
        fill(tree+1, tree+n+1, 0LL);
    }
    void upd(int x, ll val){
        while(x <= n){
            tree[x] += val;
            x += x&-x;
        }
    }

    ll sum(int x){
        ll ret = 0;
        while(x){
            ret += tree[x];
            x -= x&-x;
        }
        return ret;
    }
} tree;

struct Query{
    int u, v; ll cost;
    Query(){}
    Query(int u, int v, ll cost): u(u), v(v), cost(cost){}
};

int n, m;
int par[200002];
vector<int> child[200002];
int depth[200002], LCADB[200002][20];
ll DP[200002];
int sz[200002];
vector<Query> queryVec[200002];

int in[200002], top[200002], idx[200002];
ll DPSum[200002];

void makeTree(int x){
    sz[x] = 1;
    for(auto &y: child[x]){
        depth[y] = depth[x]+1;
        makeTree(y);
        sz[x] += sz[y];

        if(sz[y] > sz[child[x][0]]) swap(child[x][0], y);
    }
}

int in_cnt;
void dfs_hld(int x){
    in[x] = ++in_cnt;
    idx[in[x]] = x;
    for(auto y: child[x]){
        top[y] = (child[x][0] == y) ? top[x] : y;
        dfs_hld(y);
    }
}

int getLCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    for(int d=0; d<20; d++) if((depth[x]-depth[y])&(1<<d)) x = LCADB[x][d];
    if(x==y) return x;
    for(int d=19; d>=0; d--) if(LCADB[x][d] != LCADB[y][d]) x = LCADB[x][d], y = LCADB[y][d];
    return par[x];
}

int kth_parent(int x, int k){
    for(int d=0; d<20; d++){
        if((k>>d) & 1) x = LCADB[x][d];
    }
    return x;
}

ll pathQuery(int x, int topD){
    ll ret = 0;
    while(depth[x] >= topD){
        int tp = in[top[x]];
        int tStart = max(topD, depth[top[x]]) - depth[top[x]] + tp;
        int tEnd = depth[x] - depth[top[x]] + tp;
        ret += tree.sum(tEnd) - tree.sum(tStart-1);

        x = par[top[x]];
    }
    return ret;
}

void dfs(int x){
    ll dpSum = 0;
    for(auto y: child[x]){
        dfs(y);
        dpSum += DP[y];
    }

    DPSum[x] = DP[x] = dpSum;

    for(auto y: child[x]){
        tree.upd(in[y], dpSum - DP[y]);
    }
    for(auto query: queryVec[x]){ ///    .
        int tx = query.u, ty = query.v; ll tv = query.cost;
        assert(depth[tx] <= depth[ty]);

        ll val;
        if(tx == x){ ///    LCA 
            val = dpSum + tv;
            val -= DP[kth_parent(ty, depth[ty] - depth[tx] - 1)];

            val += pathQuery(ty, depth[x] + 2);
            val += DPSum[ty];
        }
        else{
            val = dpSum + tv;
            val -= DP[kth_parent(tx, depth[tx] - depth[x] - 1)];
            val -= DP[kth_parent(ty, depth[ty] - depth[x] - 1)];

            val += pathQuery(tx, depth[x] + 2);
            val += pathQuery(ty, depth[x] + 2);
            val += DPSum[tx];
            val += DPSum[ty];
        }
        DP[x] = max(DP[x], val);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=2; i<=n; i++){
        scanf("%d", &par[i]);
        LCADB[i][0] = par[i];
        child[par[i]].push_back(i);
    }
    makeTree(1);
    top[1] = 1;
    dfs_hld(1);
    for(int d=1; d<20; d++) for(int i=1; i<=n; i++) LCADB[i][d] = LCADB[LCADB[i][d-1]][d-1];

    for(int i=1; i<=m; i++){
        Query tmp;
        scanf("%d %d %lld", &tmp.u, &tmp.v, &tmp.cost);
        if(depth[tmp.u] > depth[tmp.v]) swap(tmp.u, tmp.v);
        int z = getLCA(tmp.u, tmp.v);
        queryVec[z].push_back(tmp);
    }

    tree.init(n);
    dfs(1);
    printf("%lld", DP[1]);
}
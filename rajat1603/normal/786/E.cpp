#include "bits/stdc++.h"
using namespace std;
const int N = 2e4 + 4;
const int M = 1e4 + 4;
const int LN = 15;
int n , m;
int a , b;
vector < pair < int , int > > v[N];
int dp[LN][N];
int depth[N];
int x[M] , y[M];
int name[LN][N];
int tot;
int who[N];
void dfs(int node , int parent , int level){
    dp[0][node] = parent;
    depth[node] = level;
    for(auto it : v[node]){
        int next = it.first;
        if(next != parent){
            who[next] = it.second;
            dfs(next , node , level + 1);
        }
    }
}
int lca(int a , int b){
    int dif = depth[a] - depth[b];
    if(dif < 0){
        dif = -dif;
        swap(a , b);
    }
    for(int i = 0 ; i < LN ; ++i){
        if((dif >> i) & 1){
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
}
namespace flow{
    const int V = N * LN + M;
    const int E = 2 * (LN + LN + 2) * (N + M + 2);
    const int inf = 1e9 + 9;
    vector < int > v[V];
    int a[E];
    int b[E];
    int c[E];
    int cur;
    int s , t;
    void init(){
        s = 0;
        t = tot + 1;
        cur = 0;
    }
    void addedge(int x , int y , int z){
        a[cur] = x;
        b[cur] = y;
        c[cur] = z;
        v[x].emplace_back(cur);
        ++cur;
        a[cur] = y;
        b[cur] = x;
        c[cur] = 0;
        v[y].emplace_back(cur);
        ++cur;
    }
    int dist[V];
    int que[V];
    int qs , qe;
    bool bfs(){
        qs = 0;
        qe = 0;
        for(int i = s ; i <= t ; ++i){
            dist[i] = V;
        }
        que[qe++] = s;
        dist[s] = 0;
        while(qs < qe){
            int node = que[qs++];
            for(int edge : v[node]){
                if(c[edge]){
                    int next = b[edge];
                    if(dist[next] > dist[node] + 1){
                        dist[next] = dist[node] + 1;
                        que[qe++] = next;
                    }
                }
            }
        }
        return dist[t] < V;
    }
    int res;
    int visited[V];
    int timer;
    int dfs(int node , int val){
        if(node == t){
            return val;
        }
        if(visited[node] == timer){
            return 0;
        }
        visited[node] = timer;
        int tot = 0;
        for(int edge : v[node]){
            if(c[edge]){
                int next = b[edge];
                if(dist[next] == dist[node] + 1){
                    int tmp = dfs(next , min(val - tot , c[edge]));
                    tmp = min(tmp , val - tot);
                    if(tmp){
                        c[edge] -= tmp;
                        c[edge ^ 1] += tmp;
                        tot += tmp;
                    }
                    if(tot == val){
                        break;
                    }
                }
            }
        }
        return tot;
    }
    void getflow(){
        res = 0;
        while(bfs()){
            ++timer;
            res += dfs(s , inf);
        }
    }
    bool vis[V];
    void dfs2(int node){
        if(vis[node]){
            return;
        }
        vis[node] = 1;
        for(int edge : v[node]){
            if(c[edge]){
                dfs2(b[edge]);
            }
        }
    }
    vector < int > lft , rgt;
    void getvertexcover(){
        memset(vis , 0 , sizeof(vis));
        dfs2(s);
        lft.clear();
        rgt.clear();
        for(int i = 1 ; i <= m ; ++i){
            if(!vis[i]){
                lft.emplace_back(i);
            }
        }
        for(int i = 1 ; i <= n ; ++i){
            if(dp[0][i]){
                int node = name[0][i];
                if(vis[node]){
                    rgt.emplace_back(i);
                }
            }
        }
    }
}
void solve(int idx , int x , int y){
    int lc = lca(x , y);
    int dif = depth[x] - depth[lc];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            flow :: addedge(idx , name[i][x] , 1);
            x = dp[i][x];
        }
    }
    dif = depth[y] - depth[lc];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            flow :: addedge(idx , name[i][y] , 1);
            y = dp[i][y];
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(make_pair(b , i));
        v[b].emplace_back(make_pair(a , i));
    }
    dfs(1 , 0 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    tot = m;
    for(int i = 0 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(dp[i][j]){
                name[i][j] = ++tot;
            }
        }
    }
    flow :: init();
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(dp[i][j]){
                flow :: addedge(name[i][j] , name[i - 1][j] , flow :: inf);
                flow :: addedge(name[i][j] , name[i - 1][dp[i - 1][j]] , flow :: inf);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(dp[0][i]){
            flow :: addedge(name[0][i] , flow :: t , 1);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        flow :: addedge(flow :: s , i , 1);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , x + i , y + i);
        solve(i , x[i] , y[i]);
    }
    flow :: getflow();
    printf("%d\n" , flow :: res);
    flow :: getvertexcover();
    printf("%d" , int(flow :: lft.size()));
    for(int x : flow :: lft){
        printf(" %d" , x);
    }
    printf("\n");
    printf("%d" , int(flow :: rgt.size()));
    for(int x : flow :: rgt){
        printf(" %d" , who[x]);
    }
    printf("\n");
}
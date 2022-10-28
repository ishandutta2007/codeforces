#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int LN = 19;
int n , m , q;
int a[N] , b[N];
vector < int > v[N];
int tin[N];
int anc[N];
int rek[N];
int timer;
void dfs(int node , int last){
    tin[node] = anc[node] = ++timer;
    for(int edge : v[node]){
        if(edge != last){
            int next = a[edge] ^ b[edge] ^ node;
            if(tin[next]){
                anc[node] = min(anc[node] , tin[next]);
            }
            else{
                dfs(next , edge);
                if(anc[next] > tin[node]){
                    rek[edge] = 1;
                }
                anc[node] = min(anc[node] , anc[next]);
            }
        }
    }
}
int parent[N];
int comp[N];
int num;
vector < int > g[N];
int r;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
int tout[N];
int dp[LN][N];
int depth[N];
void dfs2(int node , int parent){
    tin[node] = ++timer;
    depth[node] = depth[parent] + 1;
    dp[0][node] = parent;
    for(int next : g[node]){
        if(next != parent){
            dfs2(next , node);
        }
    }
    tout[node] = timer;
}
int qn , qm;
int arr[N];
int qa[N + N] , qb[N + N];
int transform(int x){
    x = (x + r) % n;
    if(x == 0){
        x = n;
    }
    return x;
}
int tmp[N];
int siz;
int when[N];
int lca(int a , int b){
    int dif = depth[a] - depth[b];
    if(dif < 0){
        swap(a , b);
        dif *= -1;
    }
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
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
    return a;
}
bool isanc(int top , int bot){
    return (tin[top] <= tin[bot]) && (tout[bot] <= tout[top]);
}
int qtin[N];
vector < int > qv[N];
int qanc[N];
int qtimer;
int rip[N + N];
int stk[N];
int sz;
void dfs3(int node , int last){
    qtin[node] = qanc[node] = ++qtimer;
    for(int edge : qv[node]){
        if(edge != last){
            int next = qa[edge] ^ qb[edge] ^ node;
            if(qtin[next]){
                qanc[node] = min(qanc[node] , qtin[next]);
            }
            else{
                dfs3(next , edge);
                qanc[node] = min(qanc[node] , qanc[next]);
                if(qanc[next] > qtin[node]){
                    rip[edge] = 1;
                }
            }
        }
    }
}
void solve(int query){
    ++timer;
    siz = 0;
    for(int i = 1 ; i <= qn ; ++i){
        if(when[arr[i]] < timer){
            when[arr[i]] = timer;
            tmp[++siz] = arr[i];
        }
    }
    for(int i = 1 ; i <= qm ; ++i){
        if(when[qa[i]] < timer){
            when[qa[i]] = timer;
            tmp[++siz] = qa[i];
        }
        if(when[qb[i]] < timer){
            when[qb[i]] = timer;
            tmp[++siz] = qb[i];
        }
    }
    sort(tmp + 1 , tmp + 1 + siz , [](int a , int b){
        return tin[a] < tin[b];
    });
    int tmpsiz = siz;
    for(int i = 1 ; i < tmpsiz ; ++i){
        int node = lca(tmp[i] , tmp[i + 1]);
        if(when[node] < timer){
            when[node] = timer;
            tmp[++siz] = node;
        }
    }
    sort(tmp + 1 , tmp + 1 + siz , [](int a , int b){
        return tin[a] < tin[b];
    });
    sz = 0;
    stk[++sz] = tmp[1];
    for(int i = 2 ; i <= siz ; ++i){
        while(sz && !isanc(stk[sz] , tmp[i])){
            --sz;
        }
        if(sz){
            ++qm;
            qa[qm] = stk[sz];
            qb[qm] = tmp[i];
        }
        stk[++sz] = tmp[i];
    }
    for(int i = 1 ; i <= siz ; ++i){
        qv[tmp[i]].clear();
        qtin[tmp[i]] = 0;
        qanc[tmp[i]] = 0;
    }
    qtimer = 0;
    for(int i = 1 ; i <= qm ; ++i){
        qv[qa[i]].emplace_back(i);
        qv[qb[i]].emplace_back(i);
        rip[i] = 0;
    }
    for(int i = 1 ; i <= siz ; ++i){
        int node = tmp[i];
        if(!qtin[node]){
            dfs3(node , 0);
        }
    }
    for(int i = 1 ; i <= siz ; ++i){
        parent[tmp[i]] = tmp[i];
    }
    for(int i = 1 ; i <= qm ; ++i){
        if(!rip[i]){
            parent[find(qa[i])] = find(qb[i]);
        }
    }
    int rip = 0;
    for(int i = 2 ; i <= qn ; ++i){
        if(find(arr[i]) != find(arr[1])){
            rip = 1;
            break;
        }
    }
    if(rip){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        r += query;
        r %= n;
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        v[a[i]].emplace_back(i);
        v[b[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!tin[i]){
            dfs(i , 0);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    for(int i = 1 ; i <= m ; ++i){
        if(!rek[i]){
            parent[find(a[i])] = find(b[i]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) == i){
            comp[i] = ++num;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) != i){
            comp[i] = comp[find(i)];
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(rek[i]){
            g[comp[a[i]]].emplace_back(comp[b[i]]);
            g[comp[b[i]]].emplace_back(comp[a[i]]);
        }
    }
    for(int i = 1 ; i <= num ; ++i){
        tin[i] = 0;
    }
    timer = 0;
    for(int i = 1 ; i <= num ; ++i){
        if(!tin[i]){
            dfs2(i , 0);
        }
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= num ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    timer = 0;
    r = 0;
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , &qn , &qm);
        for(int i = 1 ; i <= qn ; ++i){
            scanf("%d" , arr + i);
            arr[i] = transform(arr[i]);
            arr[i] = comp[arr[i]];
        }
        for(int i = 1 ; i <= qm ; ++i){
            scanf("%d %d" , qa + i , qb + i);
            qa[i] = transform(qa[i]);
            qb[i] = transform(qb[i]);
            qa[i] = comp[qa[i]];
            qb[i] = comp[qb[i]];
        }
        solve(i);
    }
}
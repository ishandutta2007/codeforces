#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n , m;
vector < int > v[N];
int a , b;
int subtree[N];
long long sum[N];
int depth[N];
int dp[LN][N];
int upcnt[N];
long long upsum[N];
void dfs(int node , int baap){
    dp[0][node] = baap;
    subtree[node] = 1;
    sum[node] = 0;
    depth[node] = depth[baap] + 1;
    for(int next : v[node]){
        if(next != baap){
            dfs(next , node);
            subtree[node] += subtree[next];
            sum[node] += sum[next] + subtree[next];
        }
    }
}
int dfs2(int node , int baap){
    upsum[node] = upsum[baap] + upcnt[baap];
    upsum[node] += sum[baap] - sum[node] - subtree[node] + subtree[baap] - subtree[node] - 1;
    upcnt[node] = upcnt[baap] + 1;
    upcnt[node] += subtree[baap] - subtree[node] - 1;
    for(int next : v[node]){
        if(next != baap){
            dfs2(next , node);
        }
    }
}
int lca(int a , int b){
    if(depth[a] > depth[b]){
        swap(a , b);
    }
    int dif = depth[b] - depth[a];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            b = dp[i][b];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        b = dp[0][b];
    }
    return b;
}
int get(int node , int up){
    for(int i = 0 ; i < LN ; ++i){
        if(up & (1 << i)){
            node = dp[i][node];
        }
    }
    return node;
}
int dist(int a , int b){
    return depth[a] + depth[b] - (depth[lca(a , b)] << 1);
}
void solve(int upar , int neeche){
    int nd = get(neeche , depth[neeche] - depth[upar] - 1);
    long long x1 = sum[neeche];
    long long x2 = upsum[upar] + sum[upar] - sum[nd] - subtree[nd];
    long long c1 = subtree[neeche];
    long long c2 = upcnt[upar] + subtree[upar] - subtree[nd] - 1;
    long long tot = x1 * c2 + x2 * c1 + c1 * c2 * dist(upar , neeche);
    printf("%.9lf\n" , 1.0 + (1.0 * tot / (1.0 * c1 * c2)));
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    depth[0] = 0;
    dfs(1 , 0);
    upsum[1] = 0;
    upcnt[1] = 1;
    for(int next : v[1]){
        dfs2(next , 1);
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(m--){
        scanf("%d %d" , &a , &b);
        int lc = lca(a , b);
        if(lc == a){
            solve(lc , b);
        }
        else if(lc == b){
            solve(lc , a);
        }
        else{
            long long x1 = sum[a];
            long long x2 = sum[b];
            long long c1 = subtree[a];
            long long c2 = subtree[b];
            long long tot = x1 * c2 + x2 * c1 + c1 * c2 * dist(a , b);
            printf("%.9lf\n" , 1.0 + (1.0 * tot / (1.0 * c1 * c2)));
        }
    }
}
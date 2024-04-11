#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const int LN = 17;
const int K = 1e6 + 6;
int n;
vector < pair < int , int > > v[N];
int dp[LN][N];
int depth[N];
int a , b , c;
int k;
int last , cur;
int cntu[N];
int cntd[N];
int pow2[K];
int ans = 0;
void dfs(int node , int parent){
    dp[0][node] = parent;
    for(auto it : v[node]){
        if(it.first != parent){
            depth[it.first] = depth[node] + 1;
            dfs(it.first , node);
        }
    }
}
void pre(){
    pow2[0] = 1;
    for(int i = 1 ; i < K ; ++i){
        pow2[i] = pow2[i - 1] + pow2[i - 1];
        if(pow2[i] >= mod){
            pow2[i] -= mod;
        }
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}
int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
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
//0 for bidir , 1 for up to down , 2 for down to up
void solve(int node , int parent){
    for(auto it : v[node]){
        if(it.first != parent){
            int next = it.first;
            int type = it.second;
            solve(next , node);
            if(type){
                ans += pow2[(type & 1) ? cntu[next] : cntd[next]] - 1;
                if(ans >= mod){
                    ans -= mod;
                }
            }
            cntu[node] += cntu[next];
            cntd[node] += cntd[next];
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        v[a].emplace_back(make_pair(b , c));
        v[b].emplace_back(make_pair(a , c + c));
    }
    depth[1] = 0;
    dfs(1 , 0);
    pre();
    last = 1;
    scanf("%d" , &k);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , &cur);
        int lc = lca(last , cur);
        ++cntu[last];
        ++cntd[cur];
        --cntu[lc];
        --cntd[lc];
        last = cur;
    }
    solve(1 , 0);
    printf("%d\n" , ans);
}
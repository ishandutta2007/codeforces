#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n , m , q;
vector < int > adj[N];
int dp[LN][N];
int inp1 , inp2;
vector < int > vs[N];
int u , v , a;
int depth[N];
struct node{
    int sum;
    node* left;
    node* right;
    node(int _sum = 0 , node* _left = NULL , node* _right = NULL){
        sum = _sum;
        left = _left;
        right = _right;
    }
    node* insert(int l , int r , int val);
};
node* root[N];
node* dummy;
node* node::insert(int l , int r , int val){
    if(l == r){
        return new node(sum + 1 , dummy , dummy);
    }
    int mid = l + r >> 1;
    if(val <= mid){
        return new node(sum + 1 , left -> insert(l , mid , val) , right);
    }
    return new node(sum + 1 , left , right -> insert(mid + 1 , r , val));
}
void dfs(int node , int baap){
    dp[0][node] = baap;
    depth[node] = depth[baap] + 1;
    root[node] = root[baap];
    for(int x : vs[node]){
        root[node] = root[node] -> insert(1 , m , x);
    }
    for(int next : adj[node]){
        if(next != baap){
            dfs(next , node);
        }
    }
}
int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    for(int i = 0 ; i < LN ; ++i){
        if((dif >> i) & 1){
            a = dp[i][a];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = LN - 1 ; i >= 0 ; --i){
        if(dp[i][a] != dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}
void print(int l , int r , node* a , node* b , node* c , node* d){
    int cnt = a -> sum + b -> sum - c -> sum - d -> sum;
    if(!cnt){
        return;
    }
    if(l == r){
        printf("%d " , l);
        return;
    }
    int mid = l + r >> 1;
    print(l , mid , a -> left , b -> left , c -> left , d -> left);
    print(mid + 1 , r , a -> right , b -> right , c -> right , d -> right);
}
void solve(int u , int v , int k){
    node* a = root[u];
    node* b = root[v];
    int lc = lca(u , v);
    node* c = root[lc];
    node* d = root[dp[0][lc]];
    k = min(k , a -> sum + b -> sum - c -> sum - d -> sum);
    int l = 1;
    int r = m;
    printf("%d " , k);
    while(l < r){
        int cnt = a -> left -> sum + b -> left -> sum - c -> left -> sum - d -> left -> sum;
        int mid = l + r >> 1;
        if(cnt >= k){
            r = mid;
            a = a -> left;
            b = b -> left;
            c = c -> left;
            d = d -> left;
        }
        else{
            print(l , mid , a -> left , b -> left , c -> left , d -> left);
            l = mid + 1;
            a = a -> right;
            b = b -> right;
            c = c -> right;
            d = d -> right;
            k -= cnt;
        }
    }
    if(k){
        print(l , l , a , b , c , d);
    }
    printf("\n");
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &inp1 , &inp2);
        adj[inp1].emplace_back(inp2);
        adj[inp2].emplace_back(inp1);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &inp1);
        vs[inp1].emplace_back(i);
    }
    dummy = new node();
    dummy -> left = dummy -> right = dummy;
    root[0] = dummy;
    depth[0] = 0;
    dfs(1 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(q--){
        scanf("%d %d %d" , &u , &v , &a);
        solve(u , v , a);
    }
}
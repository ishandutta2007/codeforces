#include "bits/stdc++.h"
using namespace std;
struct edge{
    int a , b;
    int dis;
    int cst;
    int idx;
};
const int N = 2e5 + 5;
const int LN = 18;
int n , m;
edge arr[N];
int s;
vector < int > v[N];
long long k;
int who;
int parent[N];
long long sum;
long long mn;
bool ontree[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
bool join(int a , int b){
    if(find(a) == find(b)){
        return 0;
    }
    parent[find(b)] = find(a);
    return 1;
}
int dp[LN][N];
pair < int , int > mx[LN][N];
int depth[N];
void dfs(int node , int parent){
    for(int e : v[node]){
        int next = arr[e].a ^ arr[e].b ^ node;
        if(next != parent){
            dp[0][next] = node;
            mx[0][next] = {arr[e].dis , e};
            depth[next] = depth[node] + 1;
            dfs(next , node);
        }
    }
}
pair < int , int > getmx(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    pair < int , int > res = {0 , 0};
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            res = max(res , mx[i][a]);
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                res = max(res , mx[i][a]);
                res = max(res , mx[i][b]);
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        res = max(res , mx[0][a]);
        res = max(res , mx[0][b]);
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &arr[i].dis);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &arr[i].cst);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &arr[i].a , &arr[i].b);
        arr[i].idx = i;
    }
    scanf("%d" , &s);
    sort(arr + 1 , arr + 1 + m , [](edge x , edge y){
        return x.dis < y.dis;
    });
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    sum = 0;
    mn = 2e9;
    for(int i = 1 ; i <= m ; ++i){
        if(join(arr[i].a , arr[i].b)){
            sum += arr[i].dis;
            v[arr[i].a].emplace_back(i);
            v[arr[i].b].emplace_back(i);
            if(arr[i].cst < mn){
                mn = arr[i].cst;
                who = i;
            }
            ontree[i] = 1;
        }
    }
    k = sum - (s / mn);
    dfs(1 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j] , mx[i - 1][dp[i - 1][j]]);
        }
    }
    int rem = -1;
    for(int i = 1 ; i <= m ; ++i){
        if(!ontree[i]){
            long long cst = sum;
            auto it = getmx(arr[i].a , arr[i].b);
            cst -= it.first;
            cst += arr[i].dis;
            cst -= s / arr[i].cst;
            if(cst < k){
                k = cst;
                who = i;
                rem = it.second;
            }
        }
    }
    printf("%lld\n" , k);
    if(!ontree[who]){
        ontree[who] = 1;
        ontree[rem] = 0;
    }
    for(int i = 1 ; i <= m ; ++i){
        if(ontree[i]){
            printf("%d %d\n" , arr[i].idx , arr[i].dis - ((who == i) ? (s / arr[i].cst) : 0));
        }
    }
}
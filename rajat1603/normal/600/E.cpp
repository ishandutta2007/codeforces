#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 330;
int n;
int arr[N];
vector < int > v[N];
int start[N];
int finish[N];
int flat[N];
int timer = 0;
int a , b;
void dfs(int node , int parent){
    start[node] = ++timer;
    flat[timer] = arr[node];
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
        }
    }
    finish[node] = timer;
}
struct query{
    int l;
    int r;
    int idx;
    query(int _l  = 0 , int _r = 0 , int _i = 0){
        l = _l;
        r = _r;
        idx = _i;
    }
    bool operator < (const query &b) const {
        if(int(l / SQN) == int(b.l / SQN)){
            return r < b.r;
        }
        return l < b.l;
    }
};
query Q[N];
long long ans[N];
int freq[N];
long long sum[N];
int cur = 0;
int curl = 1;
int curr = 0;
void add(int idx){
    int val = flat[idx];
    sum[freq[val]] -= val;
    ++freq[val];
    sum[freq[val]] += val;
    cur = max(cur , freq[val]);
}
void remove(int idx){
    int val = flat[idx];
    sum[freq[val]] -= val;
    --freq[val];
    sum[freq[val]] += val;
    while(!sum[cur]){
        --cur;
    }
}
void solve(){
    memset(freq , 0 , sizeof(freq));
    memset(sum , 0 , sizeof(sum));
    sort(Q + 1 , Q + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        while(curr < Q[i].r){
            add(++curr);
        }
        while(curl > Q[i].l){
            add(--curl);
        }
        while(curr > Q[i].r){
            remove(curr--);
        }
        while(curl < Q[i].l){
            remove(curl++);
        }
        ans[Q[i].idx] = sum[cur];
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        v[i].clear();
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , -1);
    for(int i = 1 ; i <= n ; ++i){
        Q[i] = query(start[i] , finish[i] , i);
    }
    solve();
    for(int i = 1 ; i <= n ; ++i){
        printf("%lld " , ans[i]);
    }
}
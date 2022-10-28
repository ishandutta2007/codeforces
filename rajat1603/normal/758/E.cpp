#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N] , b[N] , w[N] , s[N];
int par[N];
vector < int > v[N];
long long sub[N];
vector < pair < int , int > > pq[N];
int tin[N];
int tout[N];
long long bit[N];
int cur;
void update(int idx , int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}
long long query(int idx){
    long long res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
void pre(int node){
    sub[node] = 0;
    tin[node] = ++cur;
    for(int edge : v[node]){
        int next = b[edge];
        pre(next);
        update(tin[node] , w[edge]);
        sub[node] += sub[next] + w[edge];
    }
    tout[node] = cur;
}
long long subarray(int node){
    return query(tout[node]) - query(tin[node] - 1);
}
long long dfs(int node , long long subb){
    long long res = 0;
    for(int edge : v[node]){
        int next = b[edge];
        long long old = sub[next] - s[edge];
        long long val = dfs(next , max(0LL , sub[next] - s[edge]));
        if(val < old){
            printf("-1\n");
            exit(0);
        }
        res += val;
        subb -= val;
    }
    int child = -1;
    for(int edge : v[node]){
        int next = b[edge];
        if(child == -1 || pq[next].size() > pq[child].size()){
            child = next;
        }
    }
    if(child != -1){
        pq[node].swap(pq[child]);
    }
    for(int edge : v[node]){
        int next = b[edge];
        if(child != next){
            pq[node].insert(pq[node].end() , pq[next].begin() , pq[next].end());
            pq[next].clear();
            pq[next].shrink_to_fit();
        }
    }
    for(int edge : v[node]){
        int next = b[edge];
        if(v[next].empty()){
            pq[node].emplace_back(make_pair(min(s[edge] , w[edge] - 1) , edge));
        }
    }
    while(subb > 0){
        if(pq[node].empty()){
            printf("-1\n");
            exit(0);
        }
        auto it = pq[node].back();
        pq[node].pop_back();
        if(it.first > subb){
            it.first -= subb;
            s[it.second] -= subb;
            w[it.second] -= subb;
            update(tin[a[it.second]] , -subb);
            res += subb;
            subb = 0;
            pq[node].emplace_back(it);
        }
        else{
            subb -= it.first;
            s[it.second] -= it.first;
            w[it.second] -= it.first;
            res += it.first; 
            update(tin[a[it.second]] , -it.first);
            if(a[it.second] != node){
                pq[node].emplace_back(make_pair(min(s[par[a[it.second]]] - subarray(a[it.second]) , w[par[a[it.second]]] - 1LL) , par[a[it.second]]));
            }
        }
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %d %d" , a + i , b + i , w + i , s + i);
        v[a[i]].emplace_back(i);
        par[b[i]] = i;
    }
    pre(1);
    dfs(1 , 0);
    printf("%d\n" , n);
    for(int i = 1 ; i < n ; ++i){
        printf("%d %d %d %d\n" , a[i] , b[i] , w[i] , s[i]);
    }
}
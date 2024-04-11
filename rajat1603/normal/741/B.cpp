#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , m , w;
int arr[N];
int cst[N];
int a , b;
int parent[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
vector < pair < int , int > > v[N];
int sumw[N];
int sumb[N];
long long dp[N][N];
long long solve(int pos , int wleft){
    if(pos > n){
        return 0;
    }
    if(dp[pos][wleft] != -1){
        return dp[pos][wleft];
    }
    long long res = 0;
    res = max(res , solve(pos + 1 , wleft));
    for(auto it : v[pos]){
        if(it.first <= wleft){
            res = max(res , solve(pos + 1 , wleft - it.first) + it.second);
        }
    }
    return dp[pos][wleft] = res;
}
int main(){
    scanf("%d %d %d" , &n , &m , &w);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , cst + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        parent[find(a)] = find(b);
    }
    for(int i = 1 ; i <= n ; ++i){
        sumw[find(i)] += arr[i];
        sumb[find(i)] += cst[i];
        v[find(i)].push_back(make_pair(arr[i] , cst[i]));
    }
    for(int i = 1 ; i <= n ; ++i){
        if(sumb[i]){
            v[i].push_back(make_pair(sumw[i] , sumb[i]));
        }
    }
    memset(dp , -1 , sizeof(dp));
    printf("%lld\n" , solve(1 , w));
}
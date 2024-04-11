#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SZ = 8e5 + 5;
int n;
char arr[SZ];
vector < int > v[2][SZ];
int child[SZ][26];
int cur = 1;
long long ans = 0;
int match[N];
void insert(int idx){
    int node = 1;
    int i = 0;
    while(arr[i]){
        int nxt = arr[i] - 'a';
        if(!child[node][nxt]){
            child[node][nxt] = ++cur;
        }
        node = child[node][nxt];
        ++i;
    }
    v[(idx - 1) / n][node].emplace_back(idx);
}
void dfs(int node , int depth){
    for(int i = 0 ; i < 26 ; ++i){
        if(child[node][i]){
            dfs(child[node][i] , depth + 1);
            for(auto it : v[0][child[node][i]]){
                v[0][node].emplace_back(it);
            }
            for(auto it : v[1][child[node][i]]){
                v[1][node].emplace_back(it);
            }
            v[0][child[node][i]].clear();
            v[1][child[node][i]].clear();
        }
    }
    while(!v[0][node].empty() && !v[1][node].empty()){
        match[v[0][node].back()] = v[1][node].back();
        v[0][node].pop_back();
        v[1][node].pop_back();
        ans += depth;
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n + n ; ++i){
        scanf("%s" , arr);
        insert(i);
    }
    dfs(1 , 0);
    printf("%lld\n" , ans);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d %d\n" , i , match[i] - n);
    }
}
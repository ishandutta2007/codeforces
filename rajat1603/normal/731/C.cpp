#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m , k;
int arr[N];
int a , b;
vector < int > v[N];
int freq[N];
int mx;
int sz;
int visited[N];
int ans;
void dfs1(int node){
    if(visited[node]){
        return;
    }
    visited[node] = 1;
    ++sz;
    ++freq[arr[node]];
    mx = max(mx , freq[arr[node]]);
    for(int next : v[node]){
        dfs1(next);
    }
}
void dfs2(int node){
    if(visited[node] > 1){
        return;
    }
    visited[node] = 2;
    freq[arr[node]] = 0;
    for(int next : v[node]){
        dfs2(next);
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    while(m--){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            sz = 0;
            mx = 0;
            dfs1(i);
            dfs2(i);
            ans += sz - mx;
        }
    }
    printf("%d\n" , ans);
}
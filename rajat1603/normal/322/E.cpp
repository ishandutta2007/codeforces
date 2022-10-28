#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
vector < int > v[N];
int a , b;
bool used[N];
int ans[N];
int subtree[N];
void dfs(int node , int parent){
    subtree[node] = 1;
    for(int next : v[node]){
        if(next != parent && !used[next]){
            dfs(next , node);
            subtree[node] += subtree[next];
        }
    }
}
int find(int node , int parent , int val){
    for(int next : v[node]){
        if(next != parent && !used[next]){
            if(subtree[next] >= val){
                return find(next , node , val);
            }
        }
    }
    return node;
}
void solve(int node , int depth){
    dfs(node , 0);
    int cur = find(node , 0 , subtree[node] >> 1);
    ans[cur] = depth;
    used[cur] = 1;
    for(int next : v[cur]){
        if(!used[next]){
            solve(next , depth + 1);
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    solve(1 , 0);
    for(int i = 1 ; i <= n ; ++i){
        printf("%c " , ans[i] + 'A');
    }
}
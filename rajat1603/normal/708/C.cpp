#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int a , b;
vector < int > v[N];
int ans[N];
int subtree[N];
int mx , smx;
void dfs(int node , int parent){
    subtree[node] = 1;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            subtree[node] += subtree[next];
        }
    }
}
int find(int node , int parent){
    for(int next : v[node]){
        if(next != parent){
            if(subtree[next] > (n >> 1)){
                return find(next , node);
            }
        }
    }
    return node;
}
void dfs(int node , int parent , int loll){
    if(n - subtree[node] > (n >> 1)){
        ans[node] = 0;
        int sz = n - subtree[node];
        if(mx == loll){
            sz -= max(smx , mx - subtree[node]);
        }
        else{
            sz -= mx;
        }
        if(sz <= (n >> 1)){
            ans[node] = 1;
        }
    }
    else{
        ans[node] = 1;
    }
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node , max(loll , subtree[next]));
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
    memset(ans , 0 , sizeof(ans));
    dfs(1 , 0);
    int cent = find(1 , 0);
    dfs(cent , 0);
    mx = 0;
    smx = 0;
    for(int next : v[cent]){
        if(subtree[next] > mx){
            smx = mx;
            mx = subtree[next];
        }
        else if(subtree[next] > smx){
            smx = subtree[next];
        }
    }
    dfs(cent , 0 , 0);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , ans[i] , " \n"[i == n]);
    }
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 18;
int subtree[N];
int dist[N];
int exist[N];
int arr[N];
int n;
int ans = N * 20;
void dfs(int node){
    subtree[node] = exist[node];
    dist[node] = 0;
    for(int i = node + node ; i <= min(N - 1 , node + node + 1); ++i){
        dfs(i);
        subtree[node] += subtree[i];
        dist[node] += dist[i];
        dist[node] += subtree[i];
    }
}
int get(int node , int last , int lvl){
    if(node < 1){
        return 0;
    }
    if(last & 1){
        if(subtree[last] == n){
            return 0;
        }
        else{
            return 9999999;
        }
    }
    int add = dist[node] - dist[last] - subtree[last] + (subtree[node] - subtree[last]) * lvl;
    return add + get(node >> 1 , node , lvl + 1);
}
int main(){
    memset(exist , 0 , sizeof(exist));
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        ++exist[arr[i]];
    }
    dfs(1);
    int ans = INT_MAX;
    for(int i = 1 ; i < N ; ++i){
        if(i & 1){
            if(subtree[i] == n){
                ans = min(ans , dist[i]);
            }
        }
        else{
            ans = min(ans , dist[i] + get(i >> 1 , i , 1));
        }
    }
    cout << ans;
}
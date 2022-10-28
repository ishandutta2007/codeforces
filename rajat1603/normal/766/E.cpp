#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 20;
int n;
int arr[N];
int a , b;
vector < int > v[N];
int val[N][LN];
int subtree[N];
long long ans;
void dfs(int node , int parent){
    ans += arr[node];
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            for(int j = 0 ; j < LN ; ++j){
                bool bit = (arr[node] >> j) & 1;
                if(bit){
                    ans += 1LL * (subtree[next] - val[next][j]) * (1LL << j);
                }
                else{
                    ans += 1LL * val[next][j] * (1LL << j);
                }
                ans += 1LL * (subtree[next] - val[next][j]) * val[node][j] * (1LL << j);
                ans += 1LL * val[next][j] * (subtree[node] - val[node][j]) * (1LL << j);
            }
            subtree[node] += subtree[next];
            for(int j = 0 ; j < LN ; ++j){
                bool bit = (arr[node] >> j) & 1;
                if(bit){
                    val[node][j] += subtree[next] - val[next][j];
                }
                else{
                    val[node][j] += val[next][j];
                }
            }
        }
    }
    ++subtree[node];
    for(int j = 0 ; j < LN ; ++j){
        bool bit = (arr[node] >> j) & 1;
        if(bit){
            ++val[node][j];
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    ans = 0;
    dfs(1 , 0);
    printf("%lld\n" , ans);
}
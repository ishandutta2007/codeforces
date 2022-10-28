#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , k;
int arr[N];
int a , b;
vector < int > v[N];
int spe[N];
bool visited[N];
vector < int > comp;
int sz;
long long ans;
void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = 1;
    ++sz;
    for(int next : v[node]){
        dfs(next);
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , arr + i);
        spe[arr[i]] = 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    comp.clear();
    for(int i = 1 ; i <= k ; ++i){
        sz = 0;
        dfs(arr[i]);
        comp.emplace_back(sz);
    }
    sort(comp.begin() , comp.end());
    reverse(comp.begin() , comp.end());
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            sz = 0;
            dfs(i);
            comp[0] += sz;
        }
    }
    ans = 0;
    for(int x : comp){
        ans += 1LL * x * (x - 1LL);
    }
    ans >>= 1;
    ans -= m;
    printf("%lld\n" , ans);
}
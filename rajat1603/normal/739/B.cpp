#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
long long dist[N];
vector < pair < int , int > > v[N];
int a , b;
int cur;
int tin[N];
int tout[N];
int ans[N];
int rev[N];
map < long long , int > mp;
int val;
void dfs(int node , int parent , long long sum){
    dist[node] = sum;
    tin[node] = ++cur;
    rev[cur] = node;
    for(auto it : v[node]){
        int next = it.first;
        if(next != parent){
            dfs(next , node , sum + it.second);
        }
    }
    tout[node] = cur;
}
void comp(){
    mp.clear();
    val = 0;
    for(int i = 1 ; i <= n ; ++i){
        mp[dist[i] - arr[i]];
        mp[dist[i]];
    }
    for(auto &it : mp){
        it.second = ++val;
    }
}
int bit[N + N];
void update(int idx , int v){
    while(idx <= val){
        bit[idx] += v;
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
vector < pair < int , int > > qq[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 2 ; i <= n ; ++i){
        scanf("%d %d" , &a , &b);
        v[i].emplace_back(make_pair(a , b));
        v[a].emplace_back(make_pair(i , b));
    }
    dfs(1 , 0 , 0);
    comp();
    for(int i = 1 ; i <= n ; ++i){
        qq[tin[i]].push_back({i , 1});
        qq[tout[i] + 1].push_back({i , -1});
    }
    for(int i = n ; i >= 1 ; --i){
        int node = rev[i];
        update(mp[dist[node] - arr[node]] , 1);
        for(auto it : qq[i]){
            ans[it.first] += it.second * query(mp[dist[it.first]]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , ans[i] - 1 , " \n"[i == n]);
    }
}
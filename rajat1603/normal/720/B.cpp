#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
const int M = 1.5e4 + 4;
int n , m;
int a[M];
int b[M];
int c[M];
vector < int > v[N];
int comp[M];
vector < int > cols[M];
int cur;
int ans;
int match[M];
int visited[N];
int vtimer;
int baap[N];
int back[M];
bool done[M];
int depth[N];
void dfs(int node , int last){
    visited[node] = 1;
    for(int edge : v[node]){
        if(edge != last){
            int next = a[edge] ^ b[edge] ^ node;
            if(!visited[next]){
                depth[next] = depth[node] + 1;
                dfs(next , edge);
                baap[next] = edge;
            }
            else if(depth[next] < depth[node]){
                back[edge] = node;
            }
        }
    }
}
bool dfs2(int node){
    if(visited[node] == vtimer){
        return 0;
    }
    visited[node] = vtimer;
    for(int next : cols[node]){
        if(!done[next] && (!match[next] || dfs2(match[next]))){
            match[next] = node;
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , a + i , b + i , c + i);
        v[a[i]].emplace_back(i);
        v[b[i]].emplace_back(i);
    }
    dfs(1 , 0);
    ++vtimer;
    for(int i = 1 ; i <= m ; ++i){
        if(back[i]){
            ++cur;
            int node = back[i];
            int tp = a[i] ^ b[i] ^ node;
            while(node != tp){
                comp[baap[node]] = cur;
                node ^= a[baap[node]] ^ b[baap[node]];
            }
            comp[i] = cur;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(!comp[i]){
            ans += !done[c[i]];
            done[c[i]] = 1;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(comp[i]){
            cols[comp[i]].emplace_back(c[i]);
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        for(int j = 1 ; j < cols[i].size() ; ++j){
            ++vtimer;
            if(dfs2(i)){
                ++ans;
            }
            else{
                break;
            }
        }
    }
    printf("%d\n" , ans);
}
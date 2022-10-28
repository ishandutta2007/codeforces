#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n , m;
vector < int > v[N];
int a[N] , b[N];
int bridge[N];
int comp[N];
int sz[N];
int cur;
int tin[N];
int anc[N];
int tim;
vector < int > g[N];
int ans;
int depth[N];
bool back[N];
void dfs(int node , int last){
    tin[node] = anc[node] = ++tim;
    for(int edge : v[node]){
        if(edge != last){
            int next = a[edge] ^ b[edge] ^ node;
            if(!tin[next]){
                dfs(next , edge);
                anc[node] = min(anc[node] , anc[next]);
            }
            else{
                back[edge] = 1;
                anc[node] = min(anc[node] , tin[next]);
            }
            if(anc[next] > tin[node]){
                bridge[edge] = 1;
            }
        }
    }
}
void dfs2(int node){
    if(comp[node]){
        return;
    }
    comp[node] = cur;
    ++sz[cur];
    for(int edge : v[node]){
        if(!bridge[edge]){
            dfs2(a[edge] ^ b[edge] ^ node);
        }
    }
}
void dfs3(int node , int parent){
    depth[node] = depth[parent] + 1;
    for(int next : g[node]){
        if(next != parent){
            dfs3(next , node);
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        v[a[i]].emplace_back(i);
        v[b[i]].emplace_back(i);
    }
    dfs(1 , 0);
    for(int i = 1 ; i <= n ; ++i){
        if(!comp[i]){
            ++cur;
            dfs2(i);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(bridge[i]){
            g[comp[a[i]]].emplace_back(comp[b[i]]);
            g[comp[b[i]]].emplace_back(comp[a[i]]);
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(sz[i] > sz[ans]){
            ans = i;
        }
    }
    dfs3(ans , 0);
    for(int i = 1 ; i <= m ; ++i){
        if(bridge[i]){
            if(depth[comp[a[i]]] < depth[comp[b[i]]]){
                swap(a[i] , b[i]);
            }
        }
        else{
            if(back[i]){
                if(tin[a[i]] < tin[b[i]]){
                    swap(a[i] , b[i]);
                }
            }
            else{
                if(tin[a[i]] > tin[b[i]]){
                    swap(a[i] , b[i]);
                }
            }
        }
    }
    printf("%d\n" , sz[ans]);
    for(int i = 1 ; i <= m ; ++i){
        printf("%d %d\n" , a[i] , b[i]);
    }
}
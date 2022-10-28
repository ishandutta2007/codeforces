#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
int dist1[N];
int dist2[N];
int val , node1 , node2;
int dfs(int node , int dist[] , int parent = 0){
    dist[node] = dist[parent] + 1;
    int res = node;
    for(int next : v[node]){
        if(next != parent){
            int ret = dfs(next , dist , node);
            if(dist[ret] > dist[res]){
                res = ret;
            }
        }
    }
    return res;
}
int depths[N];
int get(int len){
    if(len & 1){
        return len;
    }
    return get(len >> 1);
}
void dfs2(int node , int parent){
    depths[node] = 0;
    map < int , int > mp;
    mp.clear();
    for(int next : v[node]){
        if(next != parent){
            dfs2(next , node);
            depths[node] = max(depths[node] , depths[next] + 1);
            ++mp[depths[next] + 1];
        }
    }
    if(mp.size() > 2){
        printf("-1\n");
        exit(0);
    }
    if(parent == 0){
        if(mp.size() == 1){
            printf("%d\n" , get(depths[node]));
        }
        if(mp.size() == 2){
            printf("%d\n" , get(mp.begin() -> first + next(mp.begin()) -> first));
        }
        exit(0);
    }
    if(mp.size() == 0){
        return;
    }
    if(mp.size() == 1){
        return;
    }
    if(mp.size() == 2 && parent != 0){
        printf("-1\n");
        exit(0);
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(dfs(dfs(1 , dist1) , dist1) , dist2);
    val = n + 1;
    node2 = -1;
    for(int i = 1 ; i <= n ; ++i){
        int m = max(dist1[i] , dist2[i]);
        if(m < val){
            val = m;
            node1 = i;
            node2 = -1;
        }
        else if(m == val){
            node2 = i;
        }
    }
    dfs2(node1 , 0);
}
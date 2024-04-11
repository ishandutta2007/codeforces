#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LEN = 25;
int n , m , q;
map < string , int > mp;
int type;
char a[LEN] , b[LEN];
int col[N];
int parent[N];
vector < int > v[N];
void pre(){
    for(int i = 1 ; i <= n ; ++i){
        col[i] = 0;
        parent[i] = i;
        v[i].clear();
        v[i].emplace_back(i);
    }
}
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void join(int type , int a , int b){
    int x = find(a);
    int y = find(b);
    if(x == y){
        if(col[a] == col[b]){
            if(type == 1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            if(type == 2){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    else{
        bool change = 0;
        if(type == 1){
            if(col[a] != col[b]){
                change = 1;
            }
        }
        else{
            if(col[a] == col[b]){
                change = 1;
            }
        }
        if(v[x].size() < v[y].size()){
            swap(x , y);
            swap(a , b);
        }
        for(int node : v[y]){
            col[node] ^= change;
            v[x].emplace_back(node);
        }
        v[y].clear();
        v[y].shrink_to_fit();
        parent[y] = x;
        printf("YES\n");
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , a);
        mp[a] = i;
    }
    pre();
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %s %s" , &type , a , b);
        join(type , mp[a] , mp[b]);
    }
    while(q--){
        scanf("%s %s" , a , b);
        int x = mp[a];
        int y = mp[b];
        if(find(x) != find(y)){
            printf("3\n");
        }
        else if(col[x] == col[y]){
            printf("1\n");
        }
        else{
            printf("2\n");
        }
    }
}
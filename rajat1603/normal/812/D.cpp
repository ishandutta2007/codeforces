#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , k , q;
int a[N] , b[N];
int lst[N];
vector < int > v[N];
int tin[N];
int tout[N];
int timer;
int indeg[N];
void dfs(int node){
    tin[node] = ++timer;
    for(int next : v[node]){
        dfs(next);
    }
    tout[node] = timer;
}
int main(){
    scanf("%d %d %d %d" , &n , &m , &k , &q);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d %d" , a + i , b + i);
        if(lst[b[i]]){
            v[lst[b[i]]].push_back(a[i]);
            indeg[a[i]] = 1;
        }
        lst[b[i]] = a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!indeg[i]){
            dfs(i);
        }
    }
    while(q--){
        int x , y;
        scanf("%d %d" , &x , &y);
        if(lst[y]){
            int node = x;
            int child = lst[y];
            if(tin[child] >= tin[node] && tout[child] <= tout[node]){
                printf("%d\n" , tout[node] - tin[node] + 1);
            }
            else{
                printf("0\n");
            }
        }
        else{
            printf("0\n");
        }
    }
}
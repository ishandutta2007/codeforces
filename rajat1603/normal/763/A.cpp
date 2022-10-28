#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a , b;
int tin[N];
int tout[N];
int rev[N];
int cur;
int colp[N];
int cols[N];
vector < int > v[N];
int who[N];
int arr[N];
void dfs(int node , int parent){
    ++cur;
    tin[node] = cur;
    rev[cur] = node;
    who[node] = arr[node];
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            if(who[next] == -1){
                who[node] = -1;
            }
            else if(who[next] != who[node]){
                who[node] = -1;
            }
        }
    }
    tout[node] = cur;
}
void dfs2(int node , int parent){
    bool ok = 1;
    if(colp[tin[node] - 1] == -1){
        ok = 0;
    }
    if(cols[tout[node] + 1] == -1){
        ok = 0;
    }
    if(tin[node] > 1 && tout[node] < n){
        if(colp[tin[node] - 1] != cols[tout[node] + 1]){
            ok = 0;
        }
    }
    for(int next : v[node]){
        if(next != parent){
            if(who[next] == -1){
                ok = 0;
            }
        }
    }
    if(ok){
        printf("YES\n%d\n" , node);
        exit(0);
    }
    for(int next : v[node]){
        if(next != parent){
            dfs2(next , node);
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
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    cur = 0;
    dfs(1 , 0);
    colp[1] = arr[rev[1]];
    for(int i = 2 ; i <= n ; ++i){
        if(colp[i - 1] == -1){
            colp[i] = -1;
        }
        else if(colp[i - 1] != arr[rev[i]]){
            colp[i] = -1;
        }
        else{
            colp[i] = colp[i - 1];
        }
    }
    cols[n] = arr[rev[n]];
    for(int i = n - 1 ; i >= 1 ; --i){
        if(cols[i + 1] == -1){
            cols[i] = -1;
        }
        else if(cols[i + 1] != arr[rev[i]]){
            cols[i] = -1;
        }
        else{
            cols[i] = cols[i + 1];
        }
    }
    dfs2(1 , 0);
    printf("NO\n");
}
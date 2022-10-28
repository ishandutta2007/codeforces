#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m , k;
int a[N] , b[N];
vector < int > v[N];
bool visited[N];
int mx;
int arr[N + N];
int sz;
vector < int > ans[N];
void dfs(int node , int parent){
    arr[++sz] = node;
    visited[node] = 1;
    bool child = 0;
    for(int next : v[node]){
        if(!visited[next]){
            child = 1;
            dfs(next , node);
            arr[++sz] = node;
        }
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        v[a[i]].emplace_back(b[i]);
        v[b[i]].emplace_back(a[i]);
    }
    mx = (n + n + k - 1) / k;
    dfs(1 , 0);
    int cur = 1;
    for(int i = 1 ; i <= k && cur <= sz ; ++i){
        for(int j = cur ; j < cur + mx ; ++j){
            if(j <= sz){
                ans[i].emplace_back(arr[j]);
            }
            else{
                break;
            }
        }
        cur += mx;
    }
    for(int i = 1 ; i <= k ; ++i){
        if(ans[i].empty()){
            ans[i].emplace_back(i);
        }
        printf("%d" , int(ans[i].size()));
        for(int x : ans[i]){
            printf(" %d" , x);
        }
        printf("\n");
    }
}
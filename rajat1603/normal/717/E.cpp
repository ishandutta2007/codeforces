#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int a , b;
vector < int > v[N];
void dfs(int node , int parent){
    printf("%d " , node);
    int child = 0;
    for(int next : v[node]){
        if(next != parent){
            child = next;
            arr[next] *= -1;
            dfs(next , node);
            arr[node] *= -1;
            printf("%d " , node);
        }
    }
    if(arr[node] == -1){
        if(parent){
            printf("%d " , parent);
            arr[parent] *= -1;
            printf("%d " , node);
            arr[node] *= -1;
        }
        else{
            printf("%d " , child);
            printf("%d " , node);
            printf("%d " , child);
            arr[node] *= -1;
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
    dfs(1 , 0);
}
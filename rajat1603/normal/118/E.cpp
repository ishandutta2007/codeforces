#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 3e5 + 5;
int n , m;
int a[M] , b[M];
vector < int > v[N];
int tin[N];
int anc[N];
int timer;
vector < pair < int , int > > ans;
void dfs(int node , int parent){
    tin[node] = anc[node] = ++timer;
    for(int edge : v[node]){
        int next = a[edge] ^ b[edge] ^ node;
        if(next != parent){
            if(!tin[next]){
                dfs(next , node);
                anc[node] = min(anc[node] , anc[next]);
                ans.push_back({node , next});
            }
            else{
                anc[node] = min(anc[node] , tin[next]);
                if(tin[next] < tin[node]){
                    ans.push_back({node , next});
                }
            }
            if(anc[next] > tin[node]){
                printf("0\n");
                exit(0);
            }
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
    for(auto it : ans){
        printf("%d %d\n" , it.first , it.second);
    }
}
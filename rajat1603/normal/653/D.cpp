#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int M = 505;
const int X = 1e5 + 5;
const double eps = 1e-7;
int n , m , x;
int adj[N][N];
double graph[N][N];
int a , b , c;
double l , r;
bool visited[N];
queue < int > q;
int parent[N];
bool bfs(){
    while(!q.empty()){
        q.pop();
    }
    memset(visited , 0 , sizeof(visited));
    memset(parent , -1 , sizeof(parent));
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; ++i){
            if(!visited[i] && graph[node][i] >= eps){
                q.push(i);
                visited[i] = 1;
                parent[i] = node;
            }
        }
    }
    return visited[n];
}
bool check(double val){
    double one = val / x;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            graph[i][j] = floor(1.0 * adj[i][j] / one + eps);
        }
    }
    double flow = 0;
    while(bfs()){
        double val = 1e15;
        int node = n;
        while(node != 1){
            int baap = parent[node];
            val = min(val , graph[baap][node]);
            node = baap;
        }
        node = n;
        while(node != 1){
            int baap = parent[node];
            graph[baap][node] -= val;
            graph[node][baap] += val;
            node = baap;
        }
        flow += val;
    }
    return (flow * one >= val - eps);
}
int main(){
    scanf("%d %d %d" , &n , &m , &x);
    memset(adj , 0 , sizeof(adj));
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        adj[a][b] = c;
    }
    l = 0.0;
    r = 1e9;
    for(int i = 0 ; i < 100 ; ++i){
        double mid = l + r;
        mid /= 2.0;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    printf("%.9lf\n" , (l + r) / 2.0);
}
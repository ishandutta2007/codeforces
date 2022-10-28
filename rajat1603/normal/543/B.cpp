#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
const int inf = 1e9;
int n , m;
int a , b;
vector < int > v[N];
int s1 , t1 , l1 , s2 , t2 , l2;
int dist[N][N];
int ans;
void bfs(int start){
    for(int i = 1 ; i <= n ; ++i){
        dist[start][i] = inf;
    }
    dist[start][start] = 0;
    queue < int > q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : v[node]){
            if(dist[start][next] > dist[start][node] + 1){
                dist[start][next] = dist[start][node] + 1;
                q.push(next);
            }
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    scanf("%d %d %d %d %d %d" , &s1 , &t1 , &l1 , &s2 , &t2 , &l2);
    for(int i = 1 ; i <= n ; ++i){
        bfs(i);
    }
    if(dist[s1][t1] > l1 || dist[s2][t2] > l2){
        printf("-1\n");
        return 0;
    }
    ans = m - dist[s1][t1] - dist[s2][t2];
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(dist[s1][i] + dist[j][t1] + dist[i][j] <= l1 && dist[s2][i] + dist[j][t2] + dist[i][j] <= l2){
                ans = max(ans , m - (dist[s1][i] + dist[s2][i] + dist[j][t1] + dist[j][t2] + dist[i][j]));
            }
            if(dist[s1][i] + dist[j][t1] + dist[i][j] <= l1 && dist[s2][j] + dist[i][t2] + dist[i][j] <= l2){
                ans = max(ans , m - (dist[s1][i] + dist[s2][j] + dist[j][t1] + dist[i][t2] + dist[i][j]));
            }
        }
    }
    printf("%d\n" , ans);
}
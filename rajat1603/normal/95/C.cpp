#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const long long inf = 1e15 + 15;
int n , m;
int s , t;
int a , b , c;
vector < pair < int , int > > v[N];
long long dist[N][N];
void dijkstra(int source , long long dist[]){
    for(int i = 1 ; i <= n ; ++i){
        dist[i] = inf;
    }
    priority_queue < pair < long long , int > > pq;
    while(!pq.empty()){
        pq.pop();
    }
    dist[source] = 0;
    pq.push({0 , source});
    while(!pq.empty()){
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }
        for(auto it : v[node]){
            int next = it.first;
            if(dist[next] > cost + it.second){
                dist[next] = cost + it.second;
                pq.push({-cost - it.second , next});
            }
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    scanf("%d %d" , &s , &t);
    while(m--){
        scanf("%d %d %d" , &a , &b , &c);
        v[a].emplace_back(make_pair(b , c));
        v[b].emplace_back(make_pair(a , c));
    }
    for(int i = 1 ; i <= n ; ++i){
        dijkstra(i , dist[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        v[i].clear();
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &a , &b);
        for(int j = 1 ; j <= n ; ++j){
            if(dist[i][j] <= a){
                v[i].emplace_back(make_pair(j , b));
            }
        }
    }
    dijkstra(s , dist[0]);
    if(dist[0][t] >= inf){
        dist[0][t] = -1;
    }
    printf("%lld\n" , dist[0][t]);
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;
int n , m , s , t;
int edges[N][3];
vector < pair < int , int > > v[2][N];
long long dist[2][N];
int ways[2][N];
int way[2][N];
void dikcjstras(int so , bool idx){
    memset(dist[idx] , -1 , sizeof(dist[idx]));
    memset(ways[idx] , 0 , sizeof(ways[idx]));
    memset(way[idx] , 0 , sizeof(way[idx]));
    ways[idx][so] = 1;
    way[idx][so] = 1;
    dist[idx][so] = 0;
    priority_queue < pair < long long , int > > pq;
    pq.push(make_pair(0 , so));
    while(!pq.empty()){
        int node = pq.top().second;
        long long dis = -pq.top().first;
        pq.pop();
        if(dis > dist[idx][node]){
            continue;
        }
        for(auto it : v[idx][node]){
            int next = it.first;
            int weight = it.second;
            if(dist[idx][next] == -1 || dist[idx][next] > dist[idx][node] + weight){
                dist[idx][next] = dist[idx][node] + weight;
                ways[idx][next] = ways[idx][node];
                way[idx][next] = way[idx][node];
                pq.push(make_pair(-dist[idx][next] , next));
            }
            else if(dist[idx][next] == dist[idx][node] + weight){
                ways[idx][next] += ways[idx][node];
                if(ways[idx][next] >= mod){
                    ways[idx][next] -= mod;
                }
                way[idx][next] += way[idx][node];
                if(way[idx][next] >= mod1){
                    way[idx][next] -= mod1;
                }
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d" , &n , &m , &s , &t);
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            scanf("%d" , &edges[i][j]);
        }
        v[0][edges[i][0]].push_back(make_pair(edges[i][1] , edges[i][2]));
        v[1][edges[i][1]].push_back(make_pair(edges[i][0] , edges[i][2]));
    }
    dikcjstras(s , 0);
    dikcjstras(t , 1);
    for(int i = 1 ; i <= m ; ++i){
        int x = edges[i][0];
        int y = edges[i][1];
        int w = edges[i][2];
        if(dist[0][x] == -1 || dist[1][y] == -1){
            printf("NO\n");
        }
        else if(dist[0][x] + dist[1][y] + w == dist[0][t] && (1LL * ways[0][x] * ways[1][y]) % mod == ways[0][t] && (1LL * way[0][x] * way[1][y]) % mod1 == way[0][t]){
            printf("YES\n");
        }
        else if(dist[0][x] + dist[1][y] + 1 < dist[0][t]){
            printf("CAN %lld\n" , dist[0][x] + dist[1][y] + w - dist[0][t] + 1);
        }
        else{
            printf("NO\n");
        }
    }
}
#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 1e4 + 4;
const long long inf = 1e15 + 15;
int n , m , l , s , t;
int a[M] , b[M];
long long c[M];
bool rektedge[M];
vector < int > v[N];
long long dist[N];
int pre[N];
int used[M];
int curr;
void rekt(){
    printf("NO\n");
    exit(0);
}
void sss(long long val){
    for(int i = 0 ; i < n ; ++i){
        dist[i] = inf;
    }
    dist[s] = 0;
    priority_queue < pair < long long , int > > pq;
    while(!pq.empty()){
        pq.pop();
    }
    pq.push({0 , s});
    while(!pq.empty()){
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }
        for(int edge : v[node]){
            int next = a[edge] ^ b[edge] ^ node;
            long long weight = cost + (rektedge[edge] ? val : c[edge]);
            if(dist[next] > weight){
                dist[next] = weight;
                pq.push({-weight , next});
            }
        }
    }
}
void solve(){
    for(int i = 0 ; i < n ; ++i){
        dist[i] = inf;
        pre[i] = -1;
    }
    dist[s] = 0;
    priority_queue < pair < long long , int > > pq;
    while(!pq.empty()){
        pq.pop();
    }
    pq.push({0 , s});
    while(!pq.empty()){
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }
        for(int edge : v[node]){
            int next = a[edge] ^ b[edge] ^ node;
            long long weight = cost + max(1LL , c[edge]);
            if(dist[next] > weight){
                dist[next] = weight;
                pq.push({-weight , next});
                pre[next] = edge;
            }
        }
    }
    int node = t;
    ++curr;
    while(node != s){
        int edge = pre[node];
        if(c[edge] == 0){
            c[edge] = 1;
        }
        used[edge] = curr;
        node ^= a[edge] ^ b[edge];
    }
    for(int i = 1 ; i <= m ; ++i){
        if(rektedge[i] && (used[i] != curr)){
            c[i] = inf;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(rektedge[i] && used[i] == curr){
            c[i] += l - dist[t];
            break;
        }
    }
    if(dist[t] >= l){
        for(int i = 1 ; i <= m ; ++i){
            printf("%d %d %lld\n" , a[i] , b[i] , c[i]);
        }
        return;
    }
    solve();
}
int main(){
    scanf("%d %d %d %d %d" , &n , &m , &l , &s , &t);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %lld" , a + i , b + i , c + i);
        v[a[i]].emplace_back(i);
        v[b[i]].emplace_back(i);
        rektedge[i] = !c[i];
    }
    sss(1);
    if(dist[t] > l){
        rekt();
    }
    sss(l + 1);
    if(dist[t] < l){
        rekt();
    }
    printf("YES\n");
    solve();
}
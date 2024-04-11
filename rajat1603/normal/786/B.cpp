#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int SN = 1 << 20;
const long long inf = 1e16 + 16;
int n , q , s;
int type[N];
int a[N] , b[N] , c[N];
int u[N] , l[N] , r[N];
int cur;
vector < pair < int , int > > v[N];
int in[SN];
int ou[SN];
void build(int l , int r , int node){
    if(l == r){
        in[node] = l;
        ou[node] = r;
    }
    else{
        in[node] = ++cur;
        ou[node] = ++cur;
    }
    if(l < r){
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        v[ou[node]].emplace_back(make_pair(ou[node + node] , 0));
        v[ou[node]].emplace_back(make_pair(ou[node + node + 1] , 0));
        v[in[node + node]].emplace_back(make_pair(in[node] , 0));
        v[in[node + node + 1]].emplace_back(make_pair(in[node] , 0));
    }
}
void query(int l , int r , int node , int ql , int qr , int vertex , int type , int cost){
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        if(type == 2){
            v[vertex].emplace_back(make_pair(ou[node] , cost));
        }
        else{
            v[in[node]].emplace_back(make_pair(vertex , cost));
        }
        return;
    }
    int mid = l + r >> 1;
    query(l , mid , node + node , ql , qr , vertex , type , cost);
    query(mid + 1 , r , node + node + 1 , ql , qr , vertex , type , cost);
}
long long dist[N];
priority_queue < pair < long long , int > > pq;
int main(){
    scanf("%d %d %d" , &n , &q , &s);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , type + i);
        if(type[i] == 1){
            scanf("%d %d %d" , a + i , b + i , c + i);
        }
        else{
            scanf("%d %d %d %d" , u + i , l + i , r + i , c + i);
        }
    }
    cur = n;
    build(1 , n , 1);
    for(int i = 1 ; i <= q ; ++i){
        if(type[i] == 1){
            v[a[i]].emplace_back(make_pair(b[i] , c[i]));
        }
        else{
            query(1 , n , 1 , l[i] , r[i] , u[i] , type[i] , c[i]);
        }
    }
    while(!pq.empty()){
        pq.pop();
    }
    for(int i = 1 ; i <= cur ; ++i){
        dist[i] = inf;
    }
    dist[s] = 0;
    pq.push(make_pair(0 , s));
    while(!pq.empty()){
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }
        for(auto it : v[node]){
            int next = it.first;
            long long d = cost + it.second;
            if(dist[next] > d){
                dist[next] = d;
                pq.push(make_pair(-d , next));
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(dist[i] >= inf){
            dist[i] = -1;
        }
        printf("%lld%c" , dist[i] , " \n"[i == n]);
    }
}
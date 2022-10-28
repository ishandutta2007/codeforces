#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int M = 3e5 + 5;
const long long inf = 2e15 + 15;
int n , m , s;
int a[M] , b[M] , c[M];
vector < int > v[N];
long long dist[N];
vector < int > g[N];
int arr[N];
int cnt;
int dom[N];
int ans[N];
void diskjstra(){
    for(int i = 1 ; i <= n ; ++i){
        dist[i] = inf;
    }
    priority_queue < pair < long long , int > > pq;
    pq.push({0 , s});
    dist[s] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        long long cost = -pq.top().first;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }
        arr[++cnt] = node;
        for(int edge : v[node]){
            int next = a[edge] ^ b[edge] ^ node;
            if(dist[next] > cost + c[edge]){
                dist[next] = cost + c[edge];
                pq.push({-cost - c[edge] , next});
            }
        }
    }
}
void makedag(){
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            if(dist[a[i]] + c[i] == dist[b[i]]){
                g[b[i]].push_back(a[i]);
            }
            swap(a[i] , b[i]);
        }
    }
}
void solve(){
    for(int i = 1 ; i <= cnt ; ++i){
        int node = arr[i];
        int val = -1;
        bool rekt = 0;
        for(int prev : g[node]){
            if(prev == s){
                rekt = 1;
            }
            else if(val == -1){
                val = dom[prev];
            }
            else if(val != dom[prev]){
                rekt = 1;
            }
        }
        if(rekt){
            dom[node] = node;
        }
        else{
            dom[node] = val;
        }
        ++ans[dom[node]];
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &s);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , a + i , b + i , c + i);
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }
    diskjstra();
    makedag();
    solve();
    printf("%d\n" , *max_element(ans + 1 , ans + 1 + n));
}
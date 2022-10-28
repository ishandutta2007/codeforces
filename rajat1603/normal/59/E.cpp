#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
const int inf = 1e6 + 6;
const int K = 1e5 + 5;
int n , m , k;
int a , b , c;
vector < int > v[N];
int cnt[N];
vector < int > rekt[N][N];
int block[N];
int timer;
int tot[N];
int dist[N][N];
pair < int , int > prv[N][N];
priority_queue < pair < int , pair < int , int > > > pq;
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    while(m--){
        scanf("%d %d" , &a , &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(k--){
        scanf("%d %d %d" , &a , &b , &c);
        ++cnt[b];
        rekt[a][b].push_back(c);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dist[i][j] = inf;
        }
    }
    pq.push({0 , {1 , 0}});
    dist[1][0] = 0;
    int ans = -1;
    int ansl;
    while(!pq.empty()){
        int node = pq.top().second.first;
        int last = pq.top().second.second;
        int cost = -pq.top().first;
        if(node == n){
            ans = cost;
            ansl = last;
            break;
        }
        pq.pop();
        if(tot[node] >= cnt[node] + 1){
            continue;
        }
        if(cost > dist[last][node]){
            continue;
        }
        ++tot[node];
        ++timer;
        for(int x : rekt[last][node]){
            block[x] = timer;
        }
        for(int next : v[node]){
            if(block[next] < timer && tot[next] <= cnt[next]){
                if(dist[node][next] > cost + 1){
                    dist[node][next] = cost + 1;
                    pq.push({-(cost + 1) , {next , node}});
                    prv[node][next] = make_pair(last , node);
                }
            }
        }
    }
    printf("%d" , ans);
    if(ans >= 0){
        pair < int , int > node = make_pair(ansl , n);
        vector < int > print;
        do{
            print.emplace_back(node.second);
            node = prv[node.first][node.second];
        }while(node.second != 1);
        reverse(print.begin() , print.end());
        printf("\n1");
        for(int node : print){
            printf(" %d" , node);
        }
    }
    printf("\n");
}
#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int inf = 1e9 + 9;
int n , m , t;
vector < pair < int , int > > v[N];
int dist[N][N];
int pre[N][N];
int a , b , c;
int indeg[N];
queue < int > q;
int main(){
    scanf("%d %d %d" , &n , &m , &t);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dist[i][j] = inf;
        }
        v[i].clear();
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        v[a].emplace_back(make_pair(b , c));
        ++indeg[b];
    }
    dist[1][1] = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!indeg[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : v[node]){
            int next = it.first;
            --indeg[next];
            if(!indeg[next]){
                q.push(next);
            }
            for(int j = 1 ; j < n ; ++j){
                if(dist[next][j + 1] > dist[node][j] + it.second){
                    dist[next][j + 1] = dist[node][j] + it.second;
                    pre[next][j + 1] = node;
                }
            }
        }
    }
    int node = n;
    int cur;
    for(int i = 1 ; i <= n ; ++i){
        if(dist[node][i] <= t){
            cur = i;
        }
    }
    vector < int > ans;
    ans.emplace_back(node);
    while(node != 1){
        node = pre[node][cur--];
        ans.emplace_back(node);
    }
    reverse(ans.begin() , ans.end());
    printf("%d\n" , int(ans.size()));
    for(int node : ans){
        printf("%d " , node);
    }
}
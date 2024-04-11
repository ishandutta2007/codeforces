#include "bits/stdc++.h"
using namespace std;
const int N = 405;
int n , m;
int a , b;
int v1[N][N];
int v2[N][N];
int dist1[N];
int dist2[N];
queue < int > q;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            v1[i][j] = 0;
            v2[i][j] = 1;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v1[a][b] = 1;
        v1[b][a] = 1;
        v2[a][b] = 0;
        v2[b][a] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        dist1[i] = 1e8;
        dist2[i] = 1e8;
    }
    dist1[1] = 0;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; ++i){
            if(v1[node][i]){
                if(dist1[node] + 1 < dist1[i]){
                    dist1[i] = dist1[node] + 1;
                    q.push(i);
                }
            }
        }
    }
    dist2[1] = 0;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 1 ; i <= n ; ++i){
            if(v2[node][i]){
                if(dist2[node] + 1 < dist2[i]){
                    if(i == n){
                        dist2[i] = dist2[node] + 1;
                        q.push(i);
                    }
                    else{
                        if(dist1[i] == dist2[node] + 1){
                            if(dist2[node] + 2 < dist2[i]){
                                dist2[i] = dist2[node] + 2;
                                q.push(i);
                            }
                        }
                        else{
                            dist2[i] = dist2[node] + 1;
                            q.push(i);
                        }
                    }
                }
            }
        }
    }
    int ans = max(dist1[n] , dist2[n]);
    if(ans >= n * n){
        ans = -1;
    }
    printf("%d\n" , ans);
}
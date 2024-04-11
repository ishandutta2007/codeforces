#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 6;
const int M = 6 * N;
const int inf = 1e9 + 9;
const int SZ = 1 << 12;
int n , p , s;
int a[N];
int b[N];
int from[M];
int to[M];
int cap[M];
int cst[M];
int cur;
vector < int > v[N];
int sum;
void addedge(int a , int b , int c , int d){
    v[a].emplace_back(cur);
    from[cur] = a;
    to[cur] = b;
    cap[cur] = c;
    cst[cur] = d;
    ++cur;
    v[b].emplace_back(cur);
    from[cur] = b;
    to[cur] = a;
    cap[cur] = 0;
    cst[cur] = -d;
    ++cur;
}
int pre[N];
int dist[N];
int que[SZ];
bool inq[N];
int h , t;
bool bfs(){
    for(int i = 0 ; i <= n + 3 ; ++i){
        dist[i] = inf;
        inq[i] = 0;
    }
    dist[0] = 0;
    h = 0;
    t = 0;
    que[t++] = 0;
    inq[0] = 1;
    while(h != t){
        int node = que[h];
        h = (h + 1) & 4095;
        inq[node] = 0;
        int d = dist[node];
        for(int edge : v[node]){
            if(cap[edge]){
                int next = to[edge];
                int weight = d + cst[edge];
                if(weight < dist[next]){
                    dist[next] = weight;
                    pre[next] = edge;
                    if(!inq[next]){
                        que[t] = next;
                        t = (t + 1) & 4095;
                        inq[next] = 1;
                    }
                }
            }
        }
    }
    return dist[n + 3] < inf;
}
int main(){
    scanf("%d %d %d" , &n , &p , &s);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , b + i);
    }
    addedge(0 , 1 , p , 0);
    addedge(0 , 2 , s , 0);
    for(int i = 1 ; i <= n ; ++i){
        addedge(1 , i + 2 , 1 , -a[i]);
        addedge(2 , i + 2 , 1 , -b[i]);
        addedge(i + 2 , n + 3 , 1 , 0);
    }
    while(bfs()){
        int node = n + 3;
        while(node){
            int edge = pre[node];
            --cap[edge];
            ++cap[edge ^ 1];
            node = from[edge];
        }
        sum -= dist[n + 3];
    }
    printf("%d\n" , sum);
    for(int i = 0 ; i < cur ; i += 2){
        if(from[i] == 1){
            if(cap[i ^ 1]){
                printf("%d " , to[i] - 2);
            }
        }
    }
    printf("\n");
    for(int i = 0 ; i < cur ; i += 2){
        if(from[i] == 2){
            if(cap[i ^ 1]){
                printf("%d " , to[i] - 2);
            }
        }
    }
    printf("\n");
}
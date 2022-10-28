#include "bits/stdc++.h"
using namespace std;
const int N = 505;
const int M = 105;
const int E = M * N;
const int inf = 1e9 + 9;
int n;
char str[N];
int m;
char arr[M][N];
int p[M];
int x;
vector < int > v[N];
int cur;
int from[E];
int to[E];
int cap[E];
int cst[E];
int dist[N];
int prv[N];
int que[E + N];
void addedge(int a , int b , int c , int d){
    v[a].push_back(cur);
    from[cur] = a;
    to[cur] = b;
    cap[cur] = c;
    cst[cur] = d;
    ++cur;
    v[b].push_back(cur);
    from[cur] = b;
    to[cur] = a;
    cap[cur] = 0;
    cst[cur] = -d;
    ++cur;
}
bool bfs(){
    for(int i = 0 ; i <= n + 1 ; ++i){
        dist[i] = inf;
        prv[i] = -1;
    }
    dist[0] = 0;
    int h = 0;
    int t = 0;
    que[t++] = 0;
    while(h < t){
        int node = que[h++];
        for(int edge : v[node]){
            if(cap[edge]){
                int next = to[edge];
                if(dist[node] + cst[edge] < dist[next]){
                    dist[next] = dist[node] + cst[edge];
                    prv[next] = edge;
                    que[t++] = next;
                }
            }
        }
    }
    return dist[n + 1] < inf;
}
void flow(){
    int ans = 0;
    while(bfs()){
        int node = n + 1;
        int preans = ans;
        while(node){
            --cap[prv[node]];
            ++cap[prv[node] ^ 1];
            ans += cst[prv[node]];
            node = from[prv[node]];
        }
        if(ans == preans){
            break;
        }
    }
    printf("%d\n" , -ans);
}
int main(){
    scanf("%d" , &n);
    scanf("%s" , str + 1);
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%s %d" , arr[i] , p + i);
    }
    scanf("%d" , &x);
    cur = 0;
    for(int i = 0 ; i <= n ; ++i){
        addedge(i , i + 1 , x , 0);
    }
    for(int i = 1 ; i <= m ; ++i){
        int len = strlen(arr[i]);
        for(int j = 1 ; j + len - 1 <= n ; ++j){
            bool ok = 1;
            for(int k = 0 ; k < len ; ++k){
                if(str[j + k] != arr[i][k]){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                addedge(j , j + len , 1 , -p[i]);
            }
        }
    }
    flow();
}
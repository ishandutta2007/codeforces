#include "bits/stdc++.h"
using namespace std;
const int N = 2e2 + 6;
const int M = N * N;
const int inf = 1e9 + 9;
const int SZ = 256;
int n , m;
char str[N];
char tmp[5];
int val1[N];
int val2[N];
int from[M];
int to[M];
int cap[M];
int cst[M];
int cur;
vector < int > v[N];
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
int flo;
int ans;
int sum;
bool bfs(){
    for(int i = 0 ; i <= n + m + 1 ; ++i){
        dist[i] = inf;
        inq[i] = 0;
    }
    dist[0] = 0;
    h = 0;
    t = 0;
    que[t++] = 0;
    inq[0] = 1;
    while(h != t){
        int node = que[h++];
        if(h >= SZ){
            h = 0;
        }
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
                        que[t++] = next;
                        if(t >= SZ){
                            t = 0;
                        }
                        inq[next] = 1;
                    }
                }
            }
        }
    }
    return dist[n + m + 1] < inf;
}
void solveall(){
    multiset < int > ms;
    ms.clear();
    for(int i = 1 ; i <= m ; ++i){
        ms.insert(val2[i]);
    }
    int sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'D'){
            auto it = ms.lower_bound(val1[i] + 1);
            ms.erase(it);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'A'){
            auto it = ms.lower_bound(val1[i]);
            sum += *it - val1[i];
            ms.erase(it);
        }
    }
    for(auto it : ms){
        sum += it;
    }
    ans = max(ans , sum);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s %d" , tmp , val1 + i);
        str[i] = tmp[0];
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , val2 + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        addedge(0 , i , 1 , 0);
        for(int j = 1 ; j <= m ; ++j){
            if(str[i] == 'A' && val1[i] <= val2[j]){
                addedge(i , j + n , 1 , val1[i]);
            }
            if(str[i] == 'D' && val1[i] < val2[j]){
                addedge(i , j + n , 1 , val2[j]);
            }
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        addedge(i + n , n + m + 1 , 1 , -val2[i]);
    }
    while(bfs()){
        ++flo;
        int node = n + m + 1;
        while(node){
            int edge = pre[node];
            --cap[edge];
            ++cap[edge ^ 1];
            node = from[edge];
        }
        sum -= dist[n + m + 1];
        ans = max(ans , sum);
    }
    if(flo == n){
        solveall();
    }
    printf("%d\n" , ans);
}
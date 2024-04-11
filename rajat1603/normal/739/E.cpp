#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int E = 8 * N;
const int inf = 1e9 + 9;
int n , a , b;
double p[N];
double u[N];
vector < int > v[N];
int cur;
int from[E];
int to[E];
int cap[E];
int cst[E];
int dist[N];
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
    for(int i = 0 ; i <= n + 3 ; ++i){
        dist[i] = inf;
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
                    que[t++] = next;
                }
            }
        }
    }
    return dist[n + 3] < inf;
}
int visited[N];
int timer;
int dfs(int node , int val){
	if(node == n + 3){
		return val;
	}
	if(visited[node] == timer){
		return 0;
	}
	visited[node] = timer;
	int tot = 0;
	for(int edge : v[node]){
		if(cap[edge]){
			int next = to[edge];
			if(dist[next] == dist[node] + cst[edge]){
				int tmp = dfs(next , min(val - tot , cap[edge]));
				if(tmp){
					cap[edge] -= tmp;
					cap[edge ^ 1] += tmp;
					tot += tmp;
				}
				if(tot == val){
					break;
				}
			}
		}
	}
	return tot;
}
void flow(){
    int ans = 0;
    while(bfs()){
    	++timer;
    	ans -= dfs(0 , 2e9 + 9) * dist[n + 3];
    }
    printf("%.6lf\n" , 1.0 * ans / 1000000);
}
int main(){
    scanf("%d %d %d" , &n , &a , &b);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lf" , p + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lf" , u + i);
    }
    addedge(0 , 1 , a , 0);
    addedge(0 , 2 , b , 0);
    for(int i = 1 ; i <= n ; ++i){
        addedge(1 , 2 + i , 1 , p[i] * -1000000);
        addedge(2 , 2 + i , 1 , u[i] * -1000000);
        addedge(2 + i , n + 3 , 1 , 0);
        addedge(2 + i , n + 3 , 1 , p[i] * u[i] * 1000000);
    }
    flow();
}
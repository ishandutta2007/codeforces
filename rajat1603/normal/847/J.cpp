#include "bits/stdc++.h"
using namespace std;
namespace flow{
    const int V = 2e4 + 4;
    const int E = 2e5 + 5;
    const int inf = 1e6 + 6;
    vector < int > v[V];
    int a[E];
    int b[E];
    int c[E];
    int cur;
    int s , t;
    void init(){
        for(int i = 0 ; i < V ; ++i){
        	v[i].clear();
        }
        cur = 0;
        s = 0;
        t = 0;
    }
    void addedge(int x , int y , int z){
        a[cur] = x;
        b[cur] = y;
        c[cur] = z;
        v[x].emplace_back(cur);
        ++cur;
        a[cur] = y;
        b[cur] = x;
        c[cur] = 0;
        v[y].emplace_back(cur);
        ++cur;
    }
    int dist[V];
    int que[V];
    int qs , qe;
    bool bfs(){
        qs = 0;
        qe = 0;
        for(int i = s ; i <= t ; ++i){
            dist[i] = V;
        }
        que[qe++] = s;
        dist[s] = 0;
        while(qs < qe){
            int node = que[qs++];
            for(int edge : v[node]){
                if(c[edge]){
                    int next = b[edge];
                    if(dist[next] > dist[node] + 1){
                        dist[next] = dist[node] + 1;
                        que[qe++] = next;
                    }
                }
            }
        }
        return dist[t] < V;
    }
    int visited[V];
    int timer;
    int dfs(int node , int val){
        if(node == t){
            return val;
        }
        if(visited[node] == timer){
            return 0;
        }
        visited[node] = timer;
        int tot = 0;
        for(int edge : v[node]){
            if(c[edge]){
                int next = b[edge];
                if(dist[next] == dist[node] + 1){
                    int tmp = dfs(next , min(val - tot , c[edge]));
                    tmp = min(tmp , val - tot);
                    if(tmp){
                        c[edge] -= tmp;
                        c[edge ^ 1] += tmp;
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
    int getflow(){
        int res = 0;
        while(bfs()){
            ++timer;
            res += dfs(s , inf);
        }
        return res;
    }
}


const int N = 2e4 + 4;
int n , m;
int a[N] , b[N];
int deg[N];
bool check(int mid){
	flow :: init();
	flow :: s = 0;
	flow :: t = m + n + 1;
	for(int i = 1 ; i <= m ; ++i){
		flow :: addedge(0 , i , 1);
	}
	for(int i = 1 ; i <= m ; ++i){
		flow :: addedge(i , a[i] + m , 1);
		flow :: addedge(i , b[i] + m , 1);
	}
	for(int i = 1 ; i <= n ; ++i){
		flow :: addedge(i + m , n + m + 1 , mid);
	}
	return flow :: getflow() == m;
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , a + i , b + i);
		++deg[a[i]];
		++deg[b[i]];
	}
	int l = 0;
	int r = n - 1;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
	check(l);
	for(int i = 0 ; i < flow :: cur ; ++i){
		if(flow :: a[i] >= 1 && flow :: a[i] <= m && flow :: b[i] >= m + 1 && flow :: b[i] <= n + m && flow :: c[i] == 0){
			printf("%d %d\n" , flow :: b[i] - m , a[flow :: a[i]] ^ b[flow :: a[i]] ^ (flow :: b[i] - m));
		}
	}
}
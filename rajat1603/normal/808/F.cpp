#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int M = 2e5 + 5;
bool p[M];
void sieve(){
	memset(p , 0 , sizeof(p));
	p[0] = 1;
	p[1] = 1;
	for(int i = 2 ; i * i < M ; ++i){
		if(!p[i]){
			for(int j = i * i ; j < M ; j += i){
				p[j] = 1;
			}
		}
	}
}
namespace flow{
    const int V = 105;
    const int E = 50005;
    const int inf = 1e6 + 6;
    vector < int > v[V];
    int a[E];
    int b[E];
    int c[E];
    int cur;
    int s , t;
    void init(int _s , int _t){
    	for(int i = 0 ; i < V ; ++i){
    		v[i].clear();
    	}
    	cur = 0;
    	s = _s;
    	t = _t;
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
int n , k;
int power[N] , num[N] , level[N];
int all[N];
int name[N];
int solve(){
	int cur = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(all[i]){
			if(num[i] & 1){
				name[i] = ++cur;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(all[i]){
			if(!(num[i] & 1)){
				name[i] = ++cur;
			}
		}
	}
	flow :: init(0 , cur + 1);
	long long ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(all[i]){
			if(num[i] & 1){
				ans += power[i];
				flow :: addedge(0 , name[i] , power[i]);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(all[i] && all[j]){
				if((num[i] & 1) && (!(num[j] & 1))){
					if(!p[num[i] + num[j]]){
						flow :: addedge(name[i] , name[j] , flow :: inf);
					}
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(all[i]){
			if(!(num[i] & 1)){
				ans += power[i];
				flow :: addedge(name[i] , cur + 1 , power[i]);
			}
		}
	}
	return ans - flow :: getflow();
}
bool check(int maxlevel){
	for(int i = 1 ; i <= n ; ++i){
		all[i] = (level[i] <= maxlevel);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(num[i] == 1){
			all[i] = 0;
		}
	}
	if(solve() >= k){
		return 1;
	}
	int idx = -1;
	int mxval = -1;
	for(int i = 1 ; i <= n ; ++i){
		all[i] = (level[i] <= maxlevel);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!all[i]){
			continue;
		}
		if(num[i] != 1){
			continue;
		}
		if(power[i] > mxval){
			mxval = power[i];
			idx = i;
		}
	}
	if(idx != -1){
		for(int i = 1 ; i <= n ; ++i){
			if(num[i] == 1){
				all[i] = 0;
			}
			if(!p[num[i] + 1]){
				all[i] = 0;
			}
		}
		return solve() + mxval >= k;
	}
	return 0;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , power + i , num + i , level + i);
	}
	sieve();
	if(!check(n + 1)){
		printf("-1\n");
		return 0;
	}
	int l = 1;
	int r = n;
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
}
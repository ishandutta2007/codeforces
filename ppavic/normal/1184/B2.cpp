#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define PB push_back

using namespace std;

typedef vector < int > vi;
typedef long long ll;

const int N = 2e3 + 500;
const int M = 105;
const int INF = 0x3f3f3f3f;

int dis[M][M], n, m, k, f, ATK[N], DEF[N], LOC_A[N], LOC_D[N], FUL[N], NIL;
int Pair[N], Dist[N];
vi Adj[N];

bool BFS(){
	queue < int > Q;
	for(int i = 0;i < n;i++){
		Dist[i] = INF;
		if(Pair[i] == NIL){
			Dist[i] = 0;
			Q.push(i);
		}
	}
	Dist[NIL] = INF;
	for(;!Q.empty();Q.pop()){
		int u = Q.front();
		if(Dist[u] < Dist[NIL]){
			for(int v : Adj[u]){
				if(Dist[Pair[v]] == INF){
					Dist[Pair[v]] = Dist[u] + 1;
					Q.push(Pair[v]);
				}
			}
		}
	}
	return Dist[NIL] != INF;
}

bool DFS(int u){
	if(u != NIL){
		for(int v : Adj[u]){
			if(Dist[Pair[v]] == Dist[u] + 1){
				if(DFS(Pair[v])){
					Pair[v] = u;
					Pair[u] = v;
					return 1;
				}
			}
		}
		Dist[u] = INF;
		return 0;
	}
	return 1;
}

int Hopcroft_Karp(){
	for(int i = 0;i <= n + m;i++)
		Pair[i] = NIL;
	int matching = 0;
	for(;BFS();){
		for(int i = 0;i < n;i++){
			if(Pair[i] == NIL)
				matching += DFS(i);
		}
	}
	return matching;
}

int main(){
	memset(dis, INF, sizeof(INF));
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++){
		int x, y; scanf("%d%d", &x, &y);
		dis[x][y] = 1; dis[y][x] = 1;
	}
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	scanf("%d%d%d%d", &n, &m, &k, &f);
	NIL = n + m;
	for(int i = 0;i < n;i++)
		scanf("%d%d%d", LOC_A + i, ATK + i, FUL + i);
	for(int i = 0;i < m;i++)
		scanf("%d%d", LOC_D + i, DEF + i);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(ATK[i] >= DEF[j] && dis[LOC_A[i]][LOC_D[j]] <= FUL[i])
				Adj[i].PB(j + n), Adj[j + n].PB(i);
		}
	}
	int kol = Hopcroft_Karp();
	//printf("%d\n", kol);
	ll ans = (ll)kol * k;
	for(int j = 0;j < kol;j++){
		ans = min(ans, (ll)j * k + (ll)(n - j) * f);
	}	
	printf("%lld\n", ans);
	return 0;
}
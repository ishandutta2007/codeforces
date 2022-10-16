#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

const int N = 4e5 + 500;
const int LOG = 19;
const int INF = 0x3f3f3f3f;

int n, k, r, dis[N], dep[N], sm[N];
int par[N][LOG], odm[N];
vector < int > v[N];

void dfs(int x,int lst){
	dep[x] = dep[lst] + 1; par[x][0] = lst;
	sm[x] = sm[lst] + (dis[x] <= (r - 1) / 2);
	for(int nxt : v[x])
		if(nxt != lst) dfs(nxt, x);
}

void compute(){
	for(int j = 1;j < LOG;j++)
		for(int i = 1;i <= n;i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = LOG - 1;i >= 0;i--)
		if(dep[x] - (1 << i) >= dep[y])
			x = par[x][i];
	if(x == y) return x;
	for(int i = LOG - 1;i >= 0;i--)
		if(par[x][i] != par[y][i])
			x = par[x][i],
			y = par[y][i];
	return par[x][0];
}

inline int get_dis(int x,int y,int lc = -1){
	if(lc == -1) lc = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[lc];
}

inline int get_sum(int x,int y,int lc = -1){
	if(lc == -1) lc = lca(x, y);
	return sm[x] + sm[y] - 2 * sm[lc] + (dis[lc] <= (r - 1) / 2);
}

int get_kti(int x, int y,int k){
	int lc = lca(x, y);
	//printf("%d-ti na putu od %d do %d je ... ", k, x, y);
	if(get_dis(x, lc, lc) < k){
		swap(x, y); k = get_dis(x, y, lc) - k;
	}
	for(int i = LOG - 1;i >= 0;i--)
		if((1 << i) & k) x = par[x][i];	
	//printf("%d\n", x);
	return x;
}

void bfs(){
	memset(dis, -1, sizeof(dis));
	queue < int > st;
	for(int i = 1;i <= n;i++){
		if(!odm[i]) continue;
		st.push(i); dis[i] = 0;
	}
	for(;!st.empty();){
		int cur = st.front();
		st.pop();
		for(int nxt : v[cur]){
			if(dis[nxt] != -1) continue;
			dis[nxt] = dis[cur] + 1;
			st.push(nxt); 
		}	
	}
}

int main(){
	scanf("%d%d%d", &n, &r, &k);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		if(r & 1)
			v[x].PB(y), v[y].PB(x);
		else
			v[x].PB(n + i), v[n + i].PB(y),
			v[y].PB(n + i), v[n + i].PB(x);
	}
	if(!(r & 1)){
		n = 2 * n - 1;
		r = 2 * r + 1;
	}
	for(int i = 0;i < k;i++){
		int x; scanf("%d", &x); odm[x] = 1;
	}
	bfs(); dfs(1, 1); compute();
	//printf("%d %d %d\n", sm[1], sm[2], sm[4]);
	int q; scanf("%d", &q);
	for(int i = 0;i < q;i++){
		int x, y; scanf("%d%d", &x, &y);
		if(get_dis(x, y) <= r){
			printf("YES\n"); continue;
		}
		int xx = get_kti(x, y, (r - 1) / 2 + 1);
		int yy = get_kti(y, x, (r + 1) / 2);
		//printf("x %d xx %d yy %d y %d\n", x, xx, yy, y);
		//printf("dis %d suma %d\n", get_dis(xx, yy), get_sum(xx, yy));
		if(get_dis(xx, yy) + 1 == get_sum(xx, yy))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
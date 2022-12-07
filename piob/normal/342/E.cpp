#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int MAXN = 100010;

VI edges[MAXN];
bool taken[MAXN];
int size[MAXN];

int jump[MAXN];
int depth[MAXN];
int dist[20][MAXN];

void update_size(int u){
	taken[u] = 1;
	size[u] = 1;
	for(int v : edges[u]) if(!taken[v]){
		update_size(v);
		size[u] += size[v];
	}
	taken[u] = 0;
}

PII centroid(int u, int n){
	taken[u] = 1;
	PII r = PII(n-size[u], u);
	for(int v : edges[u]) if(!taken[v]) r.st = max(r.st, size[v]);
	for(int v : edges[u]) if(!taken[v]) r = min(r, centroid(v, n));
	taken[u] = 0;
	return r;
}

void fill_dist(int u, int d, int layer){
	taken[u] = 1;
	dist[layer][u] = d;
	for(int v : edges[u]) if(!taken[v]) fill_dist(v, d+1, layer);
	taken[u] = 0;	
}

void decompose(int u, int p, int layer){
	update_size(u);
	int n = size[u];
	u = centroid(u, n).nd;
	jump[u] = p;
	depth[u] = layer;
	fill_dist(u, 0, layer);
	taken[u] = 1;
	for(int v : edges[u]) if(!taken[v]) decompose(v, u, layer+1);
}

int res[MAXN];
int n, q;

void update(int u){
	int p = u, d = depth[u];
	while(p){
		res[p] = min(res[p], dist[d][u]);
		p = jump[p];
		--d;
	}
}

int query(int u){
	int r = n+1;
	int p = u, d = depth[u];
	while(p){
		r = min(r, res[p] + dist[d][u]);
		p = jump[p];
		--d;
	}
	return r;
}

int main(){
	scanf("%d %d", &n, &q);
	FWD(i,1,n+1) res[i] = n+1;
	FWD(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	decompose(1, 0, 0);
	update(1);
	FWD(i,0,q){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1) update(b);
		if(a == 2) printf("%d\n", query(b));
	}
	return 0;
}
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

const int mod = 1000000007;
const K eps = 1e-15;

struct edge{
	int u, v, w;
};

int n, m;
LL s;
bool vis[200010];
edge edges[200010];
vector<int> out[200010];
PII jmp[200010][19];
int ord[200010];
int rep[200010];
int depth[200010];

int find(int u){
	return rep[u] == u ? u : rep[u] = find(rep[u]);
}

bool cmp(int a, int b){
	return edges[a].w < edges[b].w;
}

int other(int i, int u){
	return edges[i].u == u ? edges[i].v : edges[i].u;
}

void dfs(int u){
	vis[u] = 1;
	for(int i : out[u]){
		int v = other(i, u);
		if(vis[v]) continue;
		jmp[v][0] = PII(u, edges[i].w);
		depth[v] = depth[u] + 1;
		dfs(v);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,1,n+1) rep[i] = i;
	FWD(i,0,m){
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		ord[i] = i;
	}
	sort(ord, ord+m, cmp);
	FWD(_i,0,m){
		int i = ord[_i];
		edge e = edges[i];
		if(find(e.u) != find(e.v)){
			s += e.w;
			out[e.u].push_back(i);
			out[e.v].push_back(i);
			rep[rep[e.u]] = rep[e.v];
		}
	}
	depth[1] = 1;
	dfs(1);
	FWD(d,1,19) FWD(u,1,n+1){
		int v = jmp[u][d-1].st;
		jmp[u][d] = PII(jmp[v][d-1].st, max(jmp[u][d-1].nd, jmp[v][d-1].nd));
	}
	FWD(i,0,m){
		int t = 0;
		int u = edges[i].u;
		int v = edges[i].v;
		FWD(r,0,2){
			int d = 18;
			while(depth[u] > depth[v]){
				while(depth[jmp[u][d].st] < depth[v]) --d;
				t = max(t, jmp[u][d].nd);
				u = jmp[u][d].st;
			}
			swap(u, v);
		}
		BCK(d,18,-1){
			if(jmp[u][d].st != jmp[v][d].st){
				t = max(t, max(jmp[u][d].nd, jmp[v][d].nd));
				u = jmp[u][d].st;
				v = jmp[v][d].st;
			}
		}
		if(u != v)
			t = max(t, max(jmp[u][0].nd, jmp[v][0].nd));
		printf("%I64d\n", s - t + edges[i].w);
	}
	return 0;
}
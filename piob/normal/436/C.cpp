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

int n, m, k, w;

vector<pair<int, PII>> edges;
char lvl[1010][13][13];
int repr[1010];

int find(int u){
	return u == repr[u] ? u : repr[u] = find(repr[u]);
}

vector<int> E[1010];

void dfs(int u){
	repr[u] = -1;
	for(int v : E[u]) if(repr[v] != -1){
		printf("%d %d\n", v, u);
		dfs(v);
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &w);
	FWD(i,1,k+1){
		repr[i] = i;
		FWD(a,0,n) scanf("%s", lvl[i][a]);
		edges.push_back(make_pair(n*m, PII(0, i)));
		//printf("%d - %d = %d %d\n", 0, i, n*m, n*m);
		FWD(j,1,i){
			int c = 0;
			FWD(a,0,n) FWD(b,0,m)
				if(lvl[i][a][b] != lvl[j][a][b])
					++c;
			//printf("%d - %d = %d %d\n", i, j, c, c*w);
			edges.push_back(make_pair(c*w, PII(j, i)));	
		}
	}
	sort(ALL(edges));
	int cost = 0;
	for(pair<int, PII> e : edges){
		int u = e.nd.st;
		int v = e.nd.nd;
		if(find(u) != find(v)){
			cost += e.st;
			E[u].push_back(v);
			E[v].push_back(u);
			repr[find(u)] = find(v);
		}
	}
	printf("%d\n", cost);
	dfs(0);
	return 0;
}
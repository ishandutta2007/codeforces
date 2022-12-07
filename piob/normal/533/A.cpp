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

const int MAXN = 500010;
const int INF = 1000000010;

int n, k, m, d;
int tree_val[2*512*1024];
int tree_mod[2*512*1024];
int height[MAXN];
int eff[MAXN];
int cur[MAXN];
int parent[MAXN];
vector<int> edges[MAXN];
int miner[MAXN];
vector<int> roots;
vector<int> got;

void set_val(int x, int y){
	x += d;
	tree_val[x] = y;
	x /= 2;
	while(x){
		tree_val[x] = min(tree_val[2*x], tree_val[2*x+1]);
		x /= 2;
	}
}

void tree_add_val(int u, int lo, int hi, int x, int y, int c){
	if(y < lo || hi < x) return;
	if(x <= lo && hi <= y){
		tree_val[u] += c;
		tree_mod[u] += c;
		return;
	}
	tree_add_val(2*u, lo, (lo+hi)/2, x, y, c);
	tree_add_val(2*u+1, (lo+hi)/2+1, hi, x, y, c);
	tree_val[u] = min(tree_val[2*u], tree_val[2*u+1]) + tree_mod[u];
}

void add_val(int x, int y, int c){
	tree_add_val(1, 0, d-1, x, y-1, c);
}

int get_min(){
	return tree_val[1];
}

void dfs_eff(int u){
	got.push_back(eff[u]);
	for(int v : edges[u]) if(parent[u] != v){
		parent[v] = u;
		eff[v] = min(eff[u], height[v]);
		dfs_eff(v);
	}
}

int get_satisifed(int h){
	return (int)(upper_bound(miner, miner+m, h) - miner);
}

void perform(int u){
	//printf("p %d\n", u);
	int g = get_satisifed(eff[u]);
	//printf("	dawalo %d\n", g);
	add_val(0, g, -1);
	g = get_satisifed(cur[u]);
	//printf("	daje %d\n", g);
	//printf("zmiana %d -> %d\n", eff[u], cur[u]);
	add_val(0, g, 1);
	for(int v : edges[u]) if(parent[u] != v){
		parent[v] = u;
		cur[v] = min(cur[u], height[v]);
		perform(v);
	}
}

void unwind(int u){
	int g = get_satisifed(eff[u]);
	add_val(0, g, 1);
	g = get_satisifed(cur[u]);
	add_val(0, g, -1);
	for(int v : edges[u]) if(parent[u] != v){
		parent[v] = u;
		unwind(v);
	}
}

int solve(){
	priority_queue<PII> Q;
	eff[1] = height[1];
	Q.push(PII(eff[1], 1));
	m = k;
	while(m){
		int u = Q.top().nd;
		if(eff[u] < miner[m-1]){
			//printf("nie miesci sie %d\n", miner[m-1]);
			while(!Q.empty()){
				u = Q.top().nd;
				Q.pop();
				roots.push_back(u);
				dfs_eff(u);
			}
			sort(got.begin(), got.end());
			d = 1;
			while(d < m) d *= 2;
			int skip = 0;
			FWD(i,0,m){
				while(skip < SIZE(got) && got[skip] < miner[i]){
					++skip;
				}
				//printf("komnat dla %d mam %d\n", miner[i], SIZE(got)-skip);
				set_val(i, SIZE(got)-skip-(m-i));
			}
			FWD(i,0,SIZE(roots)){
				u = roots[i];
				//printf("root proboje %d (%d/%d)\n", u, i, SIZE(roots));
				cur[u] = miner[m-1];
				perform(u);
				if(get_min() >= 0)
					return miner[m-1] - height[u];
				unwind(u);
			}
			return -1;
		}
		Q.pop();
		--m;
		for(int v : edges[u]) if(parent[u] != v){
			parent[v] = u;
			eff[v] = min(eff[u], height[v]);
			Q.push(PII(eff[v], v));
		}
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1) scanf("%d", &height[i]);
	FWD(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	scanf("%d", &k);
	FWD(i,0,k) scanf("%d", &miner[i]);
	sort(miner, miner+k);
	printf("%d\n", solve());
	return 0;
}
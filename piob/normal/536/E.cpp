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

int F[MAXN];

struct path{
	int pref, total, suf, len;
	path() : pref(0), total(0), suf(0), len(1) {}
	path(int a, int b, int c, int d) : pref(a), total(b), suf(c), len(d) {}
	path(int a) : pref(a), total(0), suf(a), len(a) {}
};

path merge(path a, path b){
	if(a.pref == a.len && b.pref == b.len) return path(a.len+b.len);
	if(a.pref == a.len) return path(a.pref + b.pref, b.total, b.suf, a.len + b.len);
	if(b.pref == b.len) return path(a.pref, a.total, a.suf + b.pref, a.len + b.len);
	return path(a.pref, a.total + F[a.suf + b.pref] + b.total, b.suf, a.len + b.len);
}

path reverse(path a){
	return path(a.suf, a.total, a.pref, a.len);
}

int eval(path a){
	if(a.pref == a.len) return F[a.len];
	return F[a.pref] + a.total + F[a.suf];
}

struct tree{
	int n, d;
	vector<path> data;
	tree() : n(0) {}
	void init(){
		d = 1;
		while(d < n) d *= 2;
		data.resize(2*d);
	}
	void lit(int x){
		x += d;
		data[x] = path(1);
		x /= 2;
		while(x){
			data[x] = merge(data[2*x], data[2*x+1]);
			x /= 2;
		}
	}
	path get(int a, int b){
		assert(max(a, b) < n);
		a += d; b += d;
		path pref(0), suf(0);
		while(a < b){
			if(a&1){
				pref = merge(pref, data[a]);
				++a;
			}
			if((b&1)==0){
				suf = merge(data[b], suf);
				--b;
			}
			a /= 2;
			b /= 2;
		}
		if(a == b) pref = merge(pref, data[a]);
		return merge(pref, suf);
	}
};

int I[MAXN];
int J[MAXN];
int R[MAXN];
vector<tree> HLD;

vector<PII> edges[MAXN]; 
bool vis[MAXN];
int size[MAXN];
int depth[MAXN];
PII parent[MAXN];

void dfs(int u){
	vis[u] = 1;
	size[u] = 1;
	int b = -1;
	for(PII e : edges[u]) if(!vis[e.st]){
		parent[e.st] = PII(u, e.nd);
		depth[e.st] = depth[u] + 1;
		dfs(e.st);
		size[u] += size[e.st];
		if(b == -1 || size[b] < size[e.st]) b = e.st;
	}
	if(b == -1){
		I[u] = SIZE(HLD);
		HLD.push_back(tree());
	}else
		I[u] = I[b];
	R[I[u]] = u;
	++HLD[I[u]].n;
	vis[u] = 0;
}

vector<PII> mods;

void init(int u){
	vis[u] = 1;
	if(R[I[u]] == u){
		J[u] = 0;
		HLD[I[u]].init();
	}else
		J[u] = J[parent[u].st] + 1;
	if(u > 1)
		mods.push_back(PII(parent[u].nd, u));
	for(PII e : edges[u]) if(!vis[e.st])
		init(e.st);
	vis[u] = 0;
}

int n, q;
vector<PII> queries;

int A[MAXN], B[MAXN];
int res[MAXN];

int main(){
	scanf("%d %d", &n, &q);
	FWD(i,1,n) scanf("%d", &F[i]);
	FWD(i,1,n){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(PII(b, c));
		edges[b].push_back(PII(a, c));
	}
	dfs(1);
	init(1);
	FWD(i,0,q){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		A[i] = a;
		B[i] = b;
		queries.push_back(PII(c, i));
	}
	sort(ALL(mods), greater<PII>());
	sort(ALL(queries), greater<PII>());
	q = 0;
	int m = 0;
	while(q < SIZE(queries)){
		while(m < SIZE(mods) && mods[m].st >= queries[q].st){
			int u = mods[m].nd;
			HLD[I[u]].lit(J[u]);
			++m;
		}
		int u = B[queries[q].nd];
		int v = A[queries[q].nd];
		path tu, tv;
		while(I[u] != I[v]){
			if(depth[R[I[u]]] > depth[R[I[v]]]){
				tu = merge(HLD[I[u]].get(0, J[u]), tu);
				u = parent[R[I[u]]].st;
			}else{
				tv = merge(HLD[I[v]].get(0, J[v]), tv);
				v = parent[R[I[v]]].st;
			}
		}
		if(J[u] < J[v]){
			tu = merge(reverse(tu), HLD[I[u]].get(J[u]+1, J[v]));
			tu = merge(tu, tv);
		}else{
			tv = merge(reverse(tv), HLD[I[u]].get(J[v]+1, J[u]));
			tu = merge(tv, tu);
		}
		res[queries[q].nd] = eval(tu);
		++q;
	}
	FWD(i,0,q) printf("%d\n", res[i]);
	return 0;
}
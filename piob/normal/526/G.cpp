#define DEBUG if(0)
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
const int MAXL = 128*1024+3;
const int MAXD = 2*128*1024+3;

int n;
vector<PII> E[MAXN];

int *mrank;

bool cmp_rank(int a, int b){
	return mrank[a] > mrank[b];
}

struct rooted_tree {
	int k;
	int P[MAXN], W[MAXN];
	int L[MAXN], S[MAXN], J[MAXN], T[MAXN];
	int R[MAXN], PS[MAXN];
	int dfs(int u){
		int p = u; T[u] = 0;
		for(PII e : E[u]) if(P[u] != e.st){
			P[e.st] = u; W[e.st] = e.nd;
			int c = dfs(e.st);
			J[c] = u; T[c] += e.nd;
			if(T[c] > T[p]) p = c;
		}
		L[u] = p;
		S[u] = T[p];
		return p;
	}
	void init(int u){
		P[u] = 0;
		W[u] = 0;
		dfs(u);
		vector<int> paths;
		FWD(i,1,n+1) if(L[i] == i) paths.push_back(i);
		mrank = T;
		sort(ALL(paths), cmp_rank);
		k = SIZE(paths);
		PS[0] = 0;
		FWD(i,0,k){
			R[paths[i]] = i;
			PS[i+1] = PS[i] + T[paths[i]];
		}
	}
	int get_ans(int x, int y){
		y = min(2*y-1, k);
DEBUG printf("%d %d\n", x, y);
		x = L[x];
		if(R[x] < y) return PS[y];
		int tx = 0;
		while(R[L[x]] >= y){
			tx += T[L[x]] - S[x];
			x = J[L[x]];
		}
		return max(
			PS[y-1] + tx,
			PS[y] - S[x] + tx
		);
	}
} A, B;

int V[MAXN];

PII dfs(int u){
	V[u] = 1;
	PII res = PII(0, u);
	for(PII e : E[u]) if(!V[e.st]){
		PII can = dfs(e.st);
		can.st += e.nd;
		res = max(res, can);
	}
	return res;
}

int main(){
	int q;
	scanf("%d %d", &n, &q);
	FWD(i,1,n){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		E[a].push_back(PII(b,c));
		E[b].push_back(PII(a,c));
	}
	int a = dfs(1).nd;
	FWD(i,1,n+1) V[i] = 0;
	int b = dfs(a).nd;
	A.init(a);
	B.init(b);
	int ans = 0;
	FWD(i,0,q){
		int x, y;
		scanf("%d %d", &x, &y);
		x = (x+ans-1)%n + 1;
		y = (y+ans-1)%n + 1;
DEBUG printf("xy: %d %d\n", x, y);
		ans = max(A.get_ans(x, y), B.get_ans(x, y));
		printf("%d\n", ans);
	}
	return 0;
}
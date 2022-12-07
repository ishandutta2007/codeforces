#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;
typedef tuple<int, int, int> III;

const int mod = 1000000007;
const int INF = 1000000000;

struct point{
	int i, x, y;
	void operator-=(point b){
		x -= b.x; y -= b.y;
	}
};

bool cmp_ang(point a, point b){
	return (LL)a.x*b.y < (LL)a.y*b.x;
}

bool cmp_lex(point a, point b){
	return PII(a.x, a.y) < PII(b.x, b.y);;
}

int n;
int P[1501];
int S[1501];
vector<int> E[1501];
int R[1501];

int dfs(int u){
	S[u] = 1;
	for(int v : E[u]) if(P[u] != v){
		P[v] = u;
		S[u] += dfs(v);
	}
	return S[u];
}

void assign(int u, point X[]){
	swap(X[0], *min_element(X, X+S[u], cmp_lex));
	R[X[0].i] = u;
	FWD(i,1,S[u]) X[i] -= X[0];
	sort(X+1, X+S[u], cmp_ang);
	++X;
	for(int v : E[u]) if(P[u] != v) {
		assign(v, X);
		X += S[v];
	}
}

point X[1501];

int main(){
	scanf("%d", &n);
	FWD(i,1,n){
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(1);
	FWD(i,0,n){
		scanf("%d %d", &X[i].x, &X[i].y);
		X[i].i = i;
	}
	assign(1, X);
	FWD(i,0,n) printf("%d ", R[i]);
	printf("\n");
	return 0;
}
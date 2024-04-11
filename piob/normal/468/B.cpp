#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

namespace sat {
int n;
const int N = 200010;
vector<int> g[N];
int t, in[N], low[N];
vector<int> s;
bool stacked[N];
int scc[N], scc_n;
bool value[N];

void tarjan(int u) {
	low[u] = in[u] = t++;
	s.push_back(u);
	stacked[u] = true;
	for(int v : g[u]) {
		if (in[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (stacked[v]) low[u] = min(low[u], in[v]);
	}
	if (low[u]==in[u]) {
		for(;;) {
			int v = s.back(); s.pop_back();
			stacked[v] = false;
			scc[v] = scc_n;
			if (v==u) break;
		}
		scc_n++;
	}
}

void tarjan_scc() {
	REP(i,n) { in[i] = low[i] = -1; stacked[i] = false; }
	scc_n = t = 0;
	REP(i,n) if(in[i] == -1) tarjan(i);
}

void add_constr(int a, bool neg_a, int b, bool neg_b) {
	g[2*a+neg_a].push_back(2*b+1-neg_b);
	g[2*b+neg_b].push_back(2*a+1-neg_a);
}

bool solve_2sat() {
	tarjan_scc();
	int v[scc_n], c[scc_n];
	REP(i,(n/2)) if (scc[2*i] == scc[2*i+1]) return false;
	REP(i,n) v[scc[i]] = i;
	REP(i,scc_n) c[i] = -1;
	REP(i,scc_n) if (c[i] == -1) {
		c[i] = 1;
		c[scc[v[i]^1]] = 0;
	}
	REP(i,(n/2)) value[i] = c[scc[2*i+1]];
	return true;
}
}

int n, a, b;
map<int, int> I;
int T[100010];

int main(){
	scanf("%d %d %d", &n, &a, &b);
	sat::n = 2*n;
	FWD(i,0,n){
		scanf("%d", &T[i]);
		I[T[i]] = i;
	}
	FWD(i,0,n){
		int p = T[i];
		int ap = a-p;
		int bp = b-p;
		if(I.find(ap) == I.end())
			sat::add_constr(i,1,i,1);
		else
			sat::add_constr(i,1,I[ap],0);
		if(I.find(bp) == I.end())
			sat::add_constr(i,0,i,0);
		else
			sat::add_constr(i,0,I[bp],1);
	}
	if(sat::solve_2sat()){
		printf("YES\n");
		FWD(i,0,n) printf("%d ", 1-(int)sat::value[i]);
		printf("\n");
	}else
		printf("NO\n");
	return 0;
}
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;

const int N = 3e5 + 500;
const int OFF = (1 << 19);
const int LOG = 19;

struct node{
	node *L, *R;
	ll val;
	node(node* _L, node* _R, ll _val){
		L = _L, R = _R, val = _val;
	}
};

typedef node* pnode;

pnode L(pnode x) { return x ? x -> L : 0; }
pnode R(pnode x) { return x ? x -> R : 0; }
ll val(pnode x) { return x ? x -> val : 0; }

pnode root[N];
int n, q;
vector < int > v[N], obr[N];
int tL[N], tR[N], par[N][LOG], tme, dep[N], A[N];
ll kod[N];

void update(pnode &x, int a, int b, int wnt, ll nw){
	x = new node(L(x), R(x), val(x));
	x -> val ^= nw;
	if(a == b) return;
	if(wnt <= (a + b) / 2)
		update(x -> L, a, (a + b) / 2, wnt, nw);
	else
		update(x -> R, (a + b) / 2 + 1, b, wnt, nw);
}

ll query(pnode x, int a, int b, int lo, int hi){
	if(!x) return 0;
	if(lo <= a && b <= hi) return val(x);
	if(a > hi || b < lo) return 0;
	return query(x -> L, a, (a + b) / 2, lo, hi) ^ query(x -> R, (a + b) / 2 + 1, b, lo, hi);
}

void dfs(int x, int lst){
	dep[x] = dep[lst] + 1;
	root[x] = root[lst];
	update(root[x], 0, OFF - 1, A[x], kod[A[x]]);
	par[x][0] = lst;
	for(int y : v[x])
		if(y != lst)
			dfs(y, x);	
}

void precompute(){
	for(int j = 1;j < LOG;j++){
		for(int i = 1;i <= n;i++){
			par[i][j] = par[par[i][j - 1]][j - 1];
		}	
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int j = LOG - 1;j >= 0;j--)
		if(dep[x] - dep[y] >= (1 << j))
			x = par[x][j];
	if(x == y) return x;
	for(int j = LOG - 1;j >= 0;j--)
		if(par[x][j] != par[y][j])
			x = par[x][j], y = par[y][j];
	return par[x][0];
}

int solve(pnode x, pnode y, int a, int b, int lo, int hi, int lc){
	if(a > hi || b < lo) return -1;
	ll trg = kod[A[lc]] * (a <= A[lc] && A[lc] <= b); 
	if((val(x) ^ val(y) ^ trg) == 0) return -1;	
	if(a == b) return a;
	int lft = solve(L(x), L(y), a, (a + b) / 2, lo, hi, lc);
	if(lft != -1) return lft;
	return solve(R(x), R(y), (a + b) / 2 + 1, b, lo, hi, lc);
}


int main(){
	srand(time(NULL));
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++)
		scanf("%d", A + i), obr[A[i]].PB(i);
	for(int i = 1;i < n;i++){
		int x, y; scanf("%d%d", &x, &y);
		v[x].PB(y), v[y].PB(x);
	}
	for(int i = 1;i <= n;i++){
		kod[i] = (ll)rand() + ((ll)rand() << 16) + ((ll)rand() << 32) + ((ll)rand() << 48);
	}
	dfs(1, 1); precompute();
	for(int i = 0;i < q;i++){
		int a, b, l, r; scanf("%d%d%d%d", &a, &b, &l, &r);
		int lc = lca(a, b); 
		printf("%d\n", solve(root[a], root[b], 0, OFF - 1, l, r, lc));
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef pair < int, int > pii;

const int N = 1e5 + 500;
const int OFF = (1 << 17);
const int INF = 0x3f3f3f3f;

int L[N], R[N], tme;
pii T[2 * OFF];
int prop[2 * OFF];
int A[N], B[N], ans[N];
int n, q;
vector < int > Q[N], v[N];

void dfs(int x, int lst){
	L[x] = tme++;
	for(int y : v[x])
		if(lst != y)
			dfs(y, x);
	R[x] = tme - 1;
}

pii mrg(pii A, pii B){
	if(A.X == B.X)
		return {A.X, A.Y + B.Y};
	return min(A, B);
}

inline void refresh(int x){
	if(!prop[x]) return;
	T[x].X += prop[x];
	if(x < OFF){
		prop[2 * x] += prop[x];
		prop[2 * x + 1] += prop[x];
	}
	prop[x] = 0;
}

void update(int i, int a, int b, int lo, int hi, int x){
	refresh(i);
	if(lo <= a && b <= hi){
		prop[i] += x; refresh(i);
		return;
	}
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi, x);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
	T[i] = mrg(T[2 * i], T[2 * i + 1]);
}

inline int get_ans(){
	if(T[1].X != 0)
		return n;
	return n - T[1].Y;
}

inline void odradi(int i, int x){
	update(1, 0, OFF - 1, L[A[i]], R[A[i]], x);
	update(1, 0, OFF - 1, L[B[i]], R[B[i]], x);	
}

void solve(int x, int lst){
	for(int c : Q[x])
		odradi(c, 1);
	ans[x] = max(get_ans() - 1, 0);
	for(int y : v[x])
		if(y != lst)
			solve(y, x);
	for(int c : Q[x])
		odradi(c, -1);	
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i < n;i++){
		int a, b; scanf("%d%d", &a, &b);
		v[a].PB(b), v[b].PB(a);
	}
	for(int i = 0;i < q;i++){
		scanf("%d%d", A + i, B + i);
		Q[A[i]].PB(i), Q[B[i]].PB(i);
	}
	for(int i = 0;i < OFF;i++){
		if(i < n)
			T[OFF + i] = {0, 1};
		else
			T[OFF + i] = {INF, 0};
	}
	for(int i = OFF - 1; i ; i--)
		T[i] = mrg(T[2 * i], T[2 * i + 1]);
	dfs(1, 1); solve(1, 1);
	for(int i = 1;i <= n;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
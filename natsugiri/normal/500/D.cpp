#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

typedef vector<vector<int> > Adj;
int N, Q;
Adj G;
int A[100011], B[100011], W[100011];

int depth[100011], subsize[100011];
void dfs(int v, int p) {
    subsize[v] = 1;
    REP (i, G[v].size()) {
	int w = G[v][i];
	if (w == p) continue;
	depth[w] = depth[v]+1;
	dfs(w, v);
	subsize[v] += subsize[w];
    }
}

double D, BASE;
double tri(int n) {
    return n * (n-1.0) / 2.0;
}
void add(int v, int w) {
    D += 2.0 * subsize[v] * tri(N-subsize[v]) * w / BASE;    
    D += 2.0 * tri(subsize[v]) * (N-subsize[v]) * w / BASE;
}

int main() {
    scanf("%d", &N);
    G = Adj(N);
    REP (i, N-1) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	A[i] = x; B[i] = y; W[i] = w;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(0, -1);
    D = 0.0;
    BASE = N * (N-1.0) * (N-2.0) / 6.0;
    
    REP (i, N-1) {
	if (depth[A[i]] > depth[B[i]]) swap(A[i], B[i]);
	add(B[i], W[i]);
    }
    
    scanf("%d", &Q);
    REP ($, Q) {
	int r, w;
	scanf("%d%d", &r, &w);
	r--;
	add(B[r], -W[r]);
	add(B[r], w);
	W[r] = w;
	printf("%.10f\n", D);
    }
    return 0;
}
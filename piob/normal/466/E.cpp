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
typedef pair<LL, LL> PII;
typedef double K;
typedef vector<int> VI;

const int mod = 1000000007;

const int MAXN = 100010;

int R[MAXN];
int find(int u){ return u==R[u]?u:R[u]=find(R[u]); }

int n, m, t, p;
int pre[MAXN];
int post[MAXN];
int boss[MAXN];
vector<int> child[MAXN];

int T[MAXN];
int A[MAXN];
int B[MAXN];
vector<PII> Z[MAXN];

int W[MAXN];

void dfs(int u){
	pre[u] = ++t;
	for(int v : child[u]) dfs(v);
	post[u] = ++t;
}

bool ancestor(int u, int v){
	return pre[u] <= pre[v] && post[v] <= post[u];
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int t, a, b;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &a, &b);
			child[b].push_back(a);
			boss[a] = b;
		}
		if(t == 2)
			scanf("%d", &a);
		if(t == 3){
			scanf("%d %d", &a, &b);
			Z[b].push_back(PII(a, i));
		}
		T[i] = t; A[i] = a; B[i] = b;
	}
	FWD(i,1,n+1) R[i] = i;
	FWD(i,1,n+1) if(pre[i] == 0){
		int b = i;
		while(boss[b]) b = boss[b];
		dfs(b);
	}
	FWD(i,0,m){
		if(T[i] == 1)
			R[find(A[i])] = find(B[i]);
		if(T[i] == 2){
			++p;
			for(auto q : Z[p])
				A[q.y] = ancestor(q.x, A[i]) && find(q.x) == find(A[i]);
		}
		if(T[i] == 3)
			printf(A[i]?"YES\n":"NO\n");
	}
	return 0;
}
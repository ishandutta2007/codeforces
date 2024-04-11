#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100010;
const int MAXV = 2000010;

int n, q;
int P[MAXV];
vector<PII> D[MAXV];
int W[MAXN];
int R[MAXN];
vector<int> E[MAXN];
bool V[MAXN];

void dfs(int u, int d=0){
	int x = W[u];
	int g = -1;
	while(x > 1){
		int y = P[x];
		while(x%y == 0) x /= y;
		if(!D[y].empty())
			if(D[y].back().y > g){
				g = D[y].back().y;
				R[u] = D[y].back().x;
			}
		D[y].push_back(PII(u,d));
	}
	V[u] = 1;
	for(int v : E[u])
		if(!V[v])
			dfs(v, d+1);
	x = W[u];
	while(x > 1){
		int y = P[x];
		while(x%y == 0) x /= y;
		D[y].pop_back();
	}
}

void przelicz(){
	FWD(i,1,n+1) V[i]=0, R[i]=-1;
	dfs(1);
}

int main(){
	for(int i=2; i*i<2000010; ++i)
		if(P[i] == 0)
			for(int j=i*i; j<2000010; j+=i)
				P[j] = i;
	FWD(i,2,2000010)
		if(P[i] == 0)
			P[i] = i;
	scanf("%d %d", &n, &q);
	FWD(i,1,n+1) scanf("%d", &W[i]);
	FWD(i,1,n){
		int u, v;
		scanf("%d %d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	przelicz();
	FWD(i,0,q){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int u;
			scanf("%d", &u);
			printf("%d\n", R[u]);
		}
		if(t == 2){
			int u, w;
			scanf("%d %d", &u, &w);
			W[u] = w;
			przelicz();
		}
	}
	return 0;
}
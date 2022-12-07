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
typedef pair<LL, int> PLI;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int MAXN = 100010;
const LL INF = 1000000000LL * 1000000000LL;

int n, m, k, r;
LL dist[MAXN];
int vis[MAXN];
int parent[MAXN];
bool train[MAXN];
vector<int> childs[MAXN];
vector<PII> edges[MAXN];
priority_queue<PLI> Q;

int main(){
	scanf("%d %d %d", &n, &m, &k);
	FWD(i,1,n+1) dist[i] = INF;
	FWD(i,0,m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[a].push_back(PII(b,c));
		edges[b].push_back(PII(a,c));
	}
	FWD(i,0,k){
		int b, c;
		scanf("%d %d", &b, &c);
		if(dist[b] != INF) ++r;
		dist[b] = min(dist[b], (LL)c);
		train[b] = 1;
	}
	dist[1] = 0;
	FWD(i,1,n+1)
		if(dist[i] != INF)
			Q.push(PII(-dist[i],i));
	while(!Q.empty()){
		int u = Q.top().y;
		LL d = -Q.top().x;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		dist[u] = d;
		for(PII e : edges[u])
			if(d+e.y <= dist[e.x]){
				if(train[e.x]){
					++r;
					train[e.x] = 0;
				}
				Q.push(PII(-d-e.y, e.x));
			}
	}
	printf("%d\n", r);
}
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

const LL INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int N = 2010;

int n;
vector<PII> E[N];
vector<pair<int, PII> > edges;
int M[N][N];
int R[N];
LL dist[N];

int find(int u){
	return R[u] == u ? u : R[u] = find(R[u]);
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		FWD(j,0,n){
			scanf("%d", &M[i][j]);
			edges.push_back(make_pair(M[i][j], PII(i,j)));
		}
	}
	FWD(i,0,n) R[i] = i;
	sort(edges.begin(), edges.end());
	for(auto e : edges){
		int c = e.x;
		int a = e.y.x;
		int b = e.y.y;
		if(c && find(a) != find(b)){
			R[find(a)] = find(b);
			E[a].push_back(PII(b,c));
			E[b].push_back(PII(a,c));
		}
	}
	FWD(i,0,n){
		FWD(j,0,n) dist[j] = INF;
		dist[i] = 0;
		queue<int> Q;
		Q.push(i);
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			for(auto e : E[u])
				if(dist[e.x] > dist[u] + e.y){
					dist[e.x] = dist[u] + e.y;
					Q.push(e.x);
				}
		}
		FWD(j,0,n) if(M[i][j] != dist[j]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
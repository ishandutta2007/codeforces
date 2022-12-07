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

const int INF = 1000000010;

int n, m, k;
vector<int> edges[1010];
int color[1010];
int cc[1010];
int D[1010][1010];
int dist[1010];
int res[1010];
queue<int> Q;

bool odd_cycle(int u){
	cc[u] = k;
	for(int v : edges[u]){
		if(color[v] == 0){
			color[v] = 3 - color[u];
			if(odd_cycle(v))
				return 1;
		}else
			if(color[v] == color[u])
				return 1;
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	FWD(i,1,n+1){
		if(color[i] == 0){
			color[i] = 1;
			if(odd_cycle(i)){
				printf("-1\n");
				return 0;
			}
			++k;
		}
	}
	FWD(i,1,n+1){
		FWD(j,1,n+1) dist[j] = INF;
		dist[i] = 0;
		Q.push(i);
		while(!Q.empty()){
			int u = Q.front();
			res[cc[i]] = max(res[cc[i]], dist[u]);
			Q.pop();
			for(int v : edges[u]) if(dist[v] == INF){
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	int r = 0;
	FWD(i,0,k) r += res[i];
	printf("%d\n", r);
	return 0;
}
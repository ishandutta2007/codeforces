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
typedef pair<LL, int> PLI;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int MAXN = 2010;
const LL INF = (LL)1000000010*1000000010;

int n, s, t, m;
vector<PII> edges[MAXN];

void calc_dist(int u, LL dist[]){
	FWD(i,0,n) dist[i] = INF;
	priority_queue<PLI> Q;
	Q.push(PLI(0,u));
	LL d;
	while(!Q.empty()){
		tie(d,u) = Q.top();
		Q.pop();
		d = -d;
		if(dist[u] != INF) continue;
		dist[u] = d;
		for(PII e : edges[u])
			if(dist[e.x] == INF)
				Q.push(PLI(-d-e.y, e.x));
	}
}

LL dists[MAXN], distt[MAXN];
int ords[MAXN], ordt[MAXN];
int wheres[MAXN], wheret[MAXN];
LL val[MAXN];

bool cmpds(int a, int b){
	return dists[a] < dists[b];
}

bool cmpdt(int a, int b){
	return distt[a] < distt[b];
}

LL ress[MAXN][MAXN];
LL rest[MAXN][MAXN];

int main(){
	scanf("%d %d %d %d", &n, &m, &s, &t);
	--s; --t;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		val[i] = a;
		ords[i] = ordt[i] = i;
	}
	FWD(i,0,m){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a;
		--b;
		edges[a].push_back(PII(b, c));
		edges[b].push_back(PII(a, c));
	}
	calc_dist(s, dists);
	calc_dist(t, distt);
	sort(ords, ords+n, cmpds);
	sort(ordt, ordt+n, cmpdt);
	FWD(i,0,n){
		wheres[ords[i]] = i;
		wheret[ordt[i]] = i;
		//printf("%d %d\n", dists[i], distt[i]);
	}
	BCK(i,n-1,-1)
		BCK(j,n-1,-1){

			LL je;

			ress[i][j] = -INF;
			if(wheret[ords[i]] >= j){
				je = val[ords[i]];
				if(i == n-1 || dists[ords[i+1]] > dists[ords[i]])
					ress[i][j] = max(ress[i][j], je - rest[i+1][j]);
				ress[i][j] = max(ress[i][j], je + ress[i+1][j]);
			}else{
				ress[i][j] = ress[i+1][j];
			}

			rest[i][j] = -INF;
			if(wheres[ordt[j]] >= i){
				je = val[ordt[j]];
				if(j == n-1 || distt[ordt[j+1]] > distt[ordt[j]])
					rest[i][j] = max(rest[i][j], je - ress[i][j+1]);
				rest[i][j] = max(rest[i][j], je + rest[i][j+1]);
			}else{
				rest[i][j] = rest[i][j+1];
			}

		}

	if(ress[0][0] == 0){
		printf("Flowers\n");
	}else if(ress[0][0] > 0){
		printf("Break a heart\n");
	}else{
		printf("Cry\n");
	}
	return 0;
}
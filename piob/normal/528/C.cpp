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

int n, m;
bool vis[500010];
int ind[200010];
vector<PII> edges[200010];
vector<int> cycle;

void dfs(int u){
	while(ind[u] < SIZE(edges[u])){
		if(vis[edges[u][ind[u]].nd]) ++ind[u];
		else{
			vis[edges[u][ind[u]].nd] = 1;
			dfs(edges[u][ind[u]].st);
			cycle.push_back(u);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		edges[a].push_back(PII(b,i));
		edges[b].push_back(PII(a,i));
	}
	int j = -1;
	FWD(i,1,n+1){
		if(SIZE(edges[i])&1){
			if(j == -1)
				j = i;
			else{
				edges[i].push_back(PII(j,m));
				edges[j].push_back(PII(i,m));
				++m;
				j = -1;
			}
		}
	}
	if(m&1){
		edges[1].push_back(PII(1,m));
		edges[1].push_back(PII(1,m));		
		++m;
	}
	cycle.push_back(1);
	dfs(1);
	printf("%d\n", m);
	FWD(i,0,SIZE(cycle)-1){
		if(i&1) printf("%d %d\n", cycle[i], cycle[i+1]);
		else printf("%d %d\n", cycle[i+1], cycle[i]);
	}
	return 0;
}
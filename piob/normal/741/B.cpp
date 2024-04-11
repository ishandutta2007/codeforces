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

int n, m, w;
vector<int> out[1010];
int B[1010], W[1010];
bool vis[1010];

vector<int> group;

void dfs(int u){
	vis[u] = 1;
	group.push_back(u);
	for(int v : out[u]) if(!vis[v]) dfs(v);
}

int dp[2][1010];

int main(){
	scanf("%d %d %d", &n, &m, &w);
	FWD(i,0,n) scanf("%d", &W[i]);
	FWD(i,0,n) scanf("%d", &B[i]);
	FWD(i,0,m){
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		out[a].push_back(b);
		out[b].push_back(a);
	}
	int a = 0, b = 1;
	FWD(i,0,n) if(!vis[i]){
		group.clear();
		dfs(i);
		FWD(i,0,w+1) dp[b][i] = dp[a][i];
		int tw = 0, tb = 0;
		for(int u : group){
			tw += W[u];
			tb += B[u];
			FWD(i,0,w+1)
				if(i >= W[u])
  				dp[b][i] = max(dp[b][i], dp[a][i-W[u]] + B[u]);
  	}
  	FWD(i,0,w+1)
  		if(i >= tw)
  			dp[b][i] = max(dp[b][i], dp[a][i-tw] + tb);
		swap(a, b);
	}
	printf("%d\n", dp[a][w]);
	return 0;
}
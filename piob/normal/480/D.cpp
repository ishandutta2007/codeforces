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
//typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};
const int mod = 1000000007;

int n, S;
int in[510];
int out[510];
int weight[510];
int strength[510];
int gain[510];
int dp[510][1010];
vector<int> child[510];
bool solved[510];

bool inside(int a, int b){
	return in[a] <= in[b] && out[b] <= out[a];
}

bool cmpOut(int a, int b){
	return out[a] < out[b];
}

int cdp[510][1010];

void solve(int u){
	solved[u] = 1;
	FWD(v,0,n) if(u != v && inside(u, v)){
		child[u].push_back(v);
		if(!solved[v]) solve(v);
	}
	child[u].push_back(n);
	sort(ALL(child[u]), cmpOut);
	//printf("solve %d\n", u);
	FWD(i,1,SIZE(child[u])){
		int v = child[u][i];
		int k = 0;
		FWD(j,1,i) if(out[child[u][k]] <= out[child[u][j]] && out[child[u][j]] <= in[child[u][i]]) k = j;
		//printf("poprzednik dla %d to %d\n", v, child[u][k]);
		FWD(s,0,S+1) cdp[i][s] = max(cdp[i-1][s], cdp[k][s] + dp[v][s]);
	}
	FWD(s,0,S+1) dp[u][s] = cdp[SIZE(child[u])-1][s];
	BCK(s,S,weight[u]-1) dp[u][s] = max(dp[u][s], dp[u][min(strength[u], s-weight[u])] + gain[u]);
}

int main(){
	scanf("%d %d", &n, &S);
	++n;
	in[0] = -5; out[0] = 2*n+5;
	weight[0] = 0; strength[0] = S;
	gain[0] = 0;
	FWD(i,1,n) scanf("%d %d %d %d %d", &in[i], &out[i], &weight[i], &strength[i], &gain[i]);
	in[n] = out[n] = -10;
	solve(0);
	printf("%d\n", dp[0][S]);
	return 0;
}
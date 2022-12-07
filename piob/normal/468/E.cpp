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

const int MOD = 1000000007;
const LL MOD2 = (LL)MOD*MOD;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, k;
int cx, cy;
unordered_map<int, int> X, Y;

int get_X(int x){
	if(X.find(x) == X.end())
		return X[x] = (cx++);
	return X[x];
}

int get_Y(int y){
	if(Y.find(y) == Y.end())
		return Y[y] = (cy++);
	return Y[y];
}

bool vis[2][103];
int val[103][103];
vector<int> A, B;

void rev(){
	swap(A, B);
	FWD(i,0,k) FWD(j,i+1,k) swap(val[i][j], val[j][i]);
	FWD(i,0,k) swap(vis[0][i], vis[1][i]);
}

void dfs(int u){
	vis[0][u] = 1;
	A.push_back(u);
	rev();
	FWD(v,0,k) if(!vis[0][v] && val[v][u]) dfs(v);
	rev();
}

int tmp[103];

void conv(int a[], int b[], int s){
	FWD(i,0,s+1) tmp[i] = 0;
	FWD(i,0,s+1) FWD(j,0,s+1-i) tmp[i+j] = (int)((tmp[i+j] + (LL)a[i]*b[j])%MOD);
	FWD(i,0,s+1) a[i] = tmp[i];
}

int p, q;
int cur[103];
int res[103];
int dp[(1<<25)+3];
LL dp2[(1<<25)+3];

void addme(LL &a, LL b){
	a += b;
	if(a >= MOD2) a -= MOD2;
}

void solve_smallV(){
	dp[0] = 1;
	FWD(i,1,1<<p) dp[i] = 0;
	FWD(j,0,q){
		int v = B[j];
		FWD(i,0,1<<p) dp2[i] = 0;
		FWD(i,0,p){
			int u = A[i];
			if(val[u][v])
				BCK(mask,(1<<p)-1,-1)
					if((mask&(1<<i)) == 0)
						addme(dp2[mask|(1<<i)], (LL)dp[mask] * val[u][v]);
		}
		FWD(i,0,1<<p) dp[i] = (int)((dp[i] + dp2[i]) % MOD);
	}
	FWD(i,0,k+1) cur[i] = 0;
	FWD(i,0,1<<p) cur[popcount(i)] = (cur[popcount(i)] + dp[i]) % MOD;
}

vector<PII> non_tree;
int m;
int par[103];
int mat[103][103];
int bdp[2][103][103];
bool block[103];

void prep(int u){
	FWD(v,0,m) if(par[v] == -1 && mat[u][v]){
		par[v] = u;
		prep(v);
	}
}

int cdp[103];

void calc(int u){
	bdp[0][u][0] = 1;
	FWD(i,1,m+1) bdp[0][u][i] = 0;	
	FWD(v,0,m) if(par[v] == u){
		calc(v);
		conv(bdp[0][u], bdp[1][v], m);
	}
	FWD(i,0,m+1) bdp[1][u][i] = bdp[0][u][i];
	if(!block[u])
		FWD(v,0,m) if(par[v] == u && !block[v]){
			cdp[0] = 1;
			FWD(i,1,m+1) cdp[i] = 0;
			FWD(w,0,m) if(par[w] == u && w != v) conv(cdp, bdp[1][w], m);
			conv(cdp, bdp[0][v], m);
			FWD(i,1,m+1)
				bdp[1][u][i] = (int)((bdp[1][u][i] + (LL)cdp[i-1] * mat[u][v]) % MOD);
		}
}

void solve_bigV(){
	m = p+q;
	FWD(i,0,m) FWD(j,0,m) mat[i][j] = 0;
	FWD(i,0,p) FWD(j,0,q) mat[i][p+j] = mat[p+j][i] = val[A[i]][B[j]];
	FWD(i,0,m) par[i] = -1;
	par[0] = -2;
	prep(0);
	non_tree.clear();
	FWD(i,0,m) FWD(j,i+1,m) if(mat[i][j] && par[i] != j && par[j] != i) non_tree.push_back(PII(i,j));
	//printf("%d %d\n", m, SIZE(non_tree));
	FWD(i,0,k+1) cur[i] = 0;
	FWD(mask,0,1<<SIZE(non_tree)){
		int base = 1;
		FWD(i,0,m) block[i] = 0;
		FWD(i,0,SIZE(non_tree)) if(mask&(1<<i)){
			int u = non_tree[i].st;
			int v = non_tree[i].nd;
			if(block[u] || block[v]){
				base = 0;
				break;
			}
			block[u] = block[v] = 1;
			base = (int)(((LL)base * mat[u][v]) % MOD);
		}
		if(!base) continue;
		calc(0);
		int s = popcount(mask);
		FWD(i,s,k+1) if(i-s <= m) cur[i] = (int)((cur[i] + (LL)base * bdp[1][0][i-s]) % MOD);
	}
}

void solve(){
	bool sw = 0;
	if(SIZE(A) > SIZE(B)) sw = 1;
	if(sw) rev();

	p = SIZE(A);
	q = SIZE(B);

	int e = 0;
	for(int x : A) for(int y : B) if(val[x][y]) ++e;

	if(p < 22)
		solve_smallV();
	else
		solve_bigV();

	conv(res, cur, k);

	if(sw) rev();
}

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,k){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a = get_X(a);
		b = get_Y(b);
		val[a][b] = c-1;
	}
	res[0] = 1;
	FWD(i,0,k){
		if(!vis[0][i]){
			A.clear();
			B.clear();
			dfs(i);
			if(!B.empty()) solve();
		}
	}
	int total = 0;
	int sil = 1;
	FWD(i,2,n-k) sil = (int)(((LL)sil*i)%MOD);
	BCK(i,k,-1){
		if(n > i) sil = (int)(((LL)sil*(n-i))%MOD);
		total = (int)((total + (LL)sil*res[i]) % MOD);
	}
	printf("%d\n", total);
	return 0;
}
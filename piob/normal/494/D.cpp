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

const int N = 100010;
const int mod = 1000000007;

int n;
int P[N];
LL S[N];
LL D[N], D2[N];
LL SD[N], SD2[N];
int H[N];
PII jmp[N][18];
vector<PII> E[N];

void dfs1(int u){
	S[u] = 1;
	for(PII e : E[u]) if(e.x != P[u]){
		int v = e.x;
		LL c = e.y;
		LL c2 = c*c%mod;
		P[v] = u;
		H[v] = H[u]+1;
		jmp[v][0] = PII(u, c);
		FWD(j,1,18){
			int w = jmp[v][j-1].x;
			jmp[v][j] = PII(jmp[w][j-1].x, (jmp[v][j-1].y + jmp[w][j-1].y) % mod);
		}
		dfs1(v);
		S[u] += S[v];
		SD[u] = D[u] = (D[u] + D[v] + c*S[v]) % mod;
		SD2[u] = D2[u] = (D2[u] + D2[v] + c2*S[v] + c*2*D[v]) % mod;
	}
}

void dfs2(int u){
	for(PII e : E[u]) if(e.x != P[u]){
		int v = e.x;
		LL c = e.y;
		LL c2 = c*c%mod;

		LL Du = (D[u] + mod - (D[v] + c*S[v]) % mod) % mod;
		LL D2u = (D2[u] + mod - (D2[v] + c2*S[v]%mod + c*2*D[v]%mod)%mod) % mod;

		D[v] = (D[v] + Du + c*(n-S[v])%mod) % mod;
		D2[v] = (D2[v] + D2u + c2*(n-S[v])%mod + 2LL*(c*Du%mod)) % mod;

		dfs2(v);
	}
}

LL get_dist(int u, int v){
	LL res = 0;
	FWD(r,0,2){
		int d = max(0, H[u] - H[v]);
		for(int j = 0; d; ++j)
			if(d&(1<<j)){
				res = (res + jmp[u][j].y);
				if(res >= mod) res -= mod;
				u = jmp[u][j].x;
				d = (d&(~(1<<j)));
			}
		swap(u, v);
	}
	if(u != v){
		BCK(j,17,-1){
			if(jmp[u][j].x != jmp[v][j].x){
				res = (res + jmp[u][j].y);
				if(res >= mod) res -= mod;
				res = (res + jmp[v][j].y);
				if(res >= mod) res -= mod;
				u = jmp[u][j].x;
				v = jmp[v][j].x;
			}
		}
		res = (res + jmp[u][0].y);
		if(res >= mod) res -= mod;
		res = (res + jmp[v][0].y);		
		if(res >= mod) res -= mod;
	}
	return res;
}

bool ancestor(int u, int v){
	int d = max(0, H[v] - H[u]);
	for(int j = 0; d; ++j)
		if(d&(1<<j)){
			v = jmp[v][j].x;
			d = (d&(~(1<<j)));
		}
	return u == v;
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		E[a].push_back(PII(b,c));
		E[b].push_back(PII(a,c));
	}
	jmp[1][0] = PII(1,0);
	FWD(j,1,18){
		int w = jmp[1][j-1].x;
		jmp[1][j] = PII(jmp[w][j-1].x, (jmp[1][j-1].y + jmp[w][j-1].y) % mod);
	}
	dfs1(1);
	dfs2(1);
	//FWD(i,1,n+1) printf("%d %d %d\n", i, D[i], D2[i]);
	int q;
	scanf("%d", &q);
	FWD(i,0,q){
		int u, v;
		LL D2u;
		scanf("%d %d", &u, &v);
		//printf("solving %d %d\n", u, v);
		LL c = get_dist(u, v);
		//printf("dist %lld\n", c);
		LL c2 = c*c%mod;
		//printf("dist2 %lld\n", c2);
		if(v != u && ancestor(v, u)){
			D2u = (D2[v] + mod - SD2[v]) % mod;
			D2u = (D2u + c2*((n+mod-S[v])%mod)%mod) % mod;
			D2u = (D2u + 2LL*(c*((D[v]+mod-SD[v])%mod)%mod))%mod;
			D2u = (D2[u] + mod - D2u) % mod;
		}else{
			D2u = (SD2[v] + c2*S[v]%mod + 2LL*(c*SD[v]%mod)) % mod;
		}
		int res = (int)(((2LL*D2u+mod-D2[u])) % mod);
		if(res < 0) res += mod;
		printf("%d\n", res);
	}
	return 0;
}
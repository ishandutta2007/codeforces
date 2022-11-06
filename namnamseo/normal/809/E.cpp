#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;
int a[200010];
vector<int> edge[200010];

ll ans;
const ll mod = int(1e9)+7;
ll Pow(ll b, ll e){
	if(e<0) e=(-e*(mod-2))%(mod-1);
	ll ret=1;
	while(e){
		if(e&1) (ret*=b)%=mod; e/=2; (b*=b)%=mod;
	}
	return ret;
}

bool dead[200010];
bool vis[200010];
int comp[200010], compn;
int sz[200010];
int par[200010];

void dfs(int x){
	vis[x]=1; comp[compn++]=x; sz[x]=1;
	for(int y:edge[x]) if(!dead[y] && !vis[y]){ par[y]=x; dfs(y); sz[x]+=sz[y]; }
}

void load(int x, int d, vector<pp>& v){
	v.eb(x, d); vis[x]=1;
	for(int y:edge[x]) if(!dead[y] && !vis[y]){
		load(y, d+1, v);
	}
}

vector<int> divisor[200010];
ll phi[200010];
ll gco[200010];

ll atmp[200010];
ll multphisum[200010];
ll mcoe[200010];

int childn;
vector<pp> elem[200010];

void proc_component(int x){
	compn = 0;
	par[x]=-1; dfs(x);
	int r = x;
	for(;;){
		int mc = -1;
		for(int c:edge[r]){
			if(!dead[c] && par[c] == r){
				if(mc == -1 || sz[mc] < sz[c]) mc = c;
			}
		}
		if(mc == -1 || sz[mc] <= compn/2) break;
		r = mc;
	}

	for(int i=0; i<compn; ++i) vis[comp[i]] = 0;

	vis[r]=1;
	childn = 0;
	for(int c:edge[r]) if(!dead[c]){
		elem[childn].clear();
		load(c, 1, elem[childn]);
		for(auto tmp:elem[childn]){
			int x = tmp.x;
			int g = __gcd(x, r);
			(ans += phi[x] * phi[r] % mod * gco[g] % mod * tmp.y % mod) %= mod;
			for(int d:divisor[x])
				(multphisum[d] += phi[x]) %= mod;
		}
		childn++;
	}

	for(int i=0; i<compn; ++i) vis[comp[i]] = 0;

	for(int i=0; i<childn; ++i){
		for(auto tmp:elem[i]){
			int x = tmp.x;
			for(int d:divisor[x])
				(multphisum[d] += mod - phi[x]) %= mod;
		}

		for(auto tmp:elem[i]){
			int x, D; tie(x, D) = tmp;
			ll c = phi[x] * ll(D) % mod;
			for(int d:divisor[x]){
				(ans += c * multphisum[d] % mod * mcoe[d] % mod) %= mod;
			}
		}

		for(auto tmp:elem[i]){
			int x = tmp.x;
			for(int d:divisor[x])
				(multphisum[d] += phi[x]) %= mod;
		}
	}

	for(int i=0; i<childn; ++i){
		for(auto tmp:elem[i]){
			int x = tmp.x;
			for(int d:divisor[x]) multphisum[d] = 0;
		}
	}

	dead[r] = 1;
	for(int c:edge[r]) if(!dead[c]){
		proc_component(c);
	}
}

char prime[200010];
ll moeb[200010];
void build_arithmetic(){
	fill(prime+2, prime+n+1, 1);
	iota(phi+1, phi+n+1, 1);
	fill(gco+1, gco+n+1, 1);
	fill(moeb+1, moeb+n+1, 1);

	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; j+=i){
			divisor[j].pb(i);

			if(prime[i]){
				phi[j] = phi[j] / i * (i-1);
				(gco[j] *= i * Pow(i-1, -1) % mod) %= mod;

				if(j >= i*1ll*i && j/i % i == 0) moeb[j] = 0;
				else moeb[j] = -moeb[j];
				if(j != i) prime[j] = 0;
			}
		}
	}

	for(int i=1; i<=n; ++i){
		reverse(all(divisor[i]));
		for(int d:divisor[i]){
			(mcoe[i] += (mod + moeb[d]) * gco[i/d] % mod) %= mod;
		}
	}
}

void in(){
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	for(int i=1; i<n; ++i){
		int x, y; read(x, y);
		edge[a[x]].pb(a[y]);
		edge[a[y]].pb(a[x]);
	}
}

int main(){
	in();
	build_arithmetic();
	proc_component(1);
	printf("%lld\n", ans * 2 % mod * Pow(n, -1) % mod * Pow(n-1, -1) % mod);
	return 0;
}
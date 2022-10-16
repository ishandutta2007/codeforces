#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 5e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 << LOG);

int par[N], ty[N], tko[N], del[N], rnk[N], kad[N];
int p[N], inv[N], u[N], v[N];
int zap_x[N], zap_y[N];
int n, m, q, tme, stari[N];
set < int > S[N];

int get_max(set < int > &s){
	if((int)s.size() == 0) 
		return 0;
	return *s.rbegin();
}

int pr(int x){
	if(x == par[x]) return x;
	return pr(par[x]);
}

void mrg(int x, int y, int z){
	x = pr(x), y = pr(y);
	if(x == y) return;
	if(rnk[x] < rnk[y])
		x ^= y, y ^= x, x ^= y; 
	if(rnk[x] == rnk[y])
		rnk[x]++;
	zap_x[z] = x; zap_y[z] = y;
	stari[y] = get_max(S[y]);
	if(stari[y])
		S[x].insert(stari[y]);
	par[y] = x;
}

void update(int x){
	if(par[x] == x) return;
	if(stari[x])
		S[par[x]].erase(stari[x]);
	stari[x] = get_max(S[x]);
	if(stari[x])
		S[par[x]].insert(stari[x]);
	update(par[x]);
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1;i <= n;i++){
		scanf("%d", p + i);
		inv[p[i]] = i; par[i] = i;
		S[i].insert(p[i]);
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d", u + i, v + i);
	}
	for(int i = 0;i < q;i++){
		scanf("%d%d", ty + i, tko + i);
		if(ty[i] == 2)
			del[tko[i]] = 1;
	}
	for(int i = 1;i <= m;i++){
		if(!del[i]) mrg(u[i], v[i], q);
	}
	for(int i = q - 1;i >= 0;i--)
		if(ty[i] == 2)
			mrg(u[tko[i]], v[tko[i]], i);
	for(int i = 0;i < q;i++){
		if(ty[i] == 2) {
			par[zap_y[i]] = zap_x[i];
			if(stari[zap_y[i]])
				S[par[zap_y[i]]].erase(stari[zap_y[i]]);
			par[zap_y[i]] = zap_y[i];
			update(zap_x[i]);
			continue;
		}
		int cur = pr(tko[i]);
		int ans = get_max(S[cur]);
		if(ans){
			S[inv[ans]].erase(ans);
			update(inv[ans]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
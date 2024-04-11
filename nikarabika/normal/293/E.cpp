//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000 + 85 - 69;
int p[maxn],
	d[maxn],
	fen[maxn],
	vecsz, n, W, L, cent;
LL ans;
pii vec[maxn];
vector<pii> adj[maxn];
bool mark[maxn];

void add(int val, int idx, int maxlen){
	idx++;
	while(idx <= maxlen + 4){
		fen[idx] += val;
		idx += idx & -idx;
	}
	return;
}

int get(int idx, int maxlen){
	if(idx > maxlen + 3)
		idx = maxlen + 3;
	idx++;
	int ret = 0;
	while(idx > 0){
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void pakkon(int siz){
	/*cout << "pakkon " << siz << endl;*/
	for(int i = 0; i <= siz + 5; i++)
		fen[i] = 0;
	return;
}

int dfs(int v, int siz, int par = -1){
	p[v] = par;
	d[v] = 1;
	for(auto u : adj[v])
		if(!mark[u.L] and u.L != par){
			d[v] += dfs(u.L, siz, v);
			if(~cent)
				return 0;
		}
	if(d[v] >= (siz + 1) / 2){
		cent = v;
		return 0;
	}
	return d[v];
}

int dfs2(int v, int len, int wei, int par = -1){
	int ret = 1;
	vec[vecsz++] = MP(wei, len);
	for(auto u : adj[v])
		if(!mark[u.L] and u.L != par)
			smax(ret, 1 + dfs2(u.L, len + 1, wei + u.R, v));
	return ret;
}

void go(int v, int siz){
	cent = -1;
	dfs(v, siz);
	mark[v = cent] = true;
	//cout << "Centroid: " << v << endl;
	//cout << "@1" << endl;
	int maxlen = -1;
	vecsz = 0;
	//vec[vecsz++] = MP(0, 0);
	for(auto vert : adj[v]){
		int u = vert.L,
			wei = vert.R;
		if(mark[u])
			continue;
		smax(maxlen, dfs2(u, 1, wei));
	}
	//cout << "@2" << endl;
	sort(vec, vec + vecsz);
	/*for(int i = 0; i < vecsz; i++)
		cout << vec[i].L << ' ' << vec[i].R << endl;
	*/
	int ptr = 0;
	for(int i = vecsz - 1; i >= 0; i--){
		ans += (vec[i].L <= W and vec[i].R <= L) * 2;
		while(ptr < vecsz and vec[ptr].L <= W - vec[i].L)
			add(+1, vec[ptr++].R, maxlen);
		//cout << "Log: " << i << ' ' << ptr << endl;
		//cout << "lastans: " << ans << ' ';
		ans += get(L - vec[i].R, maxlen);
		//cout << "nextans: " << ans << endl;
	}
	pakkon(maxlen);
	//cout << "@3" << endl;
	for(auto vert : adj[v]){
		int u = vert.L,
			wei = vert.R;
		if(mark[u])
			continue;
		vecsz = 0;
		maxlen = dfs2(u, 1, wei);
		sort(vec, vec + vecsz);
		ptr = 0;
		for(int i = vecsz - 1; i >= 0; i--){
			while(ptr < vecsz and vec[ptr].L <= W - vec[i].L)
				add(+1, vec[ptr++].R, maxlen);
			ans -= get(L - vec[i].R, maxlen);
		}
		pakkon(maxlen);
	}
	//cout << "@4" << endl;
	for(auto u : adj[v])
		if(!mark[u.L])
			go(u.L, (u.L == p[v] ? siz - d[v] : d[u.L]));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> L >> W;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--;
		adj[i].PB(MP(fi, se));
		adj[fi].PB(MP(i, se));
	}
	go(0, n);
	cout << ans / 2 << endl;
	return 0;
}
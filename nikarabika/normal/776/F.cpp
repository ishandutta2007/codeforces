//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 2e5 + 10;
int pos[maxn * 4],
	frm[maxn * 4],
	too[maxn * 4],
	com[maxn * 4];
bool mark[maxn * 4],
	 fnd[maxn * 4];
int ord[maxn],
	ans[maxn],
	siz[maxn];
int n, k, cur, cent;
int comsz;
vector<int> adj[maxn],
	tadj[maxn];
set<int> ver[maxn];

bool cmp(int i, int j){
	i = (frm[i] ^ too[i] ^ cur) - cur;
	j = (frm[j] ^ too[j] ^ cur) - cur;
	if(i < 0) i += n;
	if(j < 0) j += n;
	return i < j;
}

bool ordcmp(int i, int j){
	auto it1 = ver[i].end(),
		 it2 = ver[j].end();
	while(it1 != ver[i].begin() and it2 != ver[j].begin()){
		it1--, it2--;
		if(*it1 < *it2) return true;
		else if(*it1 > *it2) return false;
	}
	if(it2 == ver[j].begin()) return false;
	return true;
}

void dfs(int e){
	if(mark[e]) return;
	mark[e] = true;

	int eid = e>>1;
	int v = (e&1 ? frm[eid] : too[eid]);
	int u = frm[eid] ^ too[eid] ^ v;
	ver[comsz].insert(u);
	ver[comsz].insert(v);
	com[e] = comsz;
	int ne = adj[v][pos[e] - 1]<<1;

	if(v == too[ne/2])
		ne |= 1;
	return dfs(ne);
}

void tdfs(int u, int p, int sz){
	siz[u] = 1;
	for(auto v : tadj[u])
		if((v^p) and !fnd[v]){
			tdfs(v, u, sz);
			siz[u] += siz[v];
		}
	if((cent >> 31) and siz[u] >= (sz + 1) / 2)
		cent = u;
}

void go(int u, int sz = comsz, int c = 1){
	cent = -1;
	tdfs(u, -1, sz);
	u = cent;
	fnd[u] = true;
	ans[u] = c++;
	for(auto v : tadj[u])
		if(!fnd[v]){
			if(siz[v] > siz[u])
				go(v, sz - siz[u], c);
			else
				go(v, siz[v], c);
		}
}

int main(){
	scanf("%d%d", &n, &k);
	if(k == 0){
		printf("1");
		return 0;
	}
	for(int i = 0; i < k; ++i){
		int fi, se;
		cin >> fi >> se;
		--fi, --se;
		adj[fi].PB(i);
		adj[se].PB(i);
		frm[i] = fi, too[i] = se;
	}
	memset(pos, -1, sizeof pos);
	for(int i = 0; i < n; i++){
		frm[i + k] = i;
		too[i + k] = (i + 1) % n;
		adj[i].PB(i + k);
		adj[(i + 1) % n].PB(i + k);
	}
	for(int i = 0; i < n; i++){
		cur = i;
		sort(all(adj[i]), cmp);
		for(int j = sz(adj[i]) - 1; j >= 0; --j){
			if(i == frm[adj[i][j]]) pos[adj[i][j]<<1|1] = j;
			else pos[adj[i][j]<<1|0] = j;
		}
	}
	for(int i = 0; i < k+k; i++)
		if(!mark[i]){
			dfs(i);
			comsz++;
		}
	for(int i = 0; i < k+k; i+=2){
		int u = com[i|0];
		int v = com[i|1];
		tadj[u].PB(v);
		tadj[v].PB(u);
	}
	go(0);
	iota(ord, ord + comsz, 0);
	sort(ord, ord + comsz, ordcmp);
	for(int i = 0; i < comsz; i++)
		cout << ans[ord[i]] << ' ';
	cout << '\n';
	return 0;
}
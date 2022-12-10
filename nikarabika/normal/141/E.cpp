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

const int maxn = 1e3 + 85 - 69,
	  maxm = 1e5 + 85 - 69;
int com[maxn],
	emar[maxm],
	par[maxn],
	frm[maxm],
	too[maxm],
	n, m, comcnt;
bool mark[maxn],
	 ty[maxm];
vector<int> adj[maxn];

void dfs(int u, int pe){
	com[u] = comcnt;
	mark[u] = true;
	for(auto e : adj[u]){
		if(e == pe) continue;
		int v = frm[e] ^ too[e] ^ u;
		if(!mark[v])
			dfs(v, e);
		else
			emar[e] = 2;
	}
	return;
}

bool erase(int u, int t, int lst = -1){
	mark[u] = true;
	if(u == t){
		emar[lst] = 0;
		adj[frm[lst]].erase(find(all(adj[frm[lst]]), lst));
		adj[too[lst]].erase(find(all(adj[too[lst]]), lst));
		return true;
	}
	for(auto e : adj[u]){
		int v = frm[e] ^ too[e] ^ u;
		if(!mark[v])
			if(erase(v, t, (ty[e] ? lst : e))) return true;
	}
	return false;
}

void build(bool id){
	for(int i = 0; i < n; i++) adj[i].clear();
	for(int i = 0; i < m; i++)
		if(ty[i] == id and emar[i] != 2)
			adj[frm[i]].PB(i), adj[too[i]].PB(i);
	return;
}

void crash(void){
	cout << -1 << endl;
	exit(0);
	return;
}	

int root(int u){ return (par[u]>>31) ? u : par[u] = root(par[u]);}

bool merge(int u, int v){
	if((u = root(u)) == (v = root(v)))
		return false;
	if(par[u] > par[v])
		swap(v, u);
	par[u] += par[v];
	par[v] = u;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		char c;
		cin >> frm[i] >> too[i] >> c;
		frm[i]--, too[i]--;
		ty[i] = c == 'M';
	}
	if(n & 1 ^ 1)
		crash();
	//build_jungle
	build(1);
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, -1);
	memset(mark, false, sizeof mark);
	build(0);
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, -1), comcnt++;
	for(int i = 0; i < m; i++)
		if(!ty[i] and emar[i] != 2)
			emar[i] = 1;
	if(comcnt - 1 > n / 2)
		crash();
	memset(par, -1, sizeof par);
	int rem = n / 2;
	for(int i = 0; i < m; i++)
		if(!emar[i])
			rem -= (emar[i] = merge(com[frm[i]], com[too[i]]));
	if(rem != n / 2 - (comcnt - 1))
		crash();
	build(0);
	for(int i = 0; i < m; i++)
		if(rem and !emar[i] and ty[i]){
			memset(mark, false, sizeof mark);
			erase(frm[i], too[i]);
			emar[i] = 1;
			adj[frm[i]].PB(i);
			adj[too[i]].PB(i);
			rem--;
		}
	if(rem)
		crash();
	cout << n-1 << '\n';
	for(int i = 0; i < m; i++)
		if(emar[i] == 1)
			cout << i+1 << ' ';
	cout << '\n';
	return 0;
}
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

const int maxn = 100 + 10, maxm = maxn * 4;
int a[maxn],
	last[maxn],
	pos[maxn],
	prv[maxm],
	cap[maxm],
	to[maxm],
	h[maxn],
	n, m, cnt;
bool mark[maxn];
vector<int> prm;
vector<pii> good;

int count(int val, int p){
	int cnt = 0;
	while(val % p == 0)
		val /= p, cnt++;
	return cnt;
}

void add(int val){
	for(int i = 2; i * i <= val; i++)
		if(val % i == 0){
			prm.PB(i);
			while(val % i == 0)
				val /= i;
		}
	if(val != 1)
		prm.PB(val);
	return;
}

void add_edge(int v, int u, int vu, int uv = 0){
	to[cnt] = u, cap[cnt] = vu, prv[cnt] = last[v], last[v] = cnt++;
	to[cnt] = v, cap[cnt] = uv, prv[cnt] = last[u], last[u] = cnt++;
}

bool bfs(int source, int sink){
	memset(mark, false, sizeof mark);
	memset(h, false, sizeof h);
	queue<int> Q;
	mark[source] = true;
	Q.push(source);
	while(sz(Q)){
		int v = Q.front();
		if(v == sink)
			return true;
		Q.pop();
		for(int e = last[v]; ~e; e = prv[e]){
			if(mark[to[e]] or !cap[e])
				continue;
			mark[to[e]] = true;
			h[to[e]] = h[v] + 1;
			Q.push(to[e]);
		}
	}
	return false;
}

int dfs(int v, int sink, int flow = 1000 * 1000 * 1000){
	if(v == sink)
		return flow;
	int downflow = 0;
	for(int &e = pos[v]; ~e; e = prv[e]){
		if(!cap[e] or h[to[e]] != h[v] + 1)
			continue;
		int val = dfs(to[e], sink, min(flow, cap[e]));
		cap[e ^ 0] -= val;
		cap[e ^ 1] += val;
		flow -= val;
		downflow += val;
		if(!flow)
			break;
	}
	return downflow;
}

int max_flow(int source, int sink){
	int ret = 0;
	while(bfs(source, sink)){
		for(int i = 0; i <= n + 1; i++)
			pos[i] = last[i];
		ret += dfs(source, sink);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		if(fi & 1) swap(fi, se);
		good.PB(MP(fi, se));
	}
	for(auto dot : good)
		add(__gcd(a[dot.L], a[dot.R]));
	sort(all(prm));
	prm.resize(unique(all(prm)) - prm.begin());
	int ans = 0;
	for(auto val : prm){
		memset(last, -1, sizeof last);
		cnt = 0;
		for(auto dot : good)
			add_edge(dot.L, dot.R, count(__gcd(a[dot.L], a[dot.R]), val));
		for(int i = 0; i < n; i += 2)
			add_edge(n, i, count(a[i], val));
		for(int i = 1; i < n; i += 2)
			add_edge(i, n + 1, count(a[i], val));
		ans += max_flow(n, n + 1);
	}
	cout << ans << endl;
	return 0;
}
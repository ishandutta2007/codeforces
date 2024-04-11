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

const int maxn = 200 + 85 - 69, maxm = maxn * maxn * 2;
int h[maxn],
	last[maxn],
	pos[maxn],
	to[maxm],
	cap[maxm],
	prv[maxm],
	a[maxn],
	n, cnt;
bool mark[maxn];
vector<int> adj[maxn],
	vec[maxn / 3];

bool isprime(int x){
	if(x <= 1) return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

void add_edge(int v, int u, int vu, int uv = 0){
	to[cnt] = u, cap[cnt] = vu, prv[cnt] = last[v], last[v] = cnt++;
	to[cnt] = v, cap[cnt] = uv, prv[cnt] = last[u], last[u] = cnt++;
}

bool bfs(int source, int sink){
	memset(mark, false, sizeof mark);
	memset(h, 0, sizeof h);
	queue<int> Q;
	mark[source] = true;
	Q.push(source);
	while(sz(Q)){
		int v = Q.front();
		if(v == sink)
			return true;
		Q.pop();
		for(int e = last[v]; ~e; e = prv[e]){
			if(!cap[e] or mark[to[e]])
				continue;
			mark[to[e]] = true;
			h[to[e]] = h[v] + 1;
			Q.push(to[e]);
		}
	}
	return false;
}

int flowdfs(int v, int sink, int flow = 1000 * 1000 * 1000){
	if(v == sink)
		return flow;
	int downflow = 0;
	for(int &e = pos[v]; ~e; e = prv[e]){
		if(!cap[e] or h[to[e]] != h[v] + 1)
			continue;
		int val = flowdfs(to[e], sink, min(flow, cap[e]));
		cap[e ^ 0] -= val;
		cap[e ^ 1] += val;
		downflow += val;
		flow -= val;
		if(!flow)
			break;
	}
	return downflow;
}

int max_flow(int source, int sink){
	int ans = 0;
	while(bfs(source, sink)){
		for(int i = 0; i <= n + 1; i++)
			pos[i] = last[i];
		ans += flowdfs(source, sink);
	}
	return ans;
}

void dfs(int v){
	mark[v] = true;
	vec[cnt].PB(v);
	for(auto u : adj[v])
		if(!mark[u])
			dfs(u);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(last, -1, sizeof last);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		if(a[i] & 1) add_edge(n, i, 2);
		else add_edge(i, n + 1, 2);
		if(a[i] & 1)
			for(int j = 0; j < n; j++)
				if(isprime(a[i] + a[j]))
					add_edge(i, j, 1);
	}
	int F = max_flow(n, n + 1);
	if(F < n){
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		if(a[i] & 1)
			for(int e = last[i]; ~e; e = prv[e])
				if(!cap[e] and to[e] < n)
					adj[i].PB(to[e]), adj[to[e]].PB(i);
	memset(mark, false, sizeof mark);
	cnt = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i]){
			dfs(i);
			cnt++;
		}
	cout << cnt << '\n';
	for(int i = 0; i < cnt; i++, cout << '\n'){
		cout << sz(vec[i]) << ' ';
		for(auto val : vec[i])
			cout << val + 1 << ' ';
	}
	return 0;
}
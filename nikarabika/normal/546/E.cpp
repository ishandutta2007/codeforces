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

const int maxn = 100 * 2 + 85 - 69, maxm = 200 * 10 + 85 - 69;
int to[maxm],
	cap[maxm],
	prv[maxm],
	last[maxn],
	pos[maxn],
	h[maxn],
	a[maxn],
	b[maxn],
	n, m, cnt;
bool mark[maxn];

void addedge(int v, int u, int vu, int uv = 0){
	to[cnt] = u, cap[cnt] = vu, prv[cnt] = last[v], last[v] = cnt++;
	to[cnt] = v, cap[cnt] = uv, prv[cnt] = last[u], last[u] = cnt++;
}

bool bfs(int source, int sink){
	memset(mark, false, sizeof mark);
	memset(h, 0, sizeof h);
	mark[source] = true;
	queue<int> Q;
	Q.push(source);
	while(sz(Q)){
		int v = Q.front();
		Q.pop();
		if(v == sink)
			return true;
		for(int e = last[v]; e != -1; e = prv[e]) if(cap[e] and !mark[to[e]]){
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
	for(int &e = pos[v]; e != -1; e = prv[e]){
		if(cap[e] == 0 or h[to[e]] != h[v] + 1)
			continue;
		int val = dfs(to[e], sink, min(flow, cap[e]));
		cap[e ^ 0] -= val;
		cap[e ^ 1] += val;
		flow -= val;
		downflow += val;
		if(!flow) break;
	}
	return downflow;
}

int max_flow(int source, int sink){
	int ans = 0;
	while(bfs(source, sink)){
		for(int i = 0; i < 2 * n + 2; i++)
			pos[i] = last[i];
		ans += dfs(source, sink);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(last, -1, sizeof last);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		addedge(fi, se + n, 100);
		addedge(se, fi + n, 100);
	}
	for(int i = 0; i < n; i++){
		addedge(i, n + i, 100);
		addedge(2 * n, i, a[i]);
		addedge(i + n, 2 * n + 1, b[i]);
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += a[i] - b[i];
	if(sum){
		cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < n; i++) sum += a[i];
	int ans[n][n];
	memset(ans, 0, sizeof ans);
	if(max_flow(2 * n, 2 * n + 1) == sum){
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			for(int e = last[i]; ~e; e = prv[e])
				ans[i][to[e] - n] = cap[e ^ 1];
		for(int i = 0; i < n; i++, cout << '\n')
			for(int j = 0; j < n; j++)
				cout << ans[i][j] << ' ';
	}
	else
		cout << "NO\n";
	return 0;
}
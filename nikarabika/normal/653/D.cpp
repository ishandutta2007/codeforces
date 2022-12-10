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

const int maxn = 100, maxm = 10000;
LL mat[maxn][maxn],
   cap[maxm];
int h[maxn],
	to[maxm],
	prv[maxm],
	pos[maxn],
	last[maxn],
	cnt;
bool mark[maxn];
LL n, m, x;

void add_edge(int v, int u, LL vu, LL uv){
	to[cnt] = u, cap[cnt] = vu, prv[cnt] = last[v], last[v] = cnt++;
	to[cnt] = v, cap[cnt] = uv, prv[cnt] = last[u], last[u] = cnt++;
	return;
}

bool bfs(int s, int t){
	memset(h, 0, sizeof h);
	memset(mark, false, sizeof mark);
	queue<int> Q;
	Q.push(s);
	mark[s] = true;
	while(sz(Q)){
		int v = Q.front();
		if(v == t)
			return true;
		Q.pop();
		for(int e = last[v]; ~e; e = prv[e]){
			if(cap[e] == 0 or mark[to[e]])
				continue;
			h[to[e]] = h[v] + 1;
			mark[to[e]] = true;
			Q.push(to[e]);
		}
	}
	return false;
}

LL dfs(int v, int t, LL flow = 1000LL * 1000 * 1000 * 1000 * 1000){
	if(v == t) return flow;
	LL downflow = 0;
	for(int &e = pos[v]; ~e; e = prv[e]){
		if(cap[e] == 0 or h[to[e]] != h[v] + 1)
			continue;
		LL val = dfs(to[e], t, min(cap[e], flow));
		flow -= val;
		downflow += val;
		cap[e ^ 0] -= val;
		cap[e ^ 1] += val;
		if(!flow) break;
	}
	return downflow;
}

inline LL Div(LL soor, LD makh){
	return floor(soor / makh);
}

LL max_flow(int s, int t){
	LL ans = 0;
	while(bfs(s, t)){
		for(int i = 0; i < n; i++)
			pos[i] = last[i];
		ans += dfs(s, t);
	}
	return ans;
}

LL build(LD maxw){
	cnt = 0;
	memset(last, -1, sizeof last);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(Div(mat[i][j], maxw) > 0 or Div(mat[j][i], maxw))
				add_edge(i, j, Div(mat[i][j], maxw), Div(mat[j][i], maxw));
	return max_flow(0, n - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		mat[fi][se] = th;
	}
	LD lo = 0, hi = 1000 * 1000 + 1;
	for(int i = 0; i < 200; i++){
		LD mid = (lo + hi) / 2;
		if(build(mid) >= x)
			lo = mid;
		else
			hi = mid;
	}
	cout.precision(12);
	cout << fixed << lo * x << endl;
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 1007, M = N * N;

int n, m, q;

int f[M];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool vis[N][N];

int ms, mt;
inline int P(int x, int y) {
	if(x < 1 || y > m) return ms; 
	if(x > n || y < 1) return mt; 
	return (x - 1) * m + y;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) f[x] = y;
}

void mark(int x, int y) {
	L(a, -1, 1) 
		L(b, -1, 1) if(vis[x + a][y + b]) 
			merge(P(x, y), P(x + a, y + b));
}

vi st[M];
vi e[M], S;

void add(int u, int v) {
	u = find(u), v = find(v);
	if(u != v) 
		e[u].emplace_back(v), e[v].emplace_back(u);
}

void remark(int x, int y) {
	S.emplace_back(find(P(x, y)));
	L(a, -1, 1) 
		L(b, -1, 1) 
			if(vis[x + a][y + b]) 
				S.emplace_back(find(P(x + a, y + b))), add(P(x, y), P(x + a, y + b));
	vis[x][y] = true;
}

bool zt[M];
vi qwq, inS, inT; 
void dfs(int x) {
	zt[x] = true;
	qwq.emplace_back(x);
	for(const int &v : e[x]) if(!zt[v]) dfs(v);
}

char s[N][N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	ms = n * m + 1, mt = n * m + 2; 
	L(i, 1, mt) f[i] = i;
	me(vis, 1);
	L(i, 1, n) {
		cin >> (s[i] + 1);
		L(j, 1, m) if(s[i][j] == '.') vis[i][j] = false;
	}
	
	L(i, 1, n) L(j, 1, m) if(vis[i][j]) mark(i, j);
	
	L(i, 1, n) L(j, 1, m) L(a, -2, 2) L(b, -2, 2) 
		if(abs(a) == 2 || abs(b) == 2) { 
			int u = find(P(i, j)), v = find(P(i + a, j + b));
			if(u != v) st[u].emplace_back(v), st[v].emplace_back(u);
		}

	L(i, 1, mt) 
		sort(st[i].begin(), st[i].end()), 
		st[i].erase(unique(st[i].begin(), st[i].end()), st[i].end());
	
	while(q--) {
		int k;
		cin >> k;
		
		vector < pair < int, int > > Pr;
		
		S.clear();
		L(i, 1, k) {
			int x, y;
			cin >> x >> y;
			Pr.emplace_back(make_pair(x, y));
			remark(x, y); 
		}
		
		bool ok = false;
		
		inS.clear(), dfs(find(ms)), swap(qwq, inS);
		inT.clear(), dfs(find(mt)), swap(qwq, inT);
		
		for(const int &u : inS) 
			for(const int &v : inT) {
				auto x = lower_bound(st[u].begin(), st[u].end(), v);
				if(x != st[u].end() && *x == v) {
					ok = true;
					break ;
				}
			}
		
		if(ok) cout << "NO" << endl;
		else cout << "YES" << endl;
				
		for(const int &u : S) zt[u] = false, e[u].clear();
		for(auto u : Pr) vis[u.first][u.second] = false;
	}
	
	return 0;
}
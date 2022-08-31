#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 760, M = 1e7 + 7;
int n, p[N], mat[N], bmat[N], ch[M][2], fail[M], las[M], tot, ans;
string s[N];
bitset<N> e[N], vis;
vector< int > ns;
void bfs() {
	queue<int> q;
	L(i, 0, 1) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(!las[u]) las[u] = las[fail[u]];
		L(i, 0, 1) {
			if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
		}
	}
}
bool dfs(int x) {
	L(i, 1, n) if(e[x][i] && !vis[i]) {
		vis[i] = true;
		if(!mat[i] || dfs(mat[i])) {
			mat[i] = x;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> s[i], p[i] = i;
	L(i, 1, n) {
		int now = 0;
		L(j, 0, s[i].size() - 1) {
			if(!ch[now][s[i][j] - 'a']) ch[now][s[i][j] - 'a'] = ++tot;
			now = ch[now][s[i][j] - 'a'];
		}
		las[now] = i;
	}
	bfs();
	L(i, 1, n) {
		int now = 0;
		L(j, 0, s[i].size() - 1) {
			now = ch[now][s[i][j] - 'a'];
			if(j == (int)(s[i].size() - 1)) e[i][las[fail[now]]] = true;
			else e[i][las[now]] = true;
		}
		e[i][0] = false;
	}
	sort(p + 1, p + n + 1, [&](int x, int y) { return s[x].size() < s[y].size(); });
	L(i, 1, n) L(j, 1, n) if(e[p[i]][j]) e[p[i]] |= e[j];
	L(i, 1, n) vis.reset(), ans += dfs(i);
	L(i, 1, n) if(mat[i]) bmat[mat[i]] = i;
	L(i, 1, n) if(!bmat[i]) ns.push_back(i);
	while(1) {
		bool ok = false;
		vis.reset();
		for(int x : ns) vis |= e[x];
		for(int &x : ns) if(vis[x]) {
			ok = true;
			for(; vis[x]; x = mat[x]) ;
		}
		if(!ok) break;
	}
	cout << n - ans << "\n";
	for(int x : ns) cout << x << " ";
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n, a[N], x, y, ano;
int vis[N], ns[N], o[N], tot;
vector<int> s[N];
queue<int> q[N];
int rmain() {
	cin >> n >> x >> y, y -= x, tot = 0;
	L(i, 1, n + 1) vis[i] = ns[i] = 0, s[i].clear();
	L(i, 1, n) while(!q[i].empty()) q[i].pop();
	L(i, 1, n) cin >> a[i], ++ vis[a[i]], s[a[i]].push_back(i);
	L(i, 1, n + 1) q[vis[i]].push(i);
	L(i, 1, n + 1) if(!vis[i]) ano = i;
	int p = n, sp = 0;
	while(x--) {
		while(q[p].empty()) --p;
		int u = q[p].front();
		--vis[u], ns[s[u][p - 1]] = u, q[p - 1].push(u), q[p].pop();
	}
	// L(i, 1, n) cout << ns[i] << " ";
	// cout << "\n";
	L(i, 1, n + 1) if(vis[i]) o[++tot] = i;
	sort(o + 1, o + tot + 1, [&] (int a, int b) {
		return vis[a] > vis[b];
	});
	p = 1;
	L(i, 2, tot) L(j, 0, vis[o[i]] - 1) if(y) {
		ns[s[o[i]][j]] = o[p], ++sp, --y;
		if(sp == vis[o[p]]) ++p, sp = 0;
	}
	if(p == 1) p = 2, sp = 0;
	L(i, 0, vis[o[1]] - 1) if(y) {
		if(p > tot) return cout << "NO\n", 0;
		ns[s[o[1]][i]] = o[p], ++sp, --y;
		if(sp == vis[o[p]]) ++p, sp = 0;
	}

	L(i, 1, n) if(!ns[i]) ns[i] = ano;
	cout << "YES\n";
	L(i, 1, n) cout << ns[i] << " ";
	cout << "\n";
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) rmain();
	return 0;
}
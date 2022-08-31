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
const int N = 5e5 + 7;
int n, m, w[N], ns[N], tot;
set < pii > e[N];
queue<int> q;
bool vis[N];
int rmain() {
	cin >> n >> m;
	L(i, 1, n) cin >> w[i];
	L(t, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].insert(mkp(v, t)), e[v].insert(mkp(u, t));
	}
	L(i, 1, n) if(sz(e[i]) <= w[i]) q.push(i), vis[i] = true;
	while(! q.empty()) {
		int u = q.front();
		q.pop();
		for(pii v : e[u]) {
			e[v.x].erase(mkp(u, v.y)), ns[++tot] = v.y;
			if(!vis[v.x] && sz(e[v.x]) <= w[v.x]) q.push(v.x), vis[v.x] = true;
		}
		e[u].clear();
	}
	if(tot == m) {
		cout << "ALIVE\n";
        R(i, tot, 1) cout << ns[i] << " ";
		cout << "\n";
	}
	else cout << "DEAD\n";
    return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	rmain();	
	return 0;
}
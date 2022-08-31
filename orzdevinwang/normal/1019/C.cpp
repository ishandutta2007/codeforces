#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int head[N], edge_id, cnt;
struct edge {
	int to, next;
} e[N];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
int n, m;
bool vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		int u, v; 
		cin >> u >> v;
		add_edge(u, v);
	}
	L(x, 1, n) if(!vis[x]) for(int i = head[x]; i; i = e[i].next) if(e[i].to > x) vis[e[i].to] = 1;
	R(x, n, 1) if(!vis[x]) for(int i = head[x]; i; i = e[i].next) vis[e[i].to] = 1;
	L(x, 1, n) if(!vis[x]) ++cnt;
	cout << cnt << "\n";
	L(x, 1, n) if(!vis[x]) cout << x << " ";
	cout << "\n";
	return 0;
}
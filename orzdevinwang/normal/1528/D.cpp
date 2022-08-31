#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 607;
int n, m;
ll e[N][N], w[N][N];
ll dis[N];
bool vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(e, 0x3f, sizeof(e));
	memset(w, 0x3f, sizeof(w));
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a][b] = c; 
	}
	L(i, 0, n - 1) 
		L(j, 0, n - 1) 
			L(k, 0, n - 1) 
				w[i][j] = min(w[i][j], (j + n - k) % n + e[i][k]);
	L(a, 0, n - 1) {
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		dis[a] = 0;
		L(t, 0, n - 1) {
			int u = -1;
			L(i, 0, n - 1) if(vis[i] == 0 && (u == -1 || dis[i] < dis[u]))	u = i;
			vis[u] = true;
			L(i, 0, n - 1) 
				dis[i] = min(dis[i], dis[u] + w[u][(i - dis[u] % n + n) % n]);
		}
		
		L(i, 0, n - 1) cout << dis[i] << " ";
		cout << "\n";
	}
	return 0;
}
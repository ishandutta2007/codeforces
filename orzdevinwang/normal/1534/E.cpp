#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7;
int n, k, dis[N], las[N], use[N], road[N];
bool vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);  
	cin >> n >> k, memset(dis, 0x3f, sizeof(dis));
	queue < int > q;
	q.push(0), dis[0] = 0, las[0] = -1; // 0  
	while(!q.empty()) {
		int u = q.front(), v;
		q.pop();
		L(j, max(0, u + k - n), min(u, k)) {
			v = u + k - j * 2;
			if(dis[v] > n) dis[v] = dis[u] + 1, las[v] = u, use[v] = j, q.push(v);
		}
	}
	if(dis[n] > n) cout << "-1" << endl;
	else {
		int ns = 0, init;
		for(int x = n; x != -1; x = las[x]) road[dis[x]] = x;
		L(i, 1, dis[n]) {
			int x[2] = {k - use[road[i]], use[road[i]]};
			cout << "? ";
			L(j, 1, n) if(x[vis[j]]) cout << j << " ", x[vis[j]]--, vis[j] ^= 1; 
			cout << endl, cin >> init, ns ^= init;
		}
		cout << "! " << ns << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1007;
int n, m;
queue < int > q;
vi e[N];
int dis1[N][N];
int dis2[N][N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	L(i, 1, n) dis1[i][i] = dis2[i][i] = 0;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		dis1[u][v] = dis1[v][u] = 1;
	}
	L(i, 1, n) 
		L(j, i + 1, n) 
			if(dis1[i][j] != 1) 
				dis2[i][j] = dis2[j][i] = 1;
	// L(i, 1, n) {
	// 	L(j, 1, n) {
	// 		cout << dis1[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }
	L(k, 1, n) 
		L(i, 1, n) 
			L(j, 1, n) 
				dis1[i][j] = min(dis1[i][j], dis1[i][k] + dis1[k][j]), 
				dis2[i][j] = min(dis2[i][j], dis2[i][k] + dis2[k][j]);
	int ns = max(dis1[1][n], dis2[1][n]);
	if(ns > n) cout << -1 << '\n';
	else cout << ns << '\n';
	return 0;
}
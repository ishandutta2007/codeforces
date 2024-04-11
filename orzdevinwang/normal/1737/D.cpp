#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
using namespace std;
const int N = 507;
int n, m, eu[N * N], ev[N * N], ew[N * N];
int dis[N][N]; 
void Main() {
	cin >> n >> m;
	me(dis, 0x3f);
	L(i, 1, n) dis[i][i] = 0;
	L(i, 1, m) {
		cin >> eu[i] >> ev[i] >> ew[i];
		dis[eu[i]][ev[i]] = dis[ev[i]][eu[i]] = 1;
	}
	L(k, 1, n) 
		L(i, 1, n) 
			L(j, 1, n) 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	ll ns = 1e18;
	L(i, 1, m) {
		int k = dis[eu[i]][1] + dis[ev[i]][n];
		k = min(k, dis[eu[i]][n] + dis[ev[i]][1]);
		L(c, 1, n) 
			k = min(k, min(dis[eu[i]][c], dis[ev[i]][c]) + dis[1][c] + dis[c][n] + 1);
		ns = min(ns, (ll)ew[i] * (k + 1));
	} 
	cout << ns << '\n';
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
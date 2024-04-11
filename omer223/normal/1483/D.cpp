
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int sz = 6e2 + 5;
int n, m, q;
ll adj[2 * sz][2 * sz];
vector<pair<pii, int>> e;


int main() {
	//fast;
	scanf("%d %d", &n, &m);
	foru(i, 0, 2*n) {
		foru(j, 0, 2*n)adj[i][j] = 1e15;
		adj[i][i] = 0;
	}
	foru(i, 0, m) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		adj[--x][--y] = w;
		adj[y][x] = w;
		adj[x + n][y + n] = w;
		adj[y + n][x + n] = w;
		e.pb({ { x,y },w });
	}
	scanf("%d", &q);
	foru(i, 0, q) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		adj[--x][--y + n] = -w;
		adj[y][x + n] = -w;
	}
	foru(k, 0, 2 * n) {
		foru(i, 0, 2 * n) {
			foru(j, 0, 2 * n) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int cnt = 0;
	for (auto &ii : e) {
		if (adj[ii.ff.ff][ii.ff.ss + n] + ii.ss <= 0)
			cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
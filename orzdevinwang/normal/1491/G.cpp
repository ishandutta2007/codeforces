#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, a[N], cnt, bel[N];
vi hs[N];

void swp(int u, int v) {
	cout << u << " " << v << "\n", swap(a[u], a[v]), a[u] = -a[u], a[v] = -a[v];
}

void mg(int x, int y) {
	int su = sz(hs[x]), sv = sz(hs[y]);
	int u = hs[x][0], v = hs[y][0];
	swp(u, v);
	L(i, 1, sv - 1) swp(u, hs[y][i]);
	L(i, 1, su - 1) swp(v, hs[x][i]);
	swp(u, v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) if(!bel[i]) {
		int now = i;
		++cnt;
		while(!bel[now]) bel[now] = cnt, hs[cnt].push_back(now), now = a[now];
	}
	cout << n + (cnt % 2) << "\n";
	if(cnt == 1) {
		swp(hs[1][0], hs[1][1]);
		L(i, 2, n - 2) swp(hs[1][0], hs[1][i]);
		int a = hs[1][0], b = hs[1][1], c = hs[1][n - 1]; 
		swp(b, c), swp(a, c), swp(a, b);
	}
	else {
		L(i, 1, cnt / 2) 
			mg(i * 2 - 1, i * 2);
		if(cnt % 2 == 1) 
			hs[1].clear(), hs[1].push_back(1), mg(1, cnt);
	}
//	L(i, 1, n) cout << a[i] << " ";
	return 0;
}
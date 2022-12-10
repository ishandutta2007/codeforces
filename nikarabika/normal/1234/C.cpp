//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1e6;
int ty[2][maxn],
	n;

int change(pii pos, pii prv) {
	int x = pos.L,
		y = pos.R;
	if (ty[x][y] <= 2)
		return ty[x][y] = (prv.R == y - 1 ? 2 : -1);
	if (prv.L == x - 1)
		return ty[x][y] = 6;
	if (prv.L == x + 1)
		return ty[x][y] = 3;
	return ty[x][y] = 4 + x;
}

pii get_out(int x, int y) {
	if (ty[x][y] <= 2)
		return MP(x, y + 1);
	if (x == 0)
		return ty[x][y] == 3 ? MP(x, y + 1) : MP(x + 1, y);
	if (x == 1)
		return ty[x][y] == 6 ? MP(x, y + 1) : MP(x - 1, y);
}

int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		ty[0][i] = c - '0';
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		ty[1][i] = c - '0';
	}
	pii pos(0, 0);
	pii prv(0, -1);
	while (pos.R != n) {
		change(pos, prv);
		if (ty[pos.L][pos.R] == -1)
			return cout << "NO\n", 0;
		prv = pos;
		pos = get_out(pos.L, pos.R);
	}
	cout << (pos.L ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}
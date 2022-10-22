#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
const int N = 1005;
int n, e[N][N], ty;
vector <pair <int, int>> A, B;
void flip(int a, int b) {
	int x;
	rep(i, 1, n) if(e[a][i] && e[b][i]) x = i;
	e[a][b] = e[b][a] = 0, e[1][x] = e[x][1] = 1;
	ty ? B.eb(1, x) : A.eb(a, b);
}
void solve() {
	mem(e, 0);
	rep(i, 1, n) {
		int j = i > 1 ? i - 1 : n;
		e[i][j] = e[j][i] = 1;
	}
	int u, v;
	rep(i, 1, n - 3) scanf("%d%d", &u, &v), e[u][v] = e[v][u] = 1;
	rep(i, 2, n) if(!e[1][i]) {
		int j = i;
		while(!e[1][j]) j++;
		flip(--i, j);
	}
}
int main() {
	cin >> n;
	solve(), ty = 1, solve();
	A.insert(A.end(), B.rbegin(), B.rend());
	cout << A.size() << endl;
	for(auto [u, v] : A) printf("%d %d\n", u, v);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, M, R, dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0}, mem[1000005];
char F[1005][1005], V[1000005], _F[1000005];
vector<int> adj[1000005];
map<char, char> nxt;
bool inv;

inline int u(int r, int c) {
	return (r - 1) * M + c;
}

void dfs(int n) {
	if (V[n] == 1) {
		inv = 1;
		return;
	}
	if (V[n] == 2) return;
	V[n] = 1;
	for (auto u : adj[n])
		dfs(u);
	V[n] = 2;
}

int dp(int n) {
	if (mem[n] != -1) return mem[n];
	mem[n] = 0;
	for (auto u : adj[n])
		mem[n] = max(mem[n], dp(u));
	mem[n] += _F[n] == 'A';
	return mem[n];
}

main() {
	memset(mem, -1, sizeof mem);
	nxt['D'] = 'I';
	nxt['I'] = 'M';
	nxt['M'] = 'A';
	nxt['A'] = 'D';
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> F[i][j];
			_F[u(i, j)] = F[i][j];
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int k = 0; k < 4; k++)
				if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && nxt[F[i][j]] == F[i + dr[k]][j + dc[k]])
					adj[u(i, j)].pb(u(i + dr[k], j + dc[k]));
	for (int i = 1; i <= N * M; i++) dfs(i);
	if (inv) return cout << "Poor Inna!\n", 0;
	for (int i = 1; i <= N * M; i++)
		if (_F[i] == 'D') R = max(R, dp(i));
	if (R == 0) cout << "Poor Dima!\n";
	else cout << R << '\n';
}
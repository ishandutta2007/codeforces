#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
typedef long double ld;

int N;
bool inv, V[205], C[205];
char S[205];
vector<int> adj[205];

void dfs(int n) {
	if (V[n]) return;
	V[n] = 1;
	for (auto u : adj[n])
		if (V[u] && C[n] == C[u]) inv = 1;
		else C[u] = !C[n], dfs(u);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			if (S[j] < S[i]) adj[i].pb(j);
	for (int i = 1; i <= N; i++) dfs(i);
	if (inv) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 1; i <= N; i++) cout << C[i];
	cout << '\n';
}
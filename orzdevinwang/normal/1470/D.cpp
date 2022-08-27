#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, orz[N], flag[N], cnt, sum;
vector<int> e[N];
void dfs(int x) {
	++cnt, flag[x] = 1, orz[x] = 1;
	for(int v : e[x]) if(flag[v]) orz[x] &= (1 ^ orz[v]);
	sum += orz[x];
	for(int v : e[x]) if(!flag[v]) dfs(v);
}
void Main() {
	cin >> n >> m, cnt = sum = 0;
	L(i, 1, n) e[i].clear(), flag[i] = 0;
	L(i, 1, m) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	dfs(1);
	if(cnt != n) return cout << "NO\n", void();
	cout << "YES\n";
	cout << sum << endl;
	L(i, 1, n) if(orz[i]) cout << i << " ";
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) Main();
	return 0;
}
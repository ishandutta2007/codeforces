#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 4e5 + 7;

int n, cnt[N], col[N];
vi e[N];
void dfs(int x) {
	cnt[col[x]]++;
	for(const int &v : e[x]) if(!col[v]) col[v] = 3 - col[x], dfs(v);
}
int main() {  
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	col[1] = 1, dfs(1);
	cout << min(cnt[1], cnt[2]) - 1 << '\n';
	return 0;
}
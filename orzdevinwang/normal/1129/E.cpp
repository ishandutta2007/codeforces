#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, ord[N], sz[N], cp;
vector < pair < int, int > > pr;
bool vis[N];
void dfs(int l, int r) {
	int cnt = 0;
	L(i, l, r) if(!vis[i]) cnt += 1;
	if(!cnt) return ; 
	cout << 1 << '\n' << 1 << '\n';
	cout << cnt << '\n';
	L(i, l, r) if(!vis[i]) cout << ord[i] << ' ';
	cout << '\n' << cp << endl;
	int w;
	cin >> w;
	if(!w) return ;
	if(l == r) return pr.push_back({cp, ord[l]}), vis[l] = true, void();
	int mid = (l + r) >> 1;
	dfs(l, mid), dfs(mid + 1, r);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 2, n) {
		cout << 1 << '\n' << 1 << '\n' << n - 1 << '\n';
		L(j, 2, n) cout << j << ' ';
		cout << '\n';
		cout << i << endl;
		cin >> sz[i];
	}
	sz[1] = n;
	L(i, 1, n) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return sz[x] > sz[y];
	});
	R(i, n - 1, 2) cp = ord[i], dfs(i + 1, n);
	L(i, 2, n) if(!vis[i]) pr.push_back({1, ord[i]});
	cout << "ANSWER\n";
	for(auto u : pr) cout << u.first << ' ' << u.second << '\n';
	return 0;
}
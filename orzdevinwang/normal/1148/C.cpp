#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
int n, m, k, ta, tb, a[N], b[N], mp[N];
int To[N];
vector<pii> ans;
void swp(int x, int y, int g) {
	ans.push_back(mkp(y, g)), swap(a[y], a[g]); // x, g, y
	ans.push_back(mkp(x, g)), swap(a[x], a[g]); // y, g, x
	ans.push_back(mkp(y, g)), swap(a[y], a[g]); // y, x, g
}
void work(int x, int y) {
	if(x == y) return;
	if(x > y) swap(x, y);
	if((y - x) * 2 >= n) return ans.push_back(mkp(x, y)), swap(a[x], a[y]), void();
	if(y <= n / 2) return swp(x, y, n);
	if(x > n / 2) return swp(x, y, 1);
	ans.push_back(mkp(x, n)), swap(a[x], a[n]); // 1 n y x
	ans.push_back(mkp(n, 1)), swap(a[n], a[1]); // x n y 1
	ans.push_back(mkp(1, y)), swap(a[1], a[y]); // y n x 1
	ans.push_back(mkp(1, n)), swap(a[1], a[n]); // 1 n x y
	ans.push_back(mkp(x, n)), swap(a[x], a[n]); // 1 y x n
}
int gs;
void dfs(int x) {
	if(a[x] == gs) return;
	int tmp = a[x];
	dfs(tmp);
	work(x, tmp);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) if(i != a[i]) {
		gs = i;
		dfs(i);
	}
	cout << (int)ans.size() << endl;
	for(pii g : ans) cout << g.first << " " << g.second << endl;
	return 0;
}
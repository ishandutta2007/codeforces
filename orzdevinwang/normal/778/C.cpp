#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 6e5 + 7;
int n, m, ch[N][26], cnt[N], dep[N], sum, tot, ans;
int merge(int x, int y) {
	if(!x || !y) return x | y;
	++sum;
	int nw = ++tot;
	L(i, 0, 25) ch[nw][i] = merge(ch[x][i], ch[y][i]);
	return nw;
}
void dfs(int x) {
	int now = 0; tot = n, sum = 0;
	L(i, 0, 25) if(ch[x][i]) now = merge(ch[x][i], now);
	if(now) cnt[dep[x]] += sum + 1; 
	L(i, 0, 25) if(ch[x][i]) dep[ch[x][i]] = dep[x] + 1, dfs(ch[x][i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v; char C[10];
		cin >> u >> v >> C;
		ch[u][C[0] - 'a'] = v;
	}
	dep[1] = 1, dfs(1);
	L(i, 1, n) if(cnt[i] > cnt[ans]) ans = i;
	cout << n - cnt[ans] << endl << ans << endl;
	return 0;
}
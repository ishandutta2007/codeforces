#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1005;
int n, m, a[N], b[N], dp[N][N], arr[N], ans, p1, p2, atot, tot, f[N], s[N][N];
vector< pii > ve[N];
void add(int x, int y, int w) {
	for(int i = x; i <= atot; i += (i & -i)) for(int j = y; j <= m; j += (j & -j)) s[i][j] = max(s[i][j], w);
}
int qry(int x, int y) {
	int res = 0;
	for(int i = x; i; i -= (i & -i)) for(int j = y; j; j -= (j & -j)) res = max(res, s[i][j]);
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], arr[++atot] = a[i];
	cin >> m;
	L(i, 1, m) cin >> b[i], arr[++atot] = b[i];
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
	L(i, 1, m) b[i] = lower_bound(arr + 1, arr + atot + 1, b[i]) - arr;
	L(i, 1, n) {
		L(j, 1, m) if(a[i] == b[j]) {
			dp[i][j] = qry(a[i] - 1, j - 1) + 1, ve[dp[i][j]].push_back(mkp(i, j));
			if(dp[i][j] > ans) ans = dp[i][j], p1 = i, p2 = j;
		}
		L(j, 1, m) add(a[i], j, dp[i][j]);
	}
	if(!ans) return cout << "0\n", 0;
	f[++tot] = a[p1];
	R(i, ans - 1, 1) for(pii q : ve[i]) if(q.first < p1 && q.second < p2 && a[q.first] < a[p1]) 
		p1 = q.first, p2 = q.second, f[++tot] = a[p1];
	reverse(f + 1, f + tot + 1);
	cout << tot << "\n";
	L(i, 1, tot) cout << arr[f[i]] << " ";
	return 0;
}
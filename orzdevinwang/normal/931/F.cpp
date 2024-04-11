#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, m, l[N], r[N], cnt[N], ans;
int sz[N], dp[N], pd[N];
void ad(int pos, int w) {
	pos ++;
	for(; pos <= n + 1; pos += (pos & -pos)) sz[pos] = max(sz[pos], w);
}
int qry(int pos) {
	pos ++;
	int mx = 0;
	for(; pos; pos -= (pos & -pos)) mx = max(mx, sz[pos]);
	return mx;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) 
		cin >> l[i] >> r[i], cnt[l[i]] ++, cnt[r[i] + 1] --;
	L(i, 1, m) cnt[i] += cnt[i - 1];
	memset(sz, 0, sizeof(sz));
	L(i, 1, m) if(cnt[i] != n) dp[i] = qry(cnt[i]) + 1, ad(cnt[i], dp[i]);
	memset(sz, 0, sizeof(sz));
	R(i, m, 1) if(cnt[i] != n) pd[i] = qry(cnt[i]) + 1, ad(cnt[i], pd[i]), ans = max(ans, pd[i] + dp[i] - 1);
	cout << ans << "\n";
	return 0;
}
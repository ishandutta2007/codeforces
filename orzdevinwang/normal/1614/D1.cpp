#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e7 + 7, M = 2e5 + 7, Mod = 1e9 + 1;
int n, a[M], mx, cnt[N], lst[N], ne[N];
bool Prime[N];
int p[N >> 3], tot;
void xxs (int n) {
	L(i, 2, n) {
		if(!Prime[i]) p[++tot] = i, lst[i] = i, ne[i] = 1;
		for (int j = 1; p[j] * i <= n && j <= tot; ++j) {
			Prime[p[j] * i] = true;
			lst[p[j] * i] = p[j];
			if(i % p[j] == 0) {
				lst[p[j] * i] = p[j];
				ne[p[j] * i] = ne[i];
				break;
			}
			ne[p[j] * i] = i;
		}
	}
}
ll dp[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	xxs (N - 7);
	cin >> n;
	int g = 0;
	L(i, 1, n) cin >> a[i], g = __gcd(a[i], g), cnt[a[i]] += 1, mx = max(mx, a[i]);
	memset(dp, -0x3f, sizeof(dp));
	dp[g] = (ll) g * n;
	L(i, 1, tot) 
		R(j, mx / p[i], 1) 
			cnt[j] += cnt[j * p[i]];
	L(i, 1, mx) 
		for (int u = i; u > 1; u = ne[u]) dp[i] = max(dp[i], dp[i / lst[u]] + (ll) cnt[i] * (i - i / lst[u]));
	ll ret = 0;
	L(i, 1, mx) ret = max(ret, dp[i]);
	cout << ret << '\n';
	return 0;
}
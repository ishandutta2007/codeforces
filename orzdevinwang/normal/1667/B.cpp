#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
int n, a[N], ip[N], dp[N];
ll pre[N], arr[N], atot;

int f[N];
int c[N];
void add(int p, int w) {
	for(; p <= atot; p += p & -p) 
		c[p] = max(c[p], w);
}
int query(int p) {
	int ret = -1e9;
	for(; p; p -= p & -p) ret = max(ret, c[p]);
	return ret;
}

void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	atot = 0;
	L(i, 0, n) arr[++atot] = pre[i];
	sort(arr + 1, arr + atot + 1);
	L(i, 0, n) ip[i] = lower_bound(arr + 1, arr + atot + 1, pre[i]) - arr;
	L(i, 1, atot) f[i] = c[i] = -1e9;
	dp[0] = 0, add(ip[0], 0), f[ip[0]] = 0;
	L(i, 1, n) {
		dp[i] = query(ip[i] - 1) + i;
		dp[i] = max(dp[i], f[ip[i]]);
		dp[i] = max(dp[i], dp[i - 1] - 1);
		f[ip[i]] = dp[i];
		add(ip[i], dp[i] - i);
	}
	cout << dp[n] << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}
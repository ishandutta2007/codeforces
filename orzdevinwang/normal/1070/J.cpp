#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, M = 2e5 + 7;
int n, m, k, cnt[N];
char s[N];
bool dp[M];
void Main () {
	L(i, 0, 25) cnt[i] = 0;
	cin >> n >> m >> k;
	cin >> (s + 1);
	L(i, 1, k) 
		cnt[s[i] - 'A'] += 1;
	int ns = 1e9;
	// case1 : ans = 0
	L(u, 0, 25) {
		L(j, 0, k) dp[j] = false;
		dp[0] = true;
		L(x, 0, 25) if(x != u) R(j, k, cnt[x]) dp[j] |= dp[j - cnt[x]];
		L(i, max (0, n - cnt[u]), n) if(dp[i] && k - cnt[u] - i >= m) 
			return cout << 0 << '\n', void ();
	}
	// case2 : ans neq 0
	L(u, 0, 25) {
		L(j, 0, k) dp[j] = false;
		dp[0] = true;
		L(x, 0, 25) if(x != u) R(j, k, cnt[x]) dp[j] |= dp[j - cnt[x]];
		L(i, 0, n) if(dp[i]) {
			int a = n - i, b = m - (k - i - cnt[u]);
			if(a >= 0 && b >= 0) 
				ns = min(ns, a * b);
		}
	}
	cout << ns << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
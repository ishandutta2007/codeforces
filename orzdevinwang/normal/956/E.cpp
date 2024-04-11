#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 10009;
int n, suf[N], l, r, ns;
bitset < N > dp[2];
struct node {
	int h, op;
} s[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	L(i, 1, n) cin >> s[i].h;
	L(i, 1, n) cin >> s[i].op;
	sort(s + 1, s + n + 1, [&] (node x, node y) {
		return x.op == y.op ? x.h > y.h : x.op < y.op;
	});
	R(i, n, 1) 
		suf[i] = suf[i + 1] + s[i].h;
	dp[0].set(0);
	s[n + 1].op = true;
	L(i, 0, n) {
		if(i) {
			dp[1] |= dp[1] << s[i].h;
			if(s[i].op) dp[1] |= dp[0];
			dp[0] |= dp[0] << s[i].h;
		}
		if(s[i + 1].op) {
			L(t, 0, 1) 
				L(j, l, r - suf[i + 1]) 
					if(dp[t][j]) 
						ns = max(ns, n - i + t);
		}

	}
	cout << ns << "\n";
	return 0;
}
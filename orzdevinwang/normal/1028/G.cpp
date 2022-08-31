#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
#define i128 __int128 
using namespace std;
const int N = 1e4 + 7, xn = 1e4;
int n;
const ll M = 10004205361450474;
ll pw[N], val[N];
i128 dp[10][N];
void calc(int v, ll l) {
	int mn = min(l, (ll) xn); 
	ll cur = (l <= xn ? dp[v + 1][l] : l + pw[4 - v] - 1);
	val[0] = l - 1;
	L(t, 1, mn) {
		val[t] = cur + 1;
		if(cur < xn - 1) {
			cur = dp[v + 1][cur + 2];
		} else {
			cur += 1 + pw[4 - v];
		}
	}
	cout << mn << ' ';
	L(i, 1, mn) cout << val[i] << ' ';
	cout << endl;
	int t = 0;
	cin >> t;
	if(t == -1) return ;
	calc(v + 1, val[t] + 1); 
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	pw[0] = 0;
	L(i, 1, 4) pw[i] = pw[i - 1] * (xn + 1) + xn;
	L(j, 1, xn) dp[5][j] = j - 1;
	R(i, 4, 0) {
		L(j, 1, xn) {
			i128 cur = dp[i + 1][j];
			L(t, 1, j) {
				if(cur < xn - 1) {
					cur = dp[i + 1][cur + 2];
				} else {
					cur += 1 + pw[4 - i];
				}
			}
			dp[i][j] = cur;
		}
	}
	calc(0, 1);
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
#define rs(x) resize(x)
using namespace std;
const int N = 17;
int n, r[N], b[N], nsa, nsb; 
char s[N][5];
int dp[1 << N][N * N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 0, n - 1) {
		cin >> (s[i] + 1);
		cin >> r[i] >> b[i];
		if(r[i] > n) nsa += r[i] - n, r[i] = n;
		if(b[i] > n) nsb += b[i] - n, b[i] = n;
	}
	me(dp, 0x3f);
	dp[0][0] = 0;
	L(i, 0, (1 << n) - 1) {
		int cntr = 0, cntb = 0;
		L(j, 0, n - 1) if(i >> j & 1) {
			if(s[j][1] == 'R') cntr += 1;
			else cntb += 1;
		}
		L(w, 0, n * n) if(dp[i][w] < 1e9) {
			L(j, 0, n - 1) if(!(i >> j & 1)) {
				int wa = max(r[j] - cntr, 0);
				int wb = max(b[j] - cntb, 0);
				dp[i | (1 << j)][w + wa] = min(dp[i | (1 << j)][w + wa], dp[i][w] + wb);
			}
		} 
	}
	int ret = 1e9;
	L(i, 0, n * n) 
		ret = min(ret, max(i + nsa, dp[(1 << n) - 1][i] + nsb));
	cout << ret + n << '\n';
	return 0;
}
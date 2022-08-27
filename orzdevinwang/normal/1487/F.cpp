#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 5007, M = N * 233, inf = 998244353;
char ss[N];
int n, qwq[N], v[N], a[N]; 
int dp[N][2], new_dp[N][2];
int slv[M * 2], *f = slv + M;
void Main() {
	me(a, 0), me(v, 0), me(qwq, 0);
	cin >> (ss + 1), n = strlen(ss + 1);
	L(i, 0, n - 1) v[i] = ss[n - i] - '0';
	R(i, n - 1, 0) {
		int c = v[i] - 1;
		if(c >= 10) c -= 1;
		a[i] = c;
		R(j, i, 0) v[j] -= c;
		L(j, 0, i) if(v[j] < 0) v[j] += 10, v[j + 1] -= 1;
		while(true) {
			bool ok = true;
			R(j, i, 0) if(v[j] != 1) {
				ok = v[j] > 1;
				break ;
			}
			if(ok) {
				a[i] += 1;
				R(j, i, 0) v[j] -= 1;
				L(j, 0, i + 1) if(v[j] < 0) v[j] += 10, v[j + 1] -= 1;
			} else break;
		}
		if(i) v[i - 1] += v[i] * 10, v[i] = 0;
	}
	me(dp, 0x3f); 
	int lim = 0, curs = 1;
	while(curs <= n) curs *= 10, lim += 1;
	lim = min(lim, n);
	dp[0][0] = 0;
	R(i, n, lim + 1) {
		me(new_dp, 0x3f); 
		int p = a[i], xp = p - 10;
		L(j, 0, n) if(dp[j][0] < inf || dp[j][1] < inf) {
			new_dp[j][0] = min(new_dp[j][0], dp[j][0] + (i + 1) * abs(p));
			new_dp[j][1] = min(new_dp[j][1], dp[j][0] + (i + 1) * abs(p + 1));
			new_dp[j + 1][0] = min(new_dp[j + 1][0], dp[j][1] + (i + 1) * abs(xp));
			new_dp[j + 1][1] = min(new_dp[j + 1][1], dp[j][1] + (i + 1) * abs(xp + 1));
		}
		swap(dp, new_dp);
	}
	qwq[0] = 1;
	L(i, 1, lim + 1) qwq[i] = qwq[i - 1] * 10 + 1;
	int len = n * 233;
	L(i, -len, len) f[i] = inf;
	int sum = 0;
	L(i, 0, lim) sum += a[i] * qwq[i];
	L(i, 0, n) L(j, 0, 1) if(dp[i][j] < inf) f[-qwq[lim + 1] * j - i + sum] = dp[i][j];
	 
	R(i, lim, 0) 
		L(j, -len, len - qwq[i]) f[j + qwq[i]] = min(f[j + qwq[i]], f[j] + i + 1);
	R(i, lim, 0) 
		R(j, len, qwq[i] - len) f[j - qwq[i]] = min(f[j - qwq[i]], f[j] + i + 1);
	cout << f[0] << '\n'; 
}
int main () {
//	return system("fc oness.out ones.out"), 0;
	//freopen("ones.in", "r", stdin);
	//freopen("ones.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) Main();
	return 0;
}
/*
W_i = 10W_{i-1}+1
 W_i 
sum t_i W_i = sum a_i W_i 
sum (t_i - a_i) W_i = 0 
 sum_{j >= i} (t_i - a_i)W_i = tW_j + c! 
 0  c <= n DP0 <= t <= 1 
~
~
~
weishenme
zhaobudao
wuwuwu
*/
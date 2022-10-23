#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int n, k, dp[1 << 9], xdp[1 << 9], pc[1 << 9], p[N], ip[N], qr[N];

int sz[N];
void add(int x, int y) {
	for(; x; x -= x & -x) sz[x] += y;
} 
int query(int x) {
	int ret = 0;
	for(; x <= n; x += x & -x) ret += sz[x];
	return ret;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 1, n) cin >> p[i], ip[p[i]] = i;
	L(i, 0, (1 << k) - 1) pc[i] = pc[i >> 1] + (i & 1);
	me(dp, 0x3f), dp[0] = 0;
	L(u, 1, n) {
		int tr = max(u - k, 0);
		if(tr > 0) add(ip[tr], 1);
		L(i, tr + 1, min(n, u + k)) qr[i] = query(ip[i]);
		me(xdp, 0x3f);
		L(i, 0, (1 << k) - 1) if(dp[i] < 1e9) {
			int xk = u - pc[i]; 
//			cout << "xk = " << xk << endl;
			int xi = i * 2;
			L(j, 0, min(k, n - xk)) if(!(xi >> j & 1)) {
				int cnt = dp[i] + qr[j + xk], w = ip[j + xk];
				L(a, tr + 1, xk - 1) cnt += ip[a] > w;
				L(a, 0, k - 1) if(i >> a & 1) cnt += ip[a + xk + 1] > w;
				int tu = xi | (1 << j);
//				cout << "T = " << tu << endl;
				while(tu & 1) tu >>= 1;
				tu >>= 1;
//				cout << "tu = " << tu << endl;
				xdp[tu] = min(xdp[tu], cnt);
			}
		}
		swap(dp, xdp);
	}
	cout << dp[0] << '\n';
	return 0;
}
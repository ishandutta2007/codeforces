#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 4e3 + 7, mod = 1e9 + 7;
int n, m, p, k, s[N], A[N], R[N];
char tmp[N];
int f[N][N][2][2] ; /* ; ; k > n?; n > A?;  */
int pre (int x) { return (ll) x * (x + 1) / 2 % mod; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> p >> k >> (tmp + 1), m = strlen(tmp + 1);
	L(i, 1, m) R[i] = tmp[i] - '0';
	reverse(R + 1, R + m + 1);
	while (m) {
		ll sum = 0;
		R(i, m, 1) sum *= 10, sum += R[i], s[i] = sum / p, sum %= p;
		A[++n] = sum;
		while (s[m] == 0 && m) --m;
		L(i, 1, m) R[i] = s[i], s[i] = 0;
	}
//	L(i, 1, n) cout << A[i] << " ";
//	cout << "\n";
	f[0][0][0][0] = true;
	L(i, 1, n) {
		L(z, 0, i - 1) L(x, 0, 1) L(y, 0, 1) {
			int bu = A[i] - y + 1, l1 = bu, l2 = p - bu;
			// <= bu; > bu; x = false : k > n; k >= n
//			cout << l1 << " " << l2 << "\n";
			L(cn, 0, 1) L(ck, 0, 1) {
				if(cn ^ ck) (f[i][z + (ck > cn)][ck > cn][cn] += (ll) l1 * l2 % mod * f[i - 1][z][x][y] % mod) %= mod;
				else {
					int len = cn ? l2 : l1;
					(f[i][z][0][cn] += (ll) pre (len - x) * f[i - 1][z][x][y] % mod) %= mod;
					(f[i][z + 1][1][cn] += (ll) pre (len - (!x)) * f[i - 1][z][x][y] % mod) %= mod;
				}
			}
//			L(sn, 0, p - 1) L(sk, 0, p - 1) {
//				int vx, vy;
//				if (sk > sn) vx = true;
//				else if (sn == sk && x == true) vx = true;
//				else vx = false;
//				if (sn >= bu) vy = true;
//				else vy = false;
//				(f[i][z + vx][vx][vy] += f[i - 1][z][x][y]) %= mod;
//			}
		}
	}
	int ns = 0;
	L(i, k, n) (ns += f[n][i][0][0]) %= mod;
	cout << ns << "\n";
	return 0;
}
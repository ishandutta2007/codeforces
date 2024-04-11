#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 507, mod = 998244353;
int n, m, a[N][N], pre[N], nfl[N], cw[N], b[N][N];
char s[N][N];
void Main () {
	cin >> n >> m;
	L(i, 1, n) 
		cin >> (s[i] + 1);
	L(i, 1, n) L(j, 1, m) a[i][j] = b[i][j] = s[i][j] - '0';
	L(i, 1, n) L(j, 1, m) b[i][j] += b[i - 1][j];
	int ns = 1e9;
	L(i, 1, n) {
		L(j, i + 4, n) {
			L(k, 1, m) pre[k] = b[j - 1][k] - b[i][k], nfl[k] = j - i - 1 - pre[k], pre[k] += pre[k - 1];
			L(k, 1, m) cw[k] = 2 - a[i][k] - a[j][k], cw[k] += cw[k - 1];
			int ret = 1e9;
			L(t, 4, m) {
				int k = t - 3;
				ret = min(ret, nfl[k] - pre[k] - cw[k]);
				ns = min(ns, ret + (nfl[t] + pre[t - 1] + cw[t - 1]));
			}
		}
	}
	cout << ns << "\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}
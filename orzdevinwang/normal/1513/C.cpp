#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define mkp make_pair
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, mod = 1e9 + 7;
int n, m, f[N][10];
int rmain() {
	cin >> n >> m;
	int c = n, ns = 0;
	while(c) (ns += f[m][c % 10]) %= mod, c /= 10;
	cout << ns << "\n";
	return 0;
}
void init() {
	L(i, 0, 9) f[0][i] = 1;
	L(t, 1, 200000) {
		L(i, 0, 8) f[t][i] = f[t - 1][i + 1];
		f[t][9] = (f[t - 1][0] + f[t - 1][1]) % mod;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}
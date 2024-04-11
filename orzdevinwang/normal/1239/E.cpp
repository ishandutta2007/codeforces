#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 52, M = 50005;
int n, f[N], sum, maxn, ns[2][N], tp0, tp1, used;
bitset < N * M > vc[N][N >> 1];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, tp0 = 2, tp1 = n - 1;
	L(i, 1, n * 2) cin >> f[i];
	sort(f + 1, f + n * 2 + 1), reverse(f + 1, f + n * 2 + 1);
	ns[0][1] = f[n * 2 - 1], ns[1][n] = f[n * 2], --n, vc[0][0][0] = 1, used = n;
	L(i, 1, n * 2) {
		sum += f[i];
		L(j, 0, n) vc[i][j] = vc[i - 1][j];
		L(j, 1, n) vc[i][j] |= (vc[i - 1][j - 1] << f[i]);
	}
	L(i, 0, sum / 2) if(vc[n * 2][n][i]) maxn = i;
	R(i, n * 2, 1) if(vc[i - 1][used][maxn]) ns[1][tp1--] = f[i];
	else ns[0][tp0++] = f[i], maxn -= f[i], --used;
	L(i, 1, n + 1) cout << ns[0][i] << ' ';
	cout << '\n';
	L(i, 1, n + 1) cout << ns[1][i] << ' ';
	return 0;
}
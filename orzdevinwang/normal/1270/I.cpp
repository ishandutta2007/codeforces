#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 10, M = 100, mod = 998244353;
int n, m, msk, x[M], y[M];
ll a[1 << N][1 << N], rns[1 << N][1 << N], ns[1 << N][1 << N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, msk = (1 << n) - 1;
	L(i, 0, msk) 
		L(j, 0, msk) 
			cin >> a[i][j], ns[i][j] = a[i][j];
	cin >> m;
	L(i, 1, m) 
		cin >> x[i] >> y[i];
	L(t, 0, n - 1) {
		L(i, 0, msk) 
			L(j, 0, msk) 
				L(k, 1, m) 
					rns[(i + (x[k] << t)) & msk][(j + (y[k] << t)) & msk] ^= ns[i][j];
		L(i, 0, msk) 
			L(j, 0, msk) 
				ns[i][j] = rns[i][j], rns[i][j] = 0;
	}
	int cnt = 0;
	L(i, 0, msk) 
		L(j, 0, msk) 
			cnt += !!ns[i][j];
	cout << cnt << '\n';
	return 0;
}
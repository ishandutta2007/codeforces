#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1007;
int n, a[N][N], w[N][N];
bitset < N > f[N];
int gs[N];
void Guess (bitset < N > h, int w) {
	R(i, n, 1) if(h[i]) {
		if(!f[i][i]) f[i] = h, gs[i] = w;
		h ^= f[i], w ^= gs[i];
	}
//	assert (w);
}
void Main () {
	cin >> n;
	L(i, 1, n) {
		L(j, 1, n) {
			cin >> a[i][j];
		}
	}
	L(i, 1, n - 1) {
		L(j, 1, n) {
			w[i + 1][j] = a[i][j] ^ w[i - 1][j] ^ w[i][j - 1] ^ w[i][j + 1];
		} 
	}
	int ns = 0;
	L(i, 1, n) L(j, 1, n) ns ^= w[i][j]; 
	cout << ns << '\n';
	L(i, 1, n) L(j, 1, n) w[i][j] = 0;
}
int main () { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}
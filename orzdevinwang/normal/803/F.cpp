#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7, mod = 1e9 + 7;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int f[N], n, cnt[N], a[N], pw[N], ns;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, pw[0] = 0;
	L(i, 1, n) cin >> a[i], pw[i] = (pw[i - 1] * 2 + 1) % mod, cnt[a[i]] ++;
	L(i, 1, 1e5) L(j, 1, 1e5 / i) (f[i] += cnt[i * j]) %= mod; 
	L(i, 1, 1e5) f[i] = pw[f[i]];	
	R(i, 1e5, 1) 
		L(j, 2, 1e5 / i) (f[i] += mod - f[i * j]) %= mod;	
	cout << f[1] << "\n";
	return 0;
}
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
int n, h[N], f[N], a[N], ns;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		a[i] = ((ll) a[i - 1] * 2 + 1) % mod;
		cin >> h[i];
		if(h[i] != -1) f[h[i]] ++;
	}
	L(i, 1, n) (ns += a[f[i]]) %= mod;
	ns = (mod + a[n - 1] - ns) % mod;
	cout << ns << "\n";
	return 0;
}
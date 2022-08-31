#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e5 + 7, mod = 1019260817, G = 19491001, iG = 972668243;
int n, m, k, f[N], Pw[N], iPw[N];
char s[N], t[N];
int hs[N], ht[N];
int gets(int l, int r) { return (ll) (hs[r] - hs[l - 1] + mod) % mod * iPw[l] % mod; }
int gett(int l, int r) { return (ll) (ht[r] - ht[l - 1] + mod) % mod * iPw[l] % mod; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> (s + 1) >> m >> (t + 1) >> k;
	Pw[0] = iPw[0] = 1;
	L(i, 1, max(n, m)) Pw[i] = (ll) Pw[i - 1] * G % mod, iPw[i] = (ll) iPw[i - 1] * iG % mod;
	L(i, 1, n) hs[i] = (hs[i - 1] + (ll) Pw[i] * s[i] % mod) % mod;
	L(i, 1, m) ht[i] = (ht[i - 1] + (ll) Pw[i] * t[i] % mod) % mod;
	L(test, 1, k) {
		R(i, n - 1, 0) {
			int l = 1, r = min(n - i, m - f[i]), ns = 0;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(gets(i + 1, i + mid) == gett(f[i] + 1, f[i] + mid)) ns = mid, l = mid + 1;
				else r = mid - 1;
			}
			if(ns > 0) f[i + ns] = max(f[i + ns], f[i] + ns);
		}
		L(i, 1, n) f[i] = max(f[i], f[i - 1]);
//		L(i, 1, n) cout << f[i] << " ";
//		cout << "\n";
	}
	if(f[n] < m) cout << "NO\n";
	else cout << "YES\n"; 
	return 0;
}
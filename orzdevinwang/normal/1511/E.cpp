#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 3e5 + 7, mod = 998244353;
int n, m, ns, pw[N], all;
int f[N]; 
string s[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 0, n - 1) cin >> s[i];
	L(i, 0, n - 1) L(j, 0, m - 1) all += (s[i][j] == 'o');
	pw[0] = 1;
	L(i, 1, n * m + 1) pw[i] = (ll) pw[i - 1] * 2 % mod;
	int s1 = 0, s2 = 1;
	f[2] = 1;
	L(i, 3, n * m + 1) {
		f[i] = (ll) f[i - 1] * 2 % mod;	
		if(i & 1) (s1 += pw[i - 3]) %= mod, (f[i] += s1) %= mod;
		else (s2 += pw[i - 3]) %= mod, (f[i] += s2) %= mod;
		// L(j, 1, (i - 1) / 2) (f[i] += pw[i - j * 2 - 1]) %= mod;
	}
	L(i, 0, n - 1) {
		int cnt = 0;
		L(j, 0, m - 1) {
			if(s[i][j] == 'o') ++cnt;
			else (ns += (ll) f[cnt] * pw[all - cnt] % mod) %= mod, cnt = 0;
		}
		(ns += (ll) f[cnt] * pw[all - cnt] % mod) %= mod;
	}
	L(j, 0, m - 1) {
		int cnt = 0;
		L(i, 0, n - 1) {
			if(s[i][j] == 'o') ++cnt;
			else (ns += (ll) f[cnt] * pw[all - cnt] % mod) %= mod, cnt = 0;
		}
		(ns += (ll) f[cnt] * pw[all - cnt] % mod) %= mod;
	}
	cout << ns << "\n";
	return 0;
} 
// To Cheat, To attack!
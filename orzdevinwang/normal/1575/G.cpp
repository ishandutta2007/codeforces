#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int n, m, a[N];
const int MAXN = 1e5;
int p[N], tot, phi[N], cnt[N];
vi fac[N];
bool Prime[N];
void xxs() {
	phi[1] = 1;
	for(int i = 2; i <= MAXN; i++) {
		if(!Prime[i]) p[++tot] = i, phi[i] = i - 1;
		for(int j = 1; p[j] * i <= MAXN && j <= tot; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) {
				phi[p[j] * i] = phi[i] * p[j];
				break;
			} 
			phi[p[j] * i] = phi[i] * (p[j] - 1);
		}
	}
	L(i, 1, MAXN) L(j, 1, MAXN / i) 
		fac[i * j].push_back(i);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int ns = 0;
	cin >> n;
	xxs ();
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		int ret = 0;
		for (int x = i; x <= n; x += i) 
			for (const int &z : fac[a[x]]) 
				(ret += (ll) (cnt[z] * 2 + 1) * phi[z] % mod) %= mod, cnt[z] += 1;
		for (int x = i; x <= n; x += i) 
			for (const int &z : fac[a[x]]) 
				cnt[z] -= 1;
		(ns += (ll) ret * phi[i] % mod) %= mod;
	}
	cout << ns << "\n";
	
	return 0;
}
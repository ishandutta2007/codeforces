#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 22, B = 6, M = 998244353, mod = 1e9 + 7;
ll n, pw[N], tp, ns; // pow10 ()
int ext (ll x) {
	int len = 0;
	while (x * pw[len + 1] <= n) ++len;
	return len;
}
struct Work {
	int B;
	vi K[10], R[10], F[10];
	int top;
	void Prework (ll now, int d) {
		++top;
		K[d].push_back(top); // top > now
		R[d].push_back(now);
		F[d].push_back(now - top);
		if(d == B) return ;
		L(i, 0, 9) 
			Prework (now * 10 + i, d + 1);
	}
	void solve () {
		Prework (0, 0);
		L(i, 0, B) sort (F[i].begin(), F[i].end());
	}
} f[10];
int cnt = 0;
void divide (ll now) {
	int len = ext (now);
	if((now + 1) * pw[len] <= n + 1 && len <= B) {
		L(i, 0, len) if(!(now * pw[i] % M + pw[i + 1] < M && tp % M + pw[i + 1] < M)) 
			goto hehezhou;
		L (i, 0, len) {
			ll Nw = now * pw[i] % M, d = tp % M;
			ns += f[len].F[i].end() - upper_bound (f[len].F[i].begin(), f[len].F[i].end(), d - Nw);
		}
		tp += f[len].top;
		return ;
	} 
	hehezhou:;
	++tp;
	ns += tp % M < now % M;
	L(i, 0, 9) if(now * 10 + i <= n) divide (now * 10 + i);	
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	if(n <= 9) return cout << 0 << '\n', 0;
	L(i, 0, B) f[i].B = i, f[i].solve();
	pw[0] = 1;
	L(i, 1, 13) pw[i] = pw[i - 1] * 10;
	L(i, 1, 9) divide (i);
	ns %= mod, cout << (ll) ns * M % mod << '\n';
	return 0;
}
/*
100000000000
440013819
*/
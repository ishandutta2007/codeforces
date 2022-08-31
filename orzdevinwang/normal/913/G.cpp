#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
#define A __int128
using namespace std;
const ll mod = 1e18, X = 1e7;
ll qpow (ll x, ll y) {
	ll ret = 1;
	for (; y; x = (A) x * x % mod, y >>= 1) if(y & 1) ret = (A) x * ret % mod;
	return ret;
}
ll Pw (ll y) {
	return qpow (2, y);
}
ll cyc[20], pw[20], r;
vector < ll > ok[20];
void Main () {
	cin >> r;
//	r = 100;
	r *= X;
	r += (1 << 18) - r % (1 << 18);
	while (r % 5 == 0) r += (1 << 18) - r % (1 << 18);
	L(i, 0, 18) ok[i].clear ();
	ok[0].push_back(0);
	L(i, 1, 18) {
		for (const ll &u : ok[i - 1]) 
			for (ll x = u; x < cyc[i]; x += cyc[i - 1]) 
				if(Pw (x) % pw[i] == r % pw[i]) 
					ok[i].push_back(x);
		int S = min(sz(ok[i]), 1);
		ok[i].resize(S);
	}
	cout << ok[18][0] << '\n';
}
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int T ;
	cin >> T;
	cyc[0] = 1, cyc[1] = 8;
	L(i, 2, 18) cyc[i] = cyc[i - 1] * 10;
	pw[0] = 1;
	L(i, 1, 18) pw[i] = pw[i - 1] * 10;
	while (T--) Main ();
	return 0;
}
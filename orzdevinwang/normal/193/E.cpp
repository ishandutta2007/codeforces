#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const ll mod = 1e13;
struct mat {
	ll v[2][2];
	mat (int x = 0) {
		L(i, 0, 1) L(j, 0, 1) v[i][j] = x * (i == j);
	}
} fi;
mat operator * (mat a, mat b) {
	mat ret (0);
	L(i, 0, 1) 
		L(j, 0, 1) 
			L(k, 0, 1) 
				(ret.v[i][j] += (__int128) a.v[i][k] * b.v[k][j] % mod) %= mod;
	return ret;
}
mat operator ^ (mat x, ll y) {
	mat ret (1);
	for (; y; x = x * x, y >>= 1) if(y & 1) ret = ret * x;
	return ret;
}
ll fibo (ll x) {
	return (fi ^ x).v[1][0];
}
ll cyc[20], pw[20], r;
vector < ll > ok[20];
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> r;
	fi.v[1][0] = 1, fi.v[1][1] = 1, fi.v[0][1] = 1;
	cyc[0] = 1, cyc[1] = 60, cyc[2] = 300, cyc[3] = 1500;
	L(i, 4, 13) cyc[i] = cyc[i - 1] * 10;
	pw[0] = 1;
	L(i, 1, 13) pw[i] = pw[i - 1] * 10;
	ok[0].push_back(0);
	L(i, 1, 13) 
		for (const ll &u : ok[i - 1]) 
			for (ll x = u; x < cyc[i]; x += cyc[i - 1]) 
				if(fibo(x) % pw[i] == r % pw[i]) 
					ok[i].push_back(x);
	sort(ok[13].begin(), ok[13].end());
	if(sz(ok[13])) cout << ok[13][0] << '\n';
	else cout << -1 << '\n';
	return 0;
}
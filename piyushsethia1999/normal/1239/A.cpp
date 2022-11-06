#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long 
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int fib[100005];
const int mod = 1e9 + 7;
void pre() {
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 100005; ++i) 
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	pre();
	int u; cin >> u;
	int v; cin >> v;
	cout << (2 * ((fib[u] + fib[v] - 1) % mod) % mod + mod) % mod;
}
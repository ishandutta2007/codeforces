#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int powm(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int mod = 1e9 + 7;
	int A; cin >> A;
	int B; cin >> B;
	int n; cin >> n;
	int x; cin >> x;
	if (A == 1) {
		cout << (x + ((n % mod) * B) % mod) % mod;
		return 0;
	} 
	int An = powm(A, n % (mod - 1), mod);
	int A_1 = powm(A - 1, mod - 2, mod);
	int re = An * x % mod + B * (((An - 1) % mod) * (A_1) % mod) % mod;
	cout << (re % mod + mod) % mod;
}
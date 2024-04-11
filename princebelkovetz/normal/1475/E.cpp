#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int N = 1e3 + 3, mod = 1e9 + 7;
int fact[N], mfact[N];
int binpow(int a, int b){
    if (!b) return 1ll;
    if (b % 2) return (a * binpow(a, b - 1)) % mod;
    int t = binpow(a, b / 2);
    return t * t % mod;
}
int getc(int k, int n){
    int res = fact[n];
    res = (res * mfact[k]) % mod;
    res = (res * mfact[n - k]) % mod;
    return res;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	fact[0] = 1;
	for (int i = 0; i < N; ++i){
	    if (i) fact[i] = (fact[i - 1] * i) % mod;
	    mfact[i] = binpow(fact[i], mod - 2);
	}
	int tt; cin >> tt;
	while (tt --> 0){
	    int n, k; cin >> n >> k;
	    vector <int> a(n);
	    for (auto &x: a) cin >> x;
	    sort(a.rbegin(), a.rend());
	    int id = k - 1;
	    while (id >= 0 and a[id] == a[k - 1]){
	        --id;
	    }
	    id++;
	    int all = k - id;
	    int cnt = 0;
	    for (auto &x: a) {
	        if (x == a[k - 1]) cnt++;
	    }
	    cout << getc(all, cnt) << '\n';
	    
	}
	return 0;
}
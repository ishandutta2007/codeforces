#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
const int P = 1e9 + 7;
const int N = 1000015;
typedef long long ll;

ll Pow(ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b & 1) r = r * a % P;
		a = a * a % P, b >>= 1;
	}
	return r;
}

ll t, fac[N], ifac[N], cur[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    fac[0] = 1; ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % P; 
        ifac[i] = Pow(fac[i], P - 2);
    }
    for (cin >> t; t; t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int j = 0; j <= n; j++)
     		cur[j] = fac[n] * ifac[j] % P * ifac[n - j] % P;
   		for (int j = 1; j <= n; j++)
   	    	cur[j] = (cur[j] + cur[j - 1]) % P;
    	for (int j = 1; j <= n; j++)
        	cur[j] = (cur[j] + cur[j - 1]) % P;  
    	ll ans = cur[m - 1] * Pow((P + 1) / 2, n - 1) % P;
        cout << (ans * k) % P << endl;
    }
    return 0;
}
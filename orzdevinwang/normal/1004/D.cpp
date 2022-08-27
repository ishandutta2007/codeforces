#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define ll long long
using namespace std;
const int N = 1e6 + 7, mod = 1019260817, G = 19491001;
int n, a[N], sum[N], pw[N], xl, mx;
int main() {
	cin >> n, sum[0] = pw[0] = 1;
	L(i, 1, n) pw[i] = (ll) pw[i - 1] * G % mod, sum[i] = (sum[i - 1] + pw[i]) % mod;
	L(i, 1, n) cin >> a[i], (xl += pw[a[i]]) %= mod, mx = max(mx, a[i]);
	L(i, 1, n) if(n % i == 0) L(k, max(1, mx + 2 - n / i), mx + 1) if((ll) (sum[k - 1] + sum[i - k] - 1) * (sum[mx + 1 - k] + sum[n / i - mx - 2 + k] - 1) % mod == xl) cout << i << " " << n / i << "\n" << k << " " << mx + 2 - k << "\n", exit(0);
	cout << "-1\n";
	return 0;
}
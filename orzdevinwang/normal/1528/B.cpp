#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, d[N], f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) L(j, 1, n / i) d[i * j]++;
	f[0] = 1; 
	int sum = 0;
	L(i, 1, n) f[i] = (d[i] + sum) % mod, (sum += f[i]) %= mod;
	cout << f[n] << "\n";
	return 0;
}
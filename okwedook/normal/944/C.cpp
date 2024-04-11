#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <cmath>

#define elif else if

using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf = 1e18 + 3, mod = 1e9 + 7;

istream& operator>>(istream& is, vector<ll> &a) {
	for (int i = 0; i < a.size(); ++i) cin >> a[i];
	return is;
}

ostream& operator<<(ostream& os, vector<ll> &a) {
	for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
	return os;
}

void sort(vector<ll> &a) {
	sort(a.begin(), a.end());
}

ll step(ll a, ll n) {
	if (n == 1) return a % mod;
	if (n & 1) return (step(a, n - 1) * a) % mod;
	ll k = step(a, n / 2);
	return (k * k) % mod;
}

ll gcd(ll a, ll b) {
	return a > 0 ? gcd(b % a, a) : b;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	vector<ll> depth(n, 0);
	ll ans = 0;
	for (int i = 1; i < n; ++i) cin >> arr[i];
	for (int i = 1; i < n; ++i) depth[i] = depth[arr[i] - 1] + 1;
	vector<bool> mod2(n);
	for (int i = 0; i < n; ++i) 
		mod2[depth[i]] = !mod2[depth[i]];
	for (int i = 0; i < n; ++i) ans += mod2[i];
	cout << ans;
	//system("pause");
	return 0;
}

/*int main() {
	ll n;
	vector<ll> arr(n);
	cin >> arr;
	sort(arr);
	int k = arr[0];
	int countk = 0, countk1 = 0, countk2 = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == k) ++countk;
		elif (arr[i] == k + 1) ++countk1;
		else ++countk2;
	}

	return 0;
}*/
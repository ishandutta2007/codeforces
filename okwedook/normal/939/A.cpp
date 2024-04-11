#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
	return a > 0 ? gcd(b % a, a) : b;
}

int main() {
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i, --i;
	for (int i = 0; i < n; ++i) 
		if (arr[arr[arr[i]]] == i) {
			cout << "YES";
			return 0;
		}
	cout << "NO";
    return 0;
}
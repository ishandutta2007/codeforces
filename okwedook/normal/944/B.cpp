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
	cin >> arr;
	sort(arr);
	int k = arr[0];
	int countk = 0, countk1 = 0, countk2 = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == k) ++countk;
		elif (arr[i] == k + 1) ++countk1;
		else ++countk2;
	}
	if (countk2 == 0) {
		cout << n << '\n';
		cout << arr;
		return 0;
	}
	if (countk < countk2) {
		if (countk2 + countk + countk1 % 2 < countk1 + countk2 - countk) {
			cout << countk + countk2 + countk1 % 2 << '\n';
			if (countk1 % 2 == 0) {
				countk1 /= 2;
				for (int i = 0; i < countk + countk1; ++i) cout << k << ' ';
				for (int i = countk + countk1; i < n; ++i) cout << k + 2 << ' ';
			} else {
				countk1 /= 2;
				for (int i = 0; i < countk + countk1; ++i) cout << k << ' ';
				cout << k + 1 << ' '; 
				for (int i = countk + countk1 + 1; i < n; ++i) cout << k + 2 << ' ';
			}
		}
		else {
			cout << countk1 + countk2 - countk << '\n';
			countk2 -= countk;
			for (int i = 0; i < countk2; ++i) cout << k + 2 << ' ';
			for (int i = countk2; i < n; ++i) cout << k + 1 << ' ';
		}
	} else {
		if (countk2 + countk + countk1 % 2 < countk1 + countk - countk2) {
			cout << countk + countk2 + countk1 % 2 << '\n';
			if (countk1 % 2 == 0) {
				countk1 /= 2;
				for (int i = 0; i < countk + countk1; ++i) cout << k << ' ';
				for (int i = countk + countk1; i < n; ++i) cout << k + 2 << ' ';
			} else {
				countk1 /= 2;
				for (int i = 0; i < countk + countk1; ++i) cout << k << ' ';
				cout << k + 1 << ' '; 
				for (int i = countk + countk1 + 1; i < n; ++i) cout << k + 2 << ' ';
			}
		}
		else {
			cout << countk1 + countk - countk2 << '\n';
			countk -= countk2;
			for (int i = 0; i < countk; ++i) cout << k << ' ';
			for (int i = countk; i < n; ++i) cout << k + 1 << ' ';
		}
	}
	//system("pause");
	return 0;
}
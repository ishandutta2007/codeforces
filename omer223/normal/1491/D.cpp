#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <intrin.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 30;

bool isvalid(int i, int k) {
	if (i > k)return 0;
	if (__builtin_popcount(i) < __builtin_popcount(k))return 0;
	int smi = 0, smk = 0;
	for (int j = 0; j < sz; j++) {
		smi += ((i >> j) & 1);
		smk += ((k >> j) & 1);
		if (smi < smk)return 0;
	}
	return 1;
}

int main() {
	fast;
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << (isvalid(x, y) ? "YES\n" : "NO\n");
	}
	return 0;
}
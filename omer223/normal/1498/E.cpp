#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool ask(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	fflush(stdout);
	string ans;
	cin >> ans;
	fflush(stdout);
	return (ans == "Yes");
}

const int sz = 5e3 + 5;
int n, k[sz];

int main() {
	fast;
	vector<pair<int, pii>> v;
	cin >> n;
	foru(i, 0, n)
		cin >> k[i];
	foru(i, 0, n) {
		foru(j, i + 1, n) {
			v.pb({ abs(k[i] - k[j]), {i ,j} });
		}
	}
	sort(v.rbegin(), v.rend());
	for (auto ii : v) {
		int i = ii.second.first, j = ii.second.second;
		if (k[i] < k[j])
			swap(i, j);
		i++; j++;
		if (ask(i, j)) {
			cout << "! " << i << ' ' << j << endl;
			fflush(stdout);
			return 0;
		}
	}
	cout << "! 0 0" << endl;
	fflush(stdout);
	return 0;
}
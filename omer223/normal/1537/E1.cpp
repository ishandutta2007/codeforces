
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;




int main() {
	fast;
	int n, k;
	string s;
	cin >> n >> k >> s;
	string bst = "";
	while (bst.length() < k)bst.push_back(s[0]);
	for (int i = 2; i <= n; i++) {
		string tmp = "";
		for (int j = 0; j < k; j++) tmp.push_back(s[j % i]);
		if (tmp < bst)bst = tmp;
	}
	cout << bst << '\n';
	return 0;
}
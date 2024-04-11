#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {
	fast;
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n);
	foru(i, 0, n) {
		cin >> a[i];
	}
	int cnt = 0;
	foru(i, 1, n-1) {
		if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))cnt++;
	}
	cout << cnt;
	return 0;
}